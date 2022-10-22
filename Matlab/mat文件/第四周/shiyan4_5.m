a=input ('请输入第一个数:');
b=input ( '请输入第二个数:') ;
c=input('输入运算符','s');
if c=='+'
s=a+b;
elseif c== '-'
s=a-b;
elseif c=='*'
s=a*b;
elseif c=='/'
s=a/b;
else
disp ( ' error! ');
end
disp(s) ;
