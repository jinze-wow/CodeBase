syms x;
f1=(x*(exp(sin(x))+1)-2*(exp(tan(x))-1)) /sin(x)^3;
limit(f1, x,0)

fun=(sqrt(x)-sqrt(acos(x)))./sqrt(x+1);
limit(fun,x,1)

y=(1-cos (2*x))/x;
diff(y,x)
diff(y ,x ,2)
