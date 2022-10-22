sum = 0;
n = 0;
x = input('Enter a number(end in 0):');
while(x~=0)
    sum = sum+x;
    n = n+1;
    x = input('Enter a number(end in 0):');
end
if(n>0)
    sum
    mean = sum/n
end
