function y = sy5_4(n)
if n==1
y = 1;
elseif n==2
y = 0;
elseif n==3
y = 1;
else
a=zeros(1,n);
a(1:3)=[1,0,1];
for i = 4:n
a (i)=a(i-1)-2*a(i-2)+a(i-3) ;
end
y = a(n) ;% y=fun (n-l)一2*fun (n-2 )+fun ( n-3 ) ;
end
maxa = max (a) ;
mina = min (a) ;
suma = sum (a) ;
zero=0 ;
zhengshu=0;
fushu=0;
for i=1:n
if a (i) == 0
    zero=zero+1;
elseif a (i) >0
    zhengshu=zhengshu+1;
else
    fushu=fushu+1;
end
end
maxa
mina
suma
   zero
   zhengshu
   fushu

