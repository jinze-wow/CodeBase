clear all
clc
x = [2007 2008 2009 2010 2011 2012 2013 2014 2015 2016 2017 2018 2019];
y = [292549 276372 283243 237248 202623 180159 146193 111187 86747 61428 39230 25413 17106];
p5 = polyfit(x,y,5);				 % 5 阶多项式拟合 
y5 = polyval(p5,x);
p5 = vpa(poly2sym(p5),5)			 %显示 5 阶多项式

figure;								%画图
plot(x,y,'bo');
hold on;
plot(x,y5,'r:');

legend('原始数据','5 阶多项式拟合');
xlabel('x');
xlabel('y');