var x=0.5;
var y=0.5;

var w=0.02;
for (var i=0; i<500; i++) {
    var x0=x;
    var y0=y;
    var roll=rand(0,3);
    if (roll>2)
        x+=Math.sign(rand(-1,1))*w;
    else if (roll>1)
        y+=Math.sign(rand(-1,1))*w;
    else {
        x+=Math.sign(rand(-1,1))*w;
        y+=Math.sign(rand(-1,1))*w;
    }
    line(x0,y0,x,y);
}