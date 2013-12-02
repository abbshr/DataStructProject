#include <stdio.h>
#include <stdlib.h>

#include <alogthm.h>

int main(int argc, char const *argv[])
{
	/* read from file */
	char* str = NULL;
	int n;
	/* input pattern str */
	printf("模式串个数：\n");
	int m;
	scanf("%d", m);
	char* p = NULL;
	p = (char* )malloc(sizeof(char) * m);
	printf("输入模式串：\n");
	scanf("%c", p);

	/* comp */
	Naive_Match(p, str, n, m);

	Rabin_Karp();

	int* next = NULL;
	next = (int* )malloc(sizeof(int) * m);
	preprocess(next, p, m);
	KMP(next, p, str, n, m);

	return 0;
}