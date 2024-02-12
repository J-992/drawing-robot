var w=7;
var h=7;

var s=0.15;
var r=0.0075;
function bruh(x,y) {
    var z=(1-(y+1)/2)*0.009;
    x=x*s+0.5+rand(-z,+z);
    y=y*s+0.5+rand(-z,+z);
    rect(x-r,y-r,x+r,y+r);
}

for (var y=-h;y<=h;y++) {
for (var x=-w;x<=w;x++) {
    bruh(x/w,y/h);
}
}