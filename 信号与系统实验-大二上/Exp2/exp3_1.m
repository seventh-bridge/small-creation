clear;
clc;

N = 45;

num = [0.9, -0.45, 0.35, 0.002];
den = [1, 0.71, -0.46, -0.62];

y = impz(num, den, N);    % ��1��ʼ

t = (1: 1: 45);
delta = (t ~= 1) * 0 + (t == 1) * 1;
yd = filter(num, den, delta);

d = yd - y';

subplot(3, 1, 1);
stem(y);
xlabel('ʱ�����');
ylabel('impz ���');
grid;

subplot(3, 1, 2);
stem(t, yd);
xlabel('ʱ�����');
ylabel('�弤���� ���');
grid;

subplot(3, 1, 3);
stem(t, d);
xlabel('ʱ�����');
ylabel('��� ���');
grid;
