A=fix ( ( 99)*rand (1,20))
b=mean (A)
P=A(find (A<=b))
P=P (find(rem (P,2)==0))
