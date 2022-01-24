#include<stdio.h>


void main(void)
{
	unsigned long dec, i, j, a[100];

	while (1)
	{
		printf("이진수로 변환할 10진수를 입력해주세요:");
		scanf_s("%d", &dec);

		i = 1;

		while (dec >= 1) // 2로 나눈 나머지들 배열에 입력
		{
			a[i] = dec % 2;
			dec = dec / 2;
			i++;
		}

		printf("\n해당 수의 이진수 표현은 다음과 같습니다:");

		for (j = i - 1; j >= 1; j--) // 입력의 역순으로 출력
		{
			printf("%d", a[j]);
			if (j % 4 == 0)
				printf("/");
		}

		printf("\n");
		printf("\n");
	}
}