A=1 : 30 ;
B=reshape (A,5,6);
n=input ( '输入n的值') ;
try
disp (B(n,: ))
catch
disp(B (5,: ))
end
lasterr
