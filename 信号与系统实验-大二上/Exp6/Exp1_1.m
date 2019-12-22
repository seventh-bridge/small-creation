% ������ɢʱ�丵��Ҷ�任��Ƶ������
clc;
clear;
h_sig = [1, 2, 3, 4, 5, 6, 7, 8, 9];
w=0: 0.005: pi;
h = fft(h_sig, size(w, 2));
figure(1);
subplot(2, 1, 1)
plot(2 * w / pi, real(h));
axis([0, 1, -30, 50]);
grid;
title('ʵ��');
xlabel('$$ \omega / \pi $$', 'Interpreter', 'LaTeX');
ylabel('���');
subplot(2, 1, 2)
plot(2 * w / pi, imag(h));
axis([0, 1, -40, 50]);
grid;
title('�鲿');
xlabel('$$ \omega / \pi $$', 'Interpreter', 'LaTeX');
ylabel('���');
figure(2);
subplot(2, 1, 1);
plot(2 * w / pi, abs(h));
axis([0, 1, -30, 50]);
grid;
title('������');
xlabel('$$ \omega / \pi $$', 'Interpreter', 'LaTeX');
ylabel('���');
subplot(2, 1, 2);
plot(2 * w / pi, angle(h));
axis([0, 1, -10, 10]);
grid;
title('��λ��');
xlabel('$$ \omega / \pi $$', 'Interpreter', 'LaTeX');
ylabel('�Ի���Ϊ��λ����λ');
