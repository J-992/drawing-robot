var n=25;
for (var i=0; i<n; i++) {
    var angle=i/n*2*Math.PI;
    var x=0.5+Math.cos(angle)*0.1;
    var y=0.5+Math.sin(angle)*0.1;
    circle(x,y,i/n*0.05);
}