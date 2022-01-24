#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void Binomial(void);
void HyperGeo(void);
void Poisson(void);
void NegBinomial(void);
void Gamma(void);
void Beta(void);
void Normal(void);
void Chi(void);
void TDIST(void);
void FDIST(void);

int main(void)
{
	int num, err;
	system("mkdir C:\\MathCom");
	system("move c:\disgraph.xlsm c:\\MathCom");
	system("move c:\contgraph.xlsm c:\\MathCom");
	system("cls");
	while (1)
	{
		rewind(stdin);

		printf("�˾ƺ� �� �ִ� �������� ����Դϴ�.\n");
		printf("---------------------------------------\n");
		printf("01. ���׺���\n");
		printf("02. �ʱ��Ϻ���\n");
		printf("03. Ǫ�Ƽۺ���\n");
		printf("04. �����׺���\n");
		printf("05. ��������\n");
		printf("06. ��Ÿ����\n");
		printf("07. ���Ժ���\n");
		printf("08. ī����������\n");
		printf("09. T����\n");
		printf("10. F����\n");
		printf("00. ������\n");
		printf("---------------------------------------\n");
		printf("����Ͻ� �������α׷��� ����ּ��� : ");
		num = 0;
		if (scanf_s("%d", &num) != 1) {
			system("cls");
			printf("���� ���ڸ� �Է����ּ���!\n��� �� ù ȭ������ ���ư��ϴ�."); rewind(stdin); Sleep(1000); system("cls");
			continue;
		}

		getchar();

		system("cls");

		switch (num)

		{
		case 1:Binomial(); break;
		case 2:HyperGeo(); break;
		case 3:Poisson(); break;
		case 4:NegBinomial(); break;
		case 5:Gamma(); break;
		case 6:Beta(); break;
		case 7:Normal(); break;
		case 8:Chi(); break;
		case 9:TDIST(); break;
		case 10:FDIST(); break;
		case 0:printf("��� �� ���α׷��� �����մϴ�...\n"); Sleep(1000); exit(1); break;
		}

		rewind(stdin);
	}
}

void Binomial(void)
{
	int i, num, state;
	char str[50], str1[50], fin[10];
	double n, p;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� ���׺����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("����Ƚ��(n)�� �Է����ּ��� (�ڿ����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &n);
		if (num != 1 or floor(n) != n or n <= 0) // ������� ���� �Է� / ������ �ƴ� �� �Է� / ���� �Է� ����ó��
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("�ڿ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("����Ȯ��(p)�� �Է����ּ��� (0�� 1 ������ ���� �����մϴ�.) : ");
		num = scanf_s("%lf", &p);
		if (num != 1 or p < 0 or p > 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("0�� 1 ������ ���� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      ��      ��      ��\n");
	fprintf(graph, "n,,%lf,,p,,%lf,,\n\n", n, p);
	fprintf(graph, "E(X),,\"=round(C2*G2,4)\",,Var(X),,\"=round(C2*G2*(1-G2),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(BINOM.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\"\n\n", n*p);

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n,%lf,p,%lf,\n", n, p);

	for (i = 0; i <= n; i++)
	{
		strcpy_s(str, "\"=BINOM.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", i + 2); // ���� i+7 ���� char�� fin�� ����
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%d,%s,\n", i, str);
	}

	state = fclose(graph);

	system("C:\\MathCom\\DisGraph.xlsm");
	system("cls");
}

void HyperGeo(void)
{
	int i, num, state;
	char str[50], str1[50], fin[10];
	double A, B, n;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� �ʱ��Ϻ����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("���(A)�� �Է����ּ���(�ڿ����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &A);
		if (num != 1 or floor(A) != A or A <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("�ڿ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("���(B)�� �Է����ּ���(�ڿ����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &B);
		if (num != 1 or floor(B) != B or B <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("�ڿ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("����Ƚ��(n)�� �Է����ּ���(A ������ �ڿ����� �����մϴ�.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or floor(n) != n or n <= 0 or n > A)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("A ������ �ڿ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      ��      ��      ��      ��\n");
	fprintf(graph, "A,,%lf,,B,,%lf,,n,,%lf,,\n\n", A, B, n);
	fprintf(graph, "E(X),,\"=round(K2*C2/(C2+G2),4)\",,Var(X),,\"=round((K2*C2*G2/(C2+G2)^2)*((C2+G2-F2)/(C2+G2-1)),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(HYPGEOM.DIST(C6,K2,C2,C2+G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\"\n\n", n*A / (A + B));

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "A,%lf,B,%lf,n,%lf,\n", A, B, n);

	for (i = 0; i <= n; i++)
	{
		strcpy_s(str, "\"=HYPGEOM.DIST(A");
		strcpy_s(str1, ",F1,B1,B1+D1,FALSE)\"");
		sprintf_s(fin, "%d", i + 2); // ���� i+7 ���� char�� fin�� ����
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%d,%s,\n", i, str);
	}

	state = fclose(graph);

	system("C:\\MathCom\\DisGraph.xlsm");
	system("cls");
}

void Poisson(void)
{
	int i, num, state;
	char str[50], str1[50], fin[10];
	double n;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� Ǫ�Ƽۺ����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("���(n)�� �Է����ּ���(����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "Ǫ      ��      ��      ��      ��\n");
	fprintf(graph, "n,,%lf\n\n", n);
	fprintf(graph, "E(X),,=C2,,Var(X),,=C2,,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(POISSON.DIST(C6,C2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\"\n\n", n);

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n,%lf,\n", n);

	if (n <= 4)
	{
		for (i = 0; i <= 10; i++)
		{
			strcpy_s(str, "\"=POISSON.DIST(A");
			strcpy_s(str1, ",B1,FALSE)\"");
			sprintf_s(fin, "%d", i + 2);
			strcat_s(str, fin);
			strcat_s(str, str1);

			fprintf(graph, "%d,%s,\n", i, str);
		}
	}

	else
	{
		for (i = 0; i <= n * 2; i++)
		{
			strcpy_s(str, "\"=POISSON.DIST(A");
			strcpy_s(str1, ",B1,FALSE)\"");
			sprintf_s(fin, "%d", i + 2);
			strcat_s(str, fin);
			strcat_s(str, str1);

			fprintf(graph, "%d,%s,\n", i, str);
		}
	}

	state = fclose(graph);

	system("C:\\MathCom\\DisGraph.xlsm");
	system("cls");
}

void NegBinomial(void)
{
	int i, num, state;
	char str[50], str1[50], fin[10];
	double r, p;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� �����׺����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("����Ƚ��(r)�� �Է����ּ��� (�ڿ����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &r);
		if (num != 1 or floor(r) != r or r <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("�ڿ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("����Ȯ��(p)�� �Է����ּ��� (0�� 1 ������ ���� �����մϴ�.) : ");
		num = scanf_s("%lf", &p);
		if (num != 1 or p < 0 or p > 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("0�� 1 ������ ���� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      ��      ��      ��      ��\n");
	fprintf(graph, "n,,%lf,,p,,%lf,,\n\n", r, p);
	fprintf(graph, "E(X),,\"=round(C2/G2,4)\",,Var(X),,\"=round((C2*(1-G2))/(G2*G2),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(NEGBINOM.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\"\n\n", r / p);

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "r,%lf,p,%lf,\n", r, p);

	if (r / p <= 2.4)
	{
		for (i = 0; i <= 10; i++)
		{
			strcpy_s(str, "\"=NEGBINOM.DIST(A");
			strcpy_s(str1, ",B1,D1,FALSE)\"");
			sprintf_s(fin, "%d", i + 2);
			strcat_s(str, fin);
			strcat_s(str, str1);

			fprintf(graph, "%d,%s,\n", i, str);
		}
	}

	else
	{
		for (i = 0; i <= 3 * r / p; i++)
		{
			strcpy_s(str, "\"=NEGBINOM.DIST(A");
			strcpy_s(str1, ",B1,D1,FALSE)\"");
			sprintf_s(fin, "%d", i + 2);
			strcat_s(str, fin);
			strcat_s(str, str1);

			fprintf(graph, "%d,%s,\n", i, str);
		}
	}

	state = fclose(graph);

	system("C:\\MathCom\\DisGraph.xlsm");
	system("cls");
}

void Gamma(void)
{
	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double i, k, s;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� ���������Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("��� �Ű����� k�� �Է����ּ��� (����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &k);
		if (num != 1 or k <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("ũ�� �Ű����� s�� �Է����ּ��� (����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &s);
		if (num != 1 or s <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      ��      ��      ��\n");
	fprintf(graph, "��纯��k,,%lf,,ũ�⺯��s,,%lf,,\n\n", k, s);
	fprintf(graph, "E(X),,\"=round(C2*G2,4)\",,Var(X),,\"=round(C2*G2*G2,4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,%lf,,���� ����,,\"=round(GAMMA.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\",,\n\n", k*s);
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(GAMMA.INV(C8/2,C2,G2),4)\",,���� X��,,\"=round(GAMMA.INV(1-C8/2,C2,G2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "k,%lf,s,%lf,\n", k, s);

	for (i = 0.001*k*s; i <= k * s * 4; i = i + 0.3*k*s)
	{
		strcpy_s(str, "\"=GAMMA.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}

	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

void Beta(void)
{
	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double i, a, b;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� ��Ÿ�����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("����(a)�� �Է����ּ��� (����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &a);
		if (num != 1 or a <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("��Ÿ(b)�� �Է����ּ��� (����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &b);
		if (num != 1 or b <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      Ÿ      ��      ��\n");
	fprintf(graph, "����(a),,%lf,,��Ÿ(b),,%lf,,\n\n", a, b);
	fprintf(graph, "E(X),,\"=round(C2/(C2+G2),4)\",,Var(X),,\"=round(C2*G2/((C2+G2)*(C2+G2)*(C2+G2+1)),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(BETA.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\",,\n\n", a / (a + b));
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(BETA.INV(C8/2,C2,G2),4)\",,���� X��,,\"=round(BETA.INV(1-C8/2,C2,G2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "����(a),%lf,��Ÿ(b),%lf,\n", a, b);

	for (i = 0; i <= 1.0; i = i + 0.1)
	{
		strcpy_s(str, "\"=BETA.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}

	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

void Normal(void)
{
	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double M, S, i;
	FILE *graph;

	printf("�ڼ����Ͻ� �Լ��� ���Ժ����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("���(M)�� ���� �Է����ּ��� : ");
		num = scanf_s("%lf", &M);
		if (num != 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("���ڸ� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("ǥ������(s)�� ���� �Է����ּ���(����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &S);
		if (num != 1 or S <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("���ڸ� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "��      ��      ��      ��\n");
	fprintf(graph, "M,,%lf,,s,,%lf,,\n\n", M, S);
	fprintf(graph, "E(X),,\"=round(C2,4)\",,Var(X),,\"=round(G2^2,4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(NORM.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,=1-G6,,\n\n", M);
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(NORM.INV(C8/2,C2,G2),4)\",,���� X��,,\"=round(NORM.INV(1-C8/2,C2,G2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "M,%lf,s,%lf,\n", M, S);

	for (i = M - 3 * S; i <= M + 3.1*S; i = i + 0.1*S)
	{
		strcpy_s(str, "\"=NORM.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}

	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

void Chi(void)
{
	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double i, n;
	FILE *graph;

	printf("�ڼ����Ͻ� �Լ��� ī���������� �Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("������ (n)�� �Է����ּ���.(����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���.\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....\n");

	fopen_s(&graph, "c:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "ī      ��      ��      ��      ��      ��\n");
	fprintf(graph, "n,,%lf,,\n\n", n);
	fprintf(graph, "E(X),,\"=round(C2,4)\",,Var(X),,\"=round(2*C2,4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(CHISQ.DIST(C6,C2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\",,\n\n", n);
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(CHISQ.INV(C8/2,C2),4)\",,���� X��,,\"=round(CHISQ.INV(1-C8/2,C2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n,%lf\n", n);

	for (i = 0.001*n; i <= 4 * n; i = i + 0.3*n)
	{
		strcpy_s(str, "\"=CHISQ.DIST(A");
		strcpy_s(str1, ",B1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}
	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

void TDIST(void)
{

	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double i, n;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� T�����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("������(n)�� �Է����ּ���(����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "T      ��      ��\n");
	fprintf(graph, "n,,%lf,,\n\n", n);
	fprintf(graph, "E(X),,=0,,Var(X),,\"=round(C2/(C2-2),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(T.DIST(C6,C2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\",,\n\n", 0.0);
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(T.INV(C8/2,C2),4)\",,���� X��,,\"=round(T.INV(1-C8/2,C2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n,%lf,\n", n);

	for (i = -3.0; i <= 3.1; i = i + 0.1)
	{
		strcpy_s(str, "\"=T.DIST(A");
		strcpy_s(str1, ",B1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}

	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

void FDIST(void)
{
	int cnt = 0, num, state;
	char str[50], str1[50], fin[10];
	double i, n1, n2;
	FILE *graph;


	printf("�ڼ����Ͻ� �Լ��� F�����Դϴ�.\n���߸� �����̴ٸ� z�� �Է��ϼ���!\n");
	while (1)
	{
		printf("������ n1�� �Է����ּ��� (����� �Է� �����մϴ�.): ");
		num = scanf_s("%lf", &n1);
		if (num != 1 or n1 <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	while (1)
	{
		printf("������ n2�� �Է����ּ��� (4���� ū ����� �Է� �����մϴ�.) : ");
		num = scanf_s("%lf", &n2);
		if (num != 1 or n2 <= 4)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("ó�� ȭ������ ���ư��ϴ�...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("4���� ū ����� �Է����ּ���!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("�׷����� ����մϴ�.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "F      ��      ��\n");
	fprintf(graph, "n1,,%lf,,n2,,%lf,,\n\n", n1, n2);
	fprintf(graph, "E(X),,\"=round(G2/(G2-2),4)\",,Var(X),,\"=round((2*G2*G2*(C2+G2-2))/(C2*(G2-2)*(G2-2)*(G2-4)),4)\",,\n\n");
	fprintf(graph, "X�� �Է�:,,\"=round(%lf,4)\",,���� ����,,\"=round(F.DIST(C6,C2,G2,TRUE),4)\",,���� ����,,\"=round(1-G6,4)\",,\n\n", n2 / (n2 - 2));
	fprintf(graph, "a�� �Է�:,,=0.05,,���� X��,,\"=round(F.INV(C8/2,C2,G2),4)\",,���� X��,,\"=round(F.INV(1-C8/2,C2,G2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n1,%lf,n2,%lf,\n", n1, n2);

	for (i = 0; i <= (4 * n2) / (n2 - 2); i = i + 0.1)
	{
		strcpy_s(str, "\"=F.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", cnt + 2);
		strcat_s(str, fin);
		strcat_s(str, str1);

		fprintf(graph, "%lf,%s,\n", i, str);
		cnt++;
	}

	state = fclose(graph);

	system("C:\\MathCom\\ContGraph.xlsm");
	system("cls");
}

