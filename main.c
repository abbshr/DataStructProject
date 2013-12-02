#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

/*strut Timeval
{
    long tv_sec; 
    long tv_usec; 

};*/

int main(int argc, char const *argv[])
{
    timeval startTime, endTime;
    double timeuse;
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

    gettimeofday(&startTime, 0);
	   Naive_Match(p, str, n, m);
    gettimeofday(&endTime,0);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) 
            + endtime.tv_usec - startime.tv_usec;
    timeuse /= 1000;  //除以1000则进行毫秒计时，如果除以1000000则进行秒级别计时，如果除以1则进行微妙级别计时
    printf("%f\n", timeuse);
	
    gettimeofday(&startTime, 0);
        Rabin_Karp();
    gettimeofday(&endTime,0);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) 
            + endtime.tv_usec - startime.tv_usec;
    timeuse /= 1000;  //除以1000则进行毫秒计时，如果除以1000000则进行秒级别计时，如果除以1则进行微妙级别计时
    printf("%f\n", timeuse);

    gettimeofday(&startTime, 0);
	int* next = NULL;
	next = (int* )malloc(sizeof(int) * m);
	preprocess(next, p, m);
	   KMP(next, p, str, n, m);
    gettimeofday(&endTime,0);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) 
            + endtime.tv_usec - startime.tv_usec;
    timeuse /= 1000;  //除以1000则进行毫秒计时，如果除以1000000则进行秒级别计时，如果除以1则进行微妙级别计时
    printf("%f\n", timeuse);

	return 0;
}