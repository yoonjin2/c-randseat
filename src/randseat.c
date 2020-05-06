#include "randseat.h"
#include<limits.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
typedef unsigned long long num;
/*무작위로 중복과 결번 없이 좌석 배치*/
void check_err(num *number, num people, num start)
{
	register num check, rep;
	for (rep = 0; rep < people; rep++)
	{
		OUTOFLOOP:
		*(number + rep) = rand() % people + start;
		for (check = 0; check < rep; check++)
		{
			if (*(number + rep) == *(number + check))
			{
				while(1)
				{
					if(*(number + rep) != *(number + check))
						rep++;
						goto OUTOFLOOP;
				} 
			}
		}
	}
}
/*인원출력*/
void printpeople(num *number, num people, FILE *f)
{	register short x;
	auto char * string=malloc(sizeof(char)*21);
	register num countnum, check = 0;
	for (countnum = 0; countnum < people; countnum++)
	{
		sprintf(string,"%llu", *(number + countnum));
		if (*(number + countnum) != 0)
		{
			printf("[%llu]", *(number + countnum));
			for(x=0;x<22-strlen(string);x++)
				putc(' ',stdout);
			fprintf(f, "[%llu]", *(number + countnum));
			for(x=0;x<22-strlen(string);x++)
				fprintf(f," ");
			check++;
			if (check % 2 == 0)
			{
				if (check % 6 == 0)
				{
					putc('\n',stdout);
					fputc('\n',f);
				}
				else
				{
					for(x=0;x<30;x++)
					{
						putc(' ',stdout);
						fputc(' ',f);
					}
				}
			}
		}
	}
	fclose(f);
	free(string);
	putc('\n',stdout);
}
/*인원 확인 및 오류 점검*/
num check_missingnum(num missingno, num start, num end)
{
	if (missingno == end - start)
	{
		puts("출력할 대상이 1명입니다.");
		return 0;
	}
	else if (missingno == 0)
	{
		puts("결번 없이 진행합니다.");
		return 1;
	}
	else if (missingno == end - start + 1)
	{
		puts("출력할 대상이 0명입니다.");
		return 0;
	}
	else if (missingno < 1)
	{
		puts("오류, 받지 않습니다!");
		return 0;
	}
}

/*결번처리함수*/
/*결번을 0으로 대체*/
void check_miss(num *number, num *miss_pointer, num people, num missingno)
{
	register num countnum, countnum0;
	for (countnum = 0; countnum < people; countnum++)
	{
		/*결번을 0으로 변환*/
		for (countnum0 = 0; countnum0 < missingno; countnum0++)
		{
			if (*(number + countnum) == *(miss_pointer + countnum0))
				*(number + countnum) = 0;
		}
	}
}
/* 시작 번호 입력 */
num firstnum()
{
	num start;
	puts("시작 번호:\n");
	scanf("%llu", &start);
	return start;
}
/*끝 번호 입력*/
num lastnum(num start)
{
	num end;
	puts("끝 번호:\n");
	scanf("%llu", &end);
	if (end < start)
	{
		printf("0번/음수는 입력불가합니다.\n");
		return 0;
	}
	else
		return end;
}
/*결번 기입*/
num missing_num(num *miss_pointer, num missingno, num end,FILE * f)
{
	register num misscount;
	for (misscount = 0; misscount < missingno; misscount++)
	{
		fscanf(f, "%llu", miss_pointer + misscount);
	}
}
