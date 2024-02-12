function poly(x,y,r,n,a) {
    for (var i=0; i<n; i++) {
        var angle0=a+i/n*2*Math.PI;
        var angle1=a+(i+1)/n*2*Math.PI;
        line(x+Math.cos(angle0)*r,y+Math.sin(angle0)*r,
             x+Math.cos(angle1)*r,y+Math.sin(angle1)*r);
    }
}

var h = 0.2;
var dy = 0.075;

for (var n=3; n<=10; n++) {
    var x=-(((n-3)/7)*2-1);
    for (var y=-h; y<=+h; y+=dy) {
         poly(0.5+x*0.2,
              0.5+y,
              0.02,
              n,
              y*3);
         poly(0.5+x*0.2+0.005,
              0.5+y+0.005,
              0.02,
              n,
              y*3);
    }
}