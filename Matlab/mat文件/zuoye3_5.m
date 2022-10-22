x=-8:0.1:8;
y=-8:0.1:8;
[x,y]=meshgrid(x,y);
z=sin((x.^2+y.^2).^(1/2))./((x.^2+y.^2).^(1/2));
plot3(x,y,z);
mesh(x,y,z);
surf(x,y,z);
