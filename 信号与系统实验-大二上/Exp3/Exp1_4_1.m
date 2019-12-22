clc;
clear;

n = (0: 40);
delta = (n ~= 0) * 0 + (n == 0) * 1;

f = 1.5 * sin(2 * pi * 0.2 * n);
f_conv = conv(f, delta);
fd = f(1: 40) - f_conv(1: 40);

subplot(3, 1, 1);
stem(f);
axis([0, 40, -5, 5]);
xlabel("ʱ����� n");
ylabel("���");
title("f");
grid;

subplot(3, 1, 2);
stem(f_conv);
axis([0, 40, -5, 5]);
xlabel("ʱ����� n");
ylabel("���");
title("conv(f, delta)");
grid;

subplot(3, 1, 3);
stem(fd);
axis([0, 40, -5, 5]);
xlabel("ʱ����� n");
ylabel("���");
title("���ź����");
grid;
