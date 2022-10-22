function [y]=sy5_1_2(n)
%n=100;
i=1:n;
f=1./i.^2;
y=sqrt(sum(f)*6);
