X=sym ('x') ;
f1=1/(1+x^4+x^8);
int(f1,x)

f2=1/ ((asin(x)^2)*sqrt (1-x^2) ) ;
int(f2,x)

f3=exp(x)*((1+exp(x))^2)
int(f3,x,0,log(2))
