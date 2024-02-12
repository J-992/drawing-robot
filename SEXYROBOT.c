/*

SEXYROBOT.c
July 18 2023

Adam Sidat
Samantha Chan
Ben Jabal
Jaffer Razavi

EV3 pen plotting robot code. Please use in conjunction with one of the header
files in HEADERS. See WEBSITES for simple tools that can be used to generate
such headers.

*/

// Constant name for the pen motor.
const int PEN_MOTOR = motorC;
// The speed and amount of time the pen motor should be driven at/for in order
// for it to alternate between fully up or fully down. Negative direction is
// up, and positive direction is down.
const int PEN_MOTOR_SPEED = 100;
const int PEN_MOTOR_SLEEP = 150; // ms

// Constant names for the X and Y motors. Turning these motors in the positive
// direction will move them *away* from home. Turning these motors in the
// negative direction will move them *towards* home.
const int X_MOTOR = motorD;
const int Y_MOTOR = motorA;
// HOME_SPEED is the speed at which the machine should be homed. This should be
// a relatively slow speed since our whole machine operates relative to the
// home position, and a slow speed will get us an accurate home positioning.
const int HOME_SPEED = 100;

// Constant names for the X and Y touch sensors.
const int X_SENSOR = S1;
const int Y_SENSOR = S2;

// Empirically found by slowly turning the motor until it hits the edge and
// recording the encoder value at the time of collision. There are no constants
// for X_MIN_ENCODER and Y_MIN_ENCODER, as they are just 0.0. The reasoning for
// this is that the motor encoders are reset when the machine is homed (and the
// home position is clearly the minimum position).
const float X_MAX = 2125.0;
const float Y_MAX = 2125.0;

// Constant speeds. MOVE_SPEED is for when the pen is down, so it should not be
// very fast (or the lines will be shaky). RAPID_SPEED is for when the pen is
// up, so it can be faster.
const int MOVE_SPEED = 25;
const int RAPID_SPEED = 100;
// This is the threshold that the motor will slow down when nearing. Basically,
// when the motor encoder value is within SLOW_THRESHOLD of a desired value,
// an algorithm will kick in which slows down the motor linearly to half of the
// normal speed, causing it to move very precisely near the end.
const float SLOW_THRESHOLD = 100.0;

// How accurate our positioning should be. If a motor encoder is within +/-
// RESOLUTION of a desired value, we will say that it is equal to that value. A
// lower value is more accurate.
const float RESOLUTION = 10.0;

// The maximum number of points.
const int MAX_POINTS = 1500;

// Returns the maximum of two values.
int imax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

float fmax(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

// Returns the minumum of two values.
float fmin(float a, float b)
{
	if (a < b)
		return a;
	else
		return b;
}

// Helper function, will clamp a value between min and max.
float clamp(float x, float min, float max)
{
	if (x < min)
		return min;
	else if (x > max)
		return max;
	else
		return x;
}

// Initialize all sensors.
void init_sensors()
{
	// Set up X touch sensor.
	SensorType[X_SENSOR] = sensorEV3_Touch;
	wait1Msec(100);
	// Set up Y touch sensor.
	SensorType[Y_SENSOR] = sensorEV3_Touch;
	wait1Msec(100);
}

// Move the pen all the way up. non-trivial
void pen_up()
{
	setMotorSpeed(PEN_MOTOR, -PEN_MOTOR_SPEED);
	sleep(PEN_MOTOR_SLEEP);
	setMotorSpeed(PEN_MOTOR, 0);
}

// Move the pen all the way down.
void pen_down()
{
	setMotorSpeed(PEN_MOTOR, PEN_MOTOR_SPEED);
	sleep(PEN_MOTOR_SLEEP);
	setMotorSpeed(PEN_MOTOR, 0);
}

// // Home each axis individually (this will reset both encoders).
// void home_individually()
// {
// 	displayString(1, "Status: Homing...");

// 	setMotorSpeed(X_MOTOR, -HOME_SPEED);
// 	while (!getTouchValue(X_SENSOR)) {}
// 	setMotorSpeed(X_MOTOR, 0);

// 	setMotorSpeed(Y_MOTOR, -HOME_SPEED);
// 	while (!getTouchValue(Y_SENSOR)) {}
// 	setMotorSpeed(Y_MOTOR, 0);

// 	resetMotorEncoder(X_MOTOR);
// 	resetMotorEncoder(Y_MOTOR);

// 	displayString(1, "Status: Done Homing.");
// }

void home_simultaneously()
{
	displayString(1, "Status: Homing...");

	bool x_homed = false;
	bool y_homed = false;

	// We go in the negative direction because we want to approach (0,0).
	setMotorSpeed(X_MOTOR, -HOME_SPEED);
	setMotorSpeed(Y_MOTOR, -HOME_SPEED);

	// Keep going until both axes are homed...
	while (!x_homed || !y_homed)
	{
		// Check whether or not each axis is homed.
		x_homed = getTouchValue(X_SENSOR);
		y_homed = getTouchValue(Y_SENSOR);

		// If either axis is homed, turn off it's corresponding motor.
		if (x_homed)
			setMotorSpeed(X_MOTOR, 0);
		if (y_homed)
			setMotorSpeed(Y_MOTOR, 0);
	}

	// The home position is the motor encoder's zero.
	resetMotorEncoder(X_MOTOR);
	resetMotorEncoder(Y_MOTOR);

	displayString(1, "Status: Done Homing.");
}

// Returns true if we are already at the specified position (x,y), where (0,0)
// is the home position and (1,1) is the maximum position.
bool at_position(float x, float y)
{
	// Make sure that 0 <= x,y <= 1.
	x = clamp(x, 0.0, 1.0);
	y = clamp(y, 0.0, 1.0);

	// Convert these positions to encoder ticks.
	x *= X_MAX;
	y *= Y_MAX;

	// Both encoders should be within RESOLUTION ticks of the desired position.
	return abs(getMotorEncoder(X_MOTOR) - x) < RESOLUTION &&
	       abs(getMotorEncoder(Y_MOTOR) - y) < RESOLUTION;
}

// Moves to the position specified by x and y, where (0,0) is the home position
// and (1,1) is the maximum position.
void move_to(float x, float y, int speed = MOVE_SPEED)
{
	// displayString(1, "Status: Moving to %f %f", x, y);

	// Make sure that 0 <= x,y <= 1.
	x = clamp(x, 0.0, 1.0);
	y = clamp(y, 0.0, 1.0);

	// Convert these positions to encoder ticks.
	x *= X_MAX;
	y *= Y_MAX;

	// See where we currently are.
	float start_x = getMotorEncoder(X_MOTOR);
	float start_y = getMotorEncoder(Y_MOTOR);

	// Figure out how far we have to move.
	float delta_x = abs(x - start_x);
	float delta_y = abs(y - start_y);

	// Now figure out the proportionality between the speeds of the two motors.
	// The problem here is that you can't move both motors at the same speed, or
	// one of them will reach the destination before the other one. This is
	// problematic because this won't work for any line besides a horizontal,
	// vertical, or diagonal line. So my solution is to set one motor to move at
	// the max rate, and then the other motor move at a fraction of that rate. The
	// motor that moves at the max rate will be the one corresponding to the axis
	// that has to move the most. This will minimize the travel time.
	float x_speed_scalar, y_speed_scalar;
	if (delta_x > delta_y)
	{
		x_speed_scalar = 1.0;
		y_speed_scalar = delta_y / delta_x; //    delta_y<=delta_x
		                                    // => 0<=y_speed_scalar<=1
	}
	else
	{
		y_speed_scalar = 1.0;
		x_speed_scalar = delta_x / delta_y;
	}

	// Keep going until we reach the desired position.
	bool reached_x = false;
	bool reached_y = false;
	while (!reached_x || !reached_y)
	{
		// NOTE: The reason why getMotorEncoder(...) is queried so many times during
		// this loop rather than querying it once and storing it, is because the
		// value of the motor encoder can change between instructions. It's kind of
		// like getMotorEncoder(...) is a getter for a variable marked as volatile,
		// so we can't do those kinds of optimizations here.

		if (reached_x)
		{
			// We've already reached the right X, so turn the motor off.
			setMotorSpeed(X_MOTOR, 0);
		}
		else
		{
			// Calculate the sign, i.e., which direction the motor should turn.
			float sign = getMotorEncoder(X_MOTOR) < x ? 1.0 : -1.0;
			float linear_slow = 1.0;//clamp(abs(getMotorEncoder(Y_MOTOR) - y) / SLOW_THRESHOLD, 0.25, 1.0);

			// Calculate the total speed by combining everything we calculated.
			// We clamp this value between 1 and 100 so that we never try to
			// make the motor move at an impossibly fast speed, and also so
			// the speed can never be < 1 (it would halt forever if we let it).
			float total_speed = sign * clamp(speed * linear_slow * x_speed_scalar, 1, 100);
			setMotorSpeed(X_MOTOR, total_speed);

			// Check if we reached the right X value yet!
			reached_x = abs(getMotorEncoder(X_MOTOR) - x) < RESOLUTION;
		}

		// Same as above, but for Y. This is a hot loop, so I didn't put this
		// in a function. I could have, but I don't trust the RobotC compiler.
		if (reached_y)
		{
			setMotorSpeed(Y_MOTOR, 0);
		}
		else
		{
			float sign = getMotorEncoder(Y_MOTOR) < y ? 1.0 : -1.0;
			float linear_slow = 1.0;//clamp(abs(getMotorEncoder(Y_MOTOR) - y) / SLOW_THRESHOLD, 0.25, 1.0);
			float total_speed = sign * clamp(speed * linear_slow * y_speed_scalar, 1, 100);
			setMotorSpeed(Y_MOTOR, total_speed);
			reached_y = abs(getMotorEncoder(Y_MOTOR) - y) < RESOLUTION;
		}
	}

	// We might have a little bit of speed, so clear it.
	setMotorSpeed(X_MOTOR, 0);
	setMotorSpeed(Y_MOTOR, 0);
}

// Rapids to the position specified by x and y. I don't know if the RobotC
// compiler is good enough to inline this, so I made it a #define.
#define rapid_to(x, y) move_to(x, y, RAPID_SPEED)

// Global variables which store all the positions we need to go to, and the
// number of positions. Each pair of points (e.g., (x[0],y[0]) and
// (x[1],y[1])) are treated as a line segment, and a line will be drawn
// between them.
float x[MAX_POINTS];
float y[MAX_POINTS];
int num_points = 0;

// Generate a line.
void line(float x0, float y0, float x1, float y1)
{
	// Simply adds a line on by adding two points to the arrays.
	x[num_points] = x0;
	y[num_points++] = y0;
	x[num_points] = x1;
	y[num_points++] = y1;
}

// Generate a circle.
void circle(float x, float y, float r)
{
	// There's some code in here that measures the circumference of a circle
	// with radius r, and uses that value to determine how many line segments
	// should be used to accurately draw it, controlled by the two constants.
	const int MIN_CIRCLE_SEGMENTS = 25;
	const float LENGTH_PER_SEGMENT = 0.025;
	float circumference = 2.0 * PI * r;
	int n = imax(ceil(circumference / LENGTH_PER_SEGMENT), MIN_CIRCLE_SEGMENTS);
	for (int i = 0; i < n; i++)
	{
		float angle0 = (float)i / (float)n * (2.0 * PI);
		float angle1 = (float)(i + 1) / (float)n * (2.0 * PI);
		line(x + cos(angle0) * r, y + sin(angle0) * r,
		     x + cos(angle1) * r, y + sin(angle1) * r);
	}
}

// Load all the data.
void load_data()
{
// To explain what #include does, it literally just pastes in the file you
// specify directly into the source code. The files we generate are a big list
// of commands like line() or circle(). Then when you call load_data(), it
// calls all those functions, populating the arrays.
circle(0.500000000,0.500000000,0.550000000);
}

// Draw everything!
void draw()
{
	// We can only draw line segments (implies # points is positive & even).
	if (num_points < 2 || num_points % 2 != 0)
		return;

	// Store the pen state.
	pen_up();
	bool is_pen_down = false;

	// Iterate over all the points, except the last one.
	for (int i = 0; i < num_points - 1; i += 2)
	{
		displayString(1, "Status: %d%% complete...", (int)((float)i / (float)(num_points-2) * 100.0));

		// Check if we're already at the first endpoint (possibly could have two
		// subsequent line segments where the second endpoint of the first line is
		// equal to the first endpoint of the second line). If so, we don't need to
		// to move anywhere at all.
		if (!at_position(x[i], y[i]))
		{
			// Pick the pen up.
			if (is_pen_down)
			{
				pen_up();
				is_pen_down = false;
			}

			// Rapid to the first endpoint.
			rapid_to(x[i], y[i]);
		}

		// Put the pen down.
		if (!is_pen_down)
		{
			pen_down();
			is_pen_down = true;
		}

		// Move to the second endpoint.
		move_to(x[i+1], y[i+1]);
	}

	pen_up();
}

// Go to a corner.
// go_to_corner(1,1) goes to top-right,
// go_to_corner(0,0) goes to bottom-left (home), etc.
void go_to_corner(bool go_to_x_max, bool go_to_y_max)
{
	// It's just a fancier version of this pattern:
	//     x_min=big value
	//     for each x if x<x_min x_min=x
	// Except that it works for min OR max on both coordinates separately
	// using just one loop. It's not the fastest way to do it, as we are
	// branching within the loop rather than outside, but it is consice, so I
	// like it.
	float x0 = go_to_x_max ? 0.0 : 1.0;
	float y0 = go_to_y_max ? 0.0 : 1.0;

	for (int i = 0; i < num_points; i++)
	{
		x0 = go_to_x_max ? fmax(x[i], x0) : fmin(x[i], x0);
		y0 = go_to_y_max ? fmax(y[i], y0) : fmin(y[i], y0);
	}

	rapid_to(x0, y0);
}

// Play a funny tone.
void jingle1()
{
	for (int i = 0; i < 5; i++)
	{
		playTone(500*(i+1), 10);
		sleep(100);
	}
}

// Play a funnier tone.
void jingle2()
{
	for (int i = 4; i >= 0; i--)
	{
		playTone(500*(i+1), 10);
		sleep(100);
	}
}

// The Tetris theme, TETRIS1 should be played in the 5th octave and TETRIS2
// should be played in the 4th octave.
// https://pianoletternotes.blogspot.com/2017/10/tetris-theme-by-korobeiniki.html
const char* TETRIS1 = "e-----c-d-edc---------c-e---d-c-------c-d---e---c---------------d---d-f-a---g-f-e---e-c-e---d-c-------c-";
const char* TETRIS2 = "----b---------b-a---a-----------b---bb--------------a---a---------------------------------------b---bb--";

// Play a note.
void play_note(char note, int octave, int ms) {
	// https://pages.mtu.edu/~suits/NoteFreqCalcs.html
	const float A4 = 440.0;
	const float TWELFTH_ROOT_OF_TWO = 1.059463094359;
	int n = note - 'a' + (octave - 4) * 12;
	float hz = A4 * pow(TWELFTH_ROOT_OF_TWO, n);
	playTone(hz, ms/10);
	sleep(ms);
}

// Play the Tetris theme.
void tetris() {
	// :)
	for (int i = 0; i < strlen(TETRIS1); i++) {
		char note1 = TETRIS1[i];
		char note2 = TETRIS2[i];
		if (note1 != '-')
			play_note(note1, 5, 100);
		else if (note2 != '-')
			play_note(note2, 4, 100);
	  else
	  	sleep(100);
	}
}

task main()
{
	// Set everything up.
	init_sensors();
	pen_up();
	// home_individually();
	home_simultaneously();
	load_data();
	jingle1();

	// TODO: select drawing?

	// Go to the top-left position.
	while (!getButtonPress(buttonAny)) {}
	go_to_corner(1, 1);
	displayString(1, "At top-left position.");

	// Go to the bottom-right position.
	while (!getButtonPress(buttonAny)) {}
	go_to_corner(0, 0);
	displayString(1, "At bottom-right position.");

	// Draw, then go home.
	displayString(1, "Press any button to draw!");
	while (!getButtonPress(buttonAny)) {}
	jingle2();
	draw();
	home_simultaneously();
	tetris();
	jingle1();

	// Quit.
	displayString(1, "Press any button to quit!");
	while (!getButtonPress(buttonAny)) {}
	jingle2();
}
