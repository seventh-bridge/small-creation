% ����ѧ����ԭ�� ��13��
clc;
clear;
% ����˵��
fprintf("��դ�������ǿ�����߻��� ��ԭ����С�� #13\n\n");
fprintf("ģ�Ⲩ��Ϊ lambda �ĵ�ɫ����ֱ�����ڹ�դ����Ϊ d��͸�ⲿ�ֿ��Ϊ a �Ĺ�դʱ��\n");
fprintf("�������������ƵĹ�ǿ�����ߡ�\n--------------------\n\n");
% �����Ҫ������
fprintf("�������դ�����ĵ��� 1/d����λ����/���ף���\n");
d = input("1/d = ");
d_nm = (1 * 1000 * 1000) / d;
fprintf("\n�������߼�͸�ⲿ�ֵĿ�� a����λ��΢�ף���\n");
a = input("a = ");
a_nm = a * 1000;
% �ж�a�Ƿ�С��b
if (1000 / d) / 2 < a
  fprintf("\naӦС��b��\n");
  return;
end
clear a d;
% ��Ĳ���
fprintf("\n����������Ⲩ�� lambda����λ�����ף���\n");
lambda_in = input("lambda = ");
% ��դ��������ͼ��
fprintf("\n������͸���դ�ܷ��� N��\n");
N = input("N = ");
% ���� mu �� beta
sin_theta = (-1: 0.001: 1);
mu = ((pi * a_nm) / lambda_in) * sin_theta;
beta = ((pi * d_nm) / lambda_in) * sin_theta;
clear lambda_in a_nm d_nm;
% ������������
single_slit = (sin(mu) ./ mu) .^ 2;
clear mu;
% �����жϡ���һ������������
for i = (1: size(single_slit, 2))
    if isnan(single_slit(i))
        single_slit(i) = 1;
    end
end
% ����������
mul_inter = (sin(N .* beta) ./ sin(beta)) .^ 2;
clear beta;
% �����жϡ���һ������������
for i = (1: size(mul_inter, 2))
    if isnan(mul_inter(i))
        mul_inter(i) = N ^ 2;
    end
end
clear i;
% ���е���
grating_func = single_slit .* mul_inter;
% ��ͼ
% ������������
subplot(2, 2, 1);
plot(sin_theta, single_slit);
xlabel('$$ \sin{\theta} $$', 'Interpreter', 'LaTeX');
ylabel('$$ \frac{\sin{\mu}}{\mu} $$', 'Interpreter', 'LaTeX');
title('���������������ǿ��');
% ����������
subplot(2, 2, 2);
plot(sin_theta, mul_inter);
xlabel('$$ \sin{\theta} $$', 'Interpreter', 'LaTeX');
ylabel('$$  \frac{\sin{N \beta}}{\sin{\beta}} $$', 'Interpreter', 'LaTeX');
title('�������������ǿ��');
% ���չ�դ���ǿ��ͼ��
subplot(2, 2, 3: 4);
plot(sin_theta, grating_func);
xlabel('$$ \sin{\theta} $$', 'Interpreter', 'LaTeX');
title('��դ�������ǿ��');
% �������ƻҶ�ͼ
x = ones(1, size(grating_func, 2));
% һ���ߵĻҶ�
x_line = x .* (grating_func ./ (N ^ 2));
clear x;
% ������
x_rep = repmat(x_line, ceil(size(grating_func, 2) * 3 / 4), 1);
clear x_line;
% �Ҷ�ת��
gray_img = mat2gray(x_rep);
% Ϊ����۲죬����ͨ��gamma���߽�������
gray_img = imadjust(gray_img, [0, 1], [0, 1], 0.5);
% �´��ڻ��ƻҶ�ͼ
figure(2);
imshow(gray_img);
title('�Ҷ�ͼ');
fprintf("��ͼ��ϣ�\n");
