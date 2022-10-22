n=6:2:18;
f1=[18 20 22 25 30 28 24];
f2=[15 19 24 28 34 32 30];
r=6.5:2:17.5;
w=interp1(n,f1,r,'spline');
w1=interp1(n,f2,r,'spline');
subplot(211),plot(r,w)
subplot(212),plot(r,w1)
