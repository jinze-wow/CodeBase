ch='cadhhdDjs42257' ;
subch=ch(1:5) %取子字符串
revch=ch(end:-1:1) %将字符串倒排
k=find(ch>='a'&ch<='z'); %找到小写字母的位置
ch(k)=ch(k)-('a'-'A'); %将小写字母变成大写
char(ch)
length(k) %统计小写字母个数