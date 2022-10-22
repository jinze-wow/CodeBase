str1 = 'today';  
str2 = 'tomorrow';  
str3 = 'today';  
out1 = strcmp(str1, str2)	  % 比较字符串 str1 和 str2 
out1 = 0    ;                            %表示字符串 str1 和 str2不同
out2 = strcmp(str1, str3)	   % 比较字符串 str1 和 str3
out2 = 1      ;                          