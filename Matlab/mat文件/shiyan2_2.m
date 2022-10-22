x=0:pi/100:5*pi;
y=sin(x);
y1=(x>pi&x<2*pi);
y1=(x>pi&x<2*pi).*y ;
plot (x,y1)
y1=(x<=pi|x>=2*pi).*y ;
plot (x,y1)
y1=(x<=pi| (x>=2*pi&x<=3*pi)|x>=4*pi).*y;
plot(x,y1)
q=(x>pi/3&x<2*pi/3)|(x>7*pi/3&8*pi/3);
q1=~q;
y2=q*sin(pi/3)+q1.*y1;
plot (x,y2)
plot (x,y1)
plot (x,y2)

