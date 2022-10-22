c = input('请输入一个字符','s');
if c >='A' & c<='Z'
    disp(char(abs(c) + abs('a')-abs('A')));
elseif c>='a' & c<='z'
    disp(char(abs(c)- abs('a') + abs('A')));
elseif c>='0' & c<='9'
    disp(abs(c)-abs('0'));
else
    disp(c);
end
