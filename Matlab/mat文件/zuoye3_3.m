x=-5:0.1:5;
y=(x+pi^(1/2))./(exp(2)).*(x<=0)+1/2.*log(x+(1+x.^2).^(1/2)).*(x>0);
plot(x,y)
