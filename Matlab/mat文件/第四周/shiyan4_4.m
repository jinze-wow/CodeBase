n=input('请输入工号:');
a=input('请输入工作小时数: ');
if a>=120
y=a*84+a*84*0.15;
disp(y);
elseif a<120 & a>=60
y=a*84;
disp(y);
else
y=a*84-700;
disp(y);
end
