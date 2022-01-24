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

		printf("알아볼 수 있는 분포들의 목록입니다.\n");
		printf("---------------------------------------\n");
		printf("01. 이항분포\n");
		printf("02. 초기하분포\n");
		printf("03. 푸아송분포\n");
		printf("04. 음이항분포\n");
		printf("05. 감마분포\n");
		printf("06. 베타분포\n");
		printf("07. 정규분포\n");
		printf("08. 카이제곱분포\n");
		printf("09. T분포\n");
		printf("10. F분포\n");
		printf("00. 끝내기\n");
		printf("---------------------------------------\n");
		printf("사용하실 분포프로그램을 골라주세요 : ");
		num = 0;
		if (scanf_s("%d", &num) != 1) {
			system("cls");
			printf("위의 숫자만 입력해주세요!\n잠시 후 첫 화면으로 돌아갑니다."); rewind(stdin); Sleep(1000); system("cls");
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
		case 0:printf("잠시 후 프로그램을 종료합니다...\n"); Sleep(1000); exit(1); break;
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


	printf("★선택하신 함수는 이항분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("시행횟수(n)을 입력해주세요 (자연수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &n);
		if (num != 1 or floor(n) != n or n <= 0) // 순서대로 문자 입력 / 정수가 아닌 수 입력 / 음수 입력 예외처리
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("자연수만 입력해주세요!\n");
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
		printf("성공확률(p)을 입력해주세요 (0과 1 사이의 수만 가능합니다.) : ");
		num = scanf_s("%lf", &p);
		if (num != 1 or p < 0 or p > 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("0과 1 사이의 수를 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "이      항      분      포\n");
	fprintf(graph, "n,,%lf,,p,,%lf,,\n\n", n, p);
	fprintf(graph, "E(X),,\"=round(C2*G2,4)\",,Var(X),,\"=round(C2*G2*(1-G2),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(BINOM.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\"\n\n", n*p);

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "n,%lf,p,%lf,\n", n, p);

	for (i = 0; i <= n; i++)
	{
		strcpy_s(str, "\"=BINOM.DIST(A");
		strcpy_s(str1, ",B1,D1,FALSE)\"");
		sprintf_s(fin, "%d", i + 2); // 정수 i+7 값을 char인 fin에 저장
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


	printf("★선택하신 함수는 초기하분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("모수(A)를 입력해주세요(자연수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &A);
		if (num != 1 or floor(A) != A or A <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("자연수만 입력해주세요!\n");
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
		printf("모수(B)을 입력해주세요(자연수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &B);
		if (num != 1 or floor(B) != B or B <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("자연수만 입력해주세요!\n");
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
		printf("시행횟수(n)을 입력해주세요(A 이하의 자연수만 가능합니다.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or floor(n) != n or n <= 0 or n > A)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("A 이하의 자연수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "초      기      하      분      포\n");
	fprintf(graph, "A,,%lf,,B,,%lf,,n,,%lf,,\n\n", A, B, n);
	fprintf(graph, "E(X),,\"=round(K2*C2/(C2+G2),4)\",,Var(X),,\"=round((K2*C2*G2/(C2+G2)^2)*((C2+G2-F2)/(C2+G2-1)),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(HYPGEOM.DIST(C6,K2,C2,C2+G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\"\n\n", n*A / (A + B));

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "A,%lf,B,%lf,n,%lf,\n", A, B, n);

	for (i = 0; i <= n; i++)
	{
		strcpy_s(str, "\"=HYPGEOM.DIST(A");
		strcpy_s(str1, ",F1,B1,B1+D1,FALSE)\"");
		sprintf_s(fin, "%d", i + 2); // 정수 i+7 값을 char인 fin에 저장
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


	printf("★선택하신 함수는 푸아송분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("모수(n)을 입력해주세요(양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "푸      아      송      분      포\n");
	fprintf(graph, "n,,%lf\n\n", n);
	fprintf(graph, "E(X),,=C2,,Var(X),,=C2,,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(POISSON.DIST(C6,C2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\"\n\n", n);

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


	printf("★선택하신 함수는 음이항분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("성공횟수(r)을 입력해주세요 (자연수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &r);
		if (num != 1 or floor(r) != r or r <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("자연수만 입력해주세요!\n");
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
		printf("성공확률(p)을 입력해주세요 (0과 1 사이의 수만 가능합니다.) : ");
		num = scanf_s("%lf", &p);
		if (num != 1 or p < 0 or p > 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("0과 1 사이의 수를 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "음      이      항      분      포\n");
	fprintf(graph, "n,,%lf,,p,,%lf,,\n\n", r, p);
	fprintf(graph, "E(X),,\"=round(C2/G2,4)\",,Var(X),,\"=round((C2*(1-G2))/(G2*G2),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(NEGBINOM.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\"\n\n", r / p);

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


	printf("★선택하신 함수는 감마분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("모양 매개변수 k를 입력해주세요 (양수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &k);
		if (num != 1 or k <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
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
		printf("크기 매개변수 s를 입력해주세요 (양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &s);
		if (num != 1 or s <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "감      마      분      포\n");
	fprintf(graph, "모양변수k,,%lf,,크기변수s,,%lf,,\n\n", k, s);
	fprintf(graph, "E(X),,\"=round(C2*G2,4)\",,Var(X),,\"=round(C2*G2*G2,4)\",,\n\n");
	fprintf(graph, "X값 입력:,,%lf,,좌측 방향,,\"=round(GAMMA.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\",,\n\n", k*s);
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(GAMMA.INV(C8/2,C2,G2),4)\",,우측 X값,,\"=round(GAMMA.INV(1-C8/2,C2,G2),4)\"");

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


	printf("★선택하신 함수는 베타분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("알파(a)를 입력해주세요 (양수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &a);
		if (num != 1 or a <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
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
		printf("베타(b)를 입력해주세요 (양수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &b);
		if (num != 1 or b <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "베      타      분      포\n");
	fprintf(graph, "알파(a),,%lf,,베타(b),,%lf,,\n\n", a, b);
	fprintf(graph, "E(X),,\"=round(C2/(C2+G2),4)\",,Var(X),,\"=round(C2*G2/((C2+G2)*(C2+G2)*(C2+G2+1)),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(BETA.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\",,\n\n", a / (a + b));
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(BETA.INV(C8/2,C2,G2),4)\",,우측 X값,,\"=round(BETA.INV(1-C8/2,C2,G2),4)\"");

	state = fclose(graph);

	fopen_s(&graph, "C:\\MathCom\\Data.csv", "w+");

	fprintf(graph, "알파(a),%lf,베타(b),%lf,\n", a, b);

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

	printf("★선택하신 함수는 정규분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("평균(M)의 값을 입력해주세요 : ");
		num = scanf_s("%lf", &M);
		if (num != 1)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("숫자만 입력해주세요!\n");
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
		printf("표준편차(s)의 값을 입력해주세요(양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &S);
		if (num != 1 or S <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("숫자만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "정      규      분      포\n");
	fprintf(graph, "M,,%lf,,s,,%lf,,\n\n", M, S);
	fprintf(graph, "E(X),,\"=round(C2,4)\",,Var(X),,\"=round(G2^2,4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(NORM.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,=1-G6,,\n\n", M);
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(NORM.INV(C8/2,C2,G2),4)\",,우측 X값,,\"=round(NORM.INV(1-C8/2,C2,G2),4)\"");

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

	printf("★선택하신 함수는 카이제곱분포 입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("자유도 (n)을 입력해주세요.(양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요.\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....\n");

	fopen_s(&graph, "c:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "카      이      제      곱      분      포\n");
	fprintf(graph, "n,,%lf,,\n\n", n);
	fprintf(graph, "E(X),,\"=round(C2,4)\",,Var(X),,\"=round(2*C2,4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(CHISQ.DIST(C6,C2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\",,\n\n", n);
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(CHISQ.INV(C8/2,C2),4)\",,우측 X값,,\"=round(CHISQ.INV(1-C8/2,C2),4)\"");

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


	printf("★선택하신 함수는 T분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("자유도(n)을 입력해주세요(양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &n);
		if (num != 1 or n <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "T      분      포\n");
	fprintf(graph, "n,,%lf,,\n\n", n);
	fprintf(graph, "E(X),,=0,,Var(X),,\"=round(C2/(C2-2),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(T.DIST(C6,C2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\",,\n\n", 0.0);
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(T.INV(C8/2,C2),4)\",,우측 X값,,\"=round(T.INV(1-C8/2,C2),4)\"");

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


	printf("★선택하신 함수는 F분포입니다.\n☆잘못 들어오셨다면 z를 입력하세요!\n");
	while (1)
	{
		printf("자유도 n1을 입력해주세요 (양수만 입력 가능합니다.): ");
		num = scanf_s("%lf", &n1);
		if (num != 1 or n1 <= 0)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("양수만 입력해주세요!\n");
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
		printf("자유도 n2을 입력해주세요 (4보다 큰 양수만 입력 가능합니다.) : ");
		num = scanf_s("%lf", &n2);
		if (num != 1 or n2 <= 4)
		{
			if (getchar() == 'z')
			{
				system("cls");
				rewind(stdin);
				printf("처음 화면으로 돌아갑니다...");
				Sleep(1000);
				system("cls");
				return;
			}
			printf("4보다 큰 양수만 입력해주세요!\n");
			rewind(stdin);
		}
		else
		{
			rewind(stdin);
			num = 0;
			break;
		}
	}
	printf("그래프를 출력합니다.....");

	fopen_s(&graph, "C:\\MathCom\\Distribution.csv", "w+");

	fprintf(graph, "F      분      포\n");
	fprintf(graph, "n1,,%lf,,n2,,%lf,,\n\n", n1, n2);
	fprintf(graph, "E(X),,\"=round(G2/(G2-2),4)\",,Var(X),,\"=round((2*G2*G2*(C2+G2-2))/(C2*(G2-2)*(G2-2)*(G2-4)),4)\",,\n\n");
	fprintf(graph, "X값 입력:,,\"=round(%lf,4)\",,좌측 방향,,\"=round(F.DIST(C6,C2,G2,TRUE),4)\",,우측 방향,,\"=round(1-G6,4)\",,\n\n", n2 / (n2 - 2));
	fprintf(graph, "a값 입력:,,=0.05,,좌측 X값,,\"=round(F.INV(C8/2,C2,G2),4)\",,우측 X값,,\"=round(F.INV(1-C8/2,C2,G2),4)\"");

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

