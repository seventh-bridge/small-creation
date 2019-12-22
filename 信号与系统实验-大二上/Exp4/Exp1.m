clc;
clear;
t = (0: 0.0001: 0.25);          % 0-0.25 ʱ����Ϊ 0.0001
y = zeros(10, max(size(t)));  % 10*629��t�ĳ��ȣ��ľ���
x = zeros(10, max(size(t)));
for k = (1: 2: 9)             % ���г�� 1, 3, 5, 7, 9
    x1 = ((4 * 3) / pi) * sin(k * 100 * t) / k;      % ����г�����ҷ���
    x(k,:) = x(k,:) + x1;     % x��k(1, 3, 5, 7, 9)�д��k��г����629��ֵ
    y((k + 1) / 2,:) = x(k,:); % �������������������1-5��
end
figure(1);
subplot(5, 1, 1);
plot(t, y(1, :));
grid;
title('��һ��г������');
subplot(5, 1, 2);
plot(t, y(2, :));
grid;
title('�ڶ���г������');
subplot(5, 1, 3);
plot(t, y(3, :));
grid;
title('������г������');
subplot(5, 1, 4);
plot(t, y(4, :));
grid;
title('������г������');
subplot(5, 1, 5);
plot(t, y(5, :));
grid;
title('������г������');
figure(2);
subplot(2, 1, 1);
plot(t, y(1: 5,:));           % ���ƾ�����1-5����ʱ��仯�Ĳ���
grid;
title('��ά����ͼ');
halft = ceil(length(t) / 2);  % ���������ȼ��루���ڶԳ�ǰ���һ�£�
subplot(2, 1, 2);             % ������άͼ�Σ�����y��ȫ����������һ��
mesh(t(1: halft), (1: 10), y(:, 1: halft));
title('��άͼ��');
