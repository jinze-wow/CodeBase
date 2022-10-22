clear;
f(1)=1;
f(2)=0;
f(3)=1;
for n=4:100
f(n)=f(n-1)-2*f(n-2)+f(n-3);
end
[MAX,x]=max(f) 
[MIN,y]=min(f)
SUM=sum(f)
zhengshu=length(find(f>0))
zero=length(find(f==0))
fushu=length(find(f<0))
