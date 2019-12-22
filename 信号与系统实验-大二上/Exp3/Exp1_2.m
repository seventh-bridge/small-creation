clear;
clc;

num = [0.9, -0.45, 0.35, 0.002];
den = [1, 0.71, -0.46, -0.62];

t = (1: 1: 20);
delta = (t ~= 1) * 0 + (t == 1) * 1;
h = filter(num, den, delta);

x = [1, -2, 3, -4, 3, 2, 1];
y = conv(h, x);
n = 0:25;

subplot(3, 1, 1);
stem(n, y);
xlabel("ʱ����� n");
ylabel("���");
title("�þ���õ������");
grid;

x1 = [x, zeros(1,19)];
y1 = filter(h, 1, x1);

subplot(3, 1, 2);
stem(n, y1);
xlabel("ʱ����� n");
ylabel("���");
title("���˲��õ������");
grid;

yd = y - y1;
subplot(3, 1, 3);
stem(n, yd);
xlabel("ʱ����� n");
ylabel("���");
title("���ź����");
grid;
