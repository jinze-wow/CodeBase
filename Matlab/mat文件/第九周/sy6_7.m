I1=inline('sqrt((cos(t)).^2+4*sin(2*t).^2+1)' ,'t');
quad(I1,0,2*pi)
I2=inline('log(1+x)./(1+x.^2)', 'x');
quad(I2,0,1)
