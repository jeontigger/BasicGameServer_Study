#include<stdio.h>
#include<string.h>

void main(void) {
	char str1[20] = "Mathematics", str2[20] = {"0"}, str3[10] = {"0"};

	printf("Original String : %s \n", str1);

	strcpy(str2, str1);
	printf("strcpy String : %s \n", str2);
	
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = '\0';
	printf("strncpy String : %s \n", str3);

	getchar();
	getchar();

}