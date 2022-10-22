t=0:pi/10000:pi;
x=sin(3*t).*cos(t);
y1=2*x-0.5;
y2=sin(3*t).*sin(t);
plot(x,y1);
hold on;
plot(x,y2);
y=y1-y2;
e=find(y>-0.0002&y<0.0002)
text(0.2616,2*0.2616-0.5,'\fontsize{16}\leftarrowsin(t)=.707 ')
text(0.5000,2*0.5000-0.5,'\fontsize{16}\leftarrowsin(t) = .707 ')
text(-0.1606,-2*0.1606-0.5,'\fontsize{16}\eftarrowsin(t)= .707 ')
text(0.1190,2*0.1190-0.5,'\fontsize{16}\leftarrowsin(t)= .707 ')
