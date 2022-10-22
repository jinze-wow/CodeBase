t = [0:199]./100;      %采样时间点
% 生成信号
x = sin(2*pi*t) + sin(4*pi*t);
plot(t,x);
legend('x = sin(2*pi*t) + sin(4*pi*t)');
