% ������ɢʱ�丵��Ҷ�任��Ƶ������
clc;
clear;
w = -4 * pi: 8 * pi / 511: 4 * pi;
num = (2, 1);
den = (1, -0.6);
h = freqz(num, den, w);
subplot(2,1,1)
plot(w / pi, real(h));
grid;
title('ʵ��');
xlabel('\omega \pi');
ylabel(�������);
subplot(2,1,2)
plot(w/pi, imag(h)); grid;
title(���鲿��)
xlabel(��omega/\pi��);
ylabel(�������);
figure;
subplot(2,1,1)
plot(w/pi, abs(h)); grid;
title(�������ס�)
xlabel(��omega/\pi��);
ylabel(�������);
subplot(2,1,2)
plot(w/pi, angle (h)); grid;
title(����λ�ס�)
xlabel(��omega/\pi��);
ylabel(���Ի���Ϊ��λ����λ��);
