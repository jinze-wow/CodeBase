x=[1,2,3,4,5,6,7,8,9,10];
y=[1.2,3,4,4,5,4.7,5,5.2,6,7.2];
p1 = polyfit(x,y,1);
p3 = polyfit (x,y,3);
x2=1:0.1:10;
y1=polyval(p1,x2);
y3=polyval(p3,x2);
plot( x,y, '*',x2, y1, ':',x2,y3)
