#include<stdio.h>


void main(void)
{
	unsigned long dec, i, j, a[100];

	while (1)
	{
		printf("�������� ��ȯ�� 10������ �Է����ּ���:");
		scanf_s("%d", &dec);

		i = 1;

		while (dec >= 1) // 2�� ���� �������� �迭�� �Է�
		{
			a[i] = dec % 2;
			dec = dec / 2;
			i++;
		}

		printf("\n�ش� ���� ������ ǥ���� ������ �����ϴ�:");

		for (j = i - 1; j >= 1; j--) // �Է��� �������� ���
		{
			printf("%d", a[j]);
			if (j % 4 == 0)
				printf("/");
		}

		printf("\n");
		printf("\n");
	}
}