function g(x) {
    return Math.sin(x*25)*0.1;
}

var h = 0.1;
function f(x) {
    return Math.min(Math.max(g(x),-h),+h);
}

var dx = 0.01;

function graph(a,y,amp)
{
    for (var x=-0.25; x<=0.25; x+=dx) {
        line(0.5+x+a,0.5+f(x)*amp+y,0.5+x+dx+a,0.5+f(x+dx)*amp+y);
    }
}

for (var i=-0.1; i<0.1; i+=0.0125) {
    graph(i/2,i,0.5);
}