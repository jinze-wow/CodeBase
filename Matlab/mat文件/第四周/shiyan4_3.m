a=input('请输入成绩:');
if a>=90 & a<=100
disp('A');
elseif a>=80 & a<90
disp('B');
elseif a>=70 & a<80
disp('C');
elseif a>=60 & a<70
disp('D');
elseif a<60 &a>=O
disp('E');
else
disp('输入有误! ');
end
a=input('请输入成绩:');
switch fix(a/10)
case {9}
disp('A');
case {8}
disp('B');
case{7}
disp('C');
case {6}
disp('D');
case num2cell(2:5)
disp('E')
otherwise
disp('输入有误! ');
end
