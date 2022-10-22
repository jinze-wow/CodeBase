x=linspace(1,101,10);
y=log(x)/log(10);
p=polyfit(x,y,5)
y1=polyval(p,x)
plot(x,y,':o',x,y1,'-*')
legend('sin(x)','fit')
