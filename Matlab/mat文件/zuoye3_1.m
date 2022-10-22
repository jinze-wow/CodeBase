x=0:2*pi/100:2*pi;
y=(0.5+3.*sin(x)./(1+x.^2)).*cos(x);
plot(x,y)
