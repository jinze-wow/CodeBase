a=input('请输入一个四位整数: ');
a1=fix(a/1000) ;
a2=rem(fix(a/100) , 10) ;
a3=rem(fix(a/ 10),10);a4=rem(a,10) ;
a1=rem(a1+7,10);
a2=rem(a2+7,10);
a3=rem(a3+7,10);
a4=rem(a4+7,10);
b=a1 ; a1=a3 ; a3=b ;
b=a2 ; a2=a4 ; a4=b ;
c=a1*1000+a2*100+a3* 10+a4 ;
disp(c)

