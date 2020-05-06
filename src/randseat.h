#ifndef RANDSEAT_H
#define RANDSEAT_H
#include<stdio.h>
typedef unsigned long long num;
/*인원 출력 함수*/
void printpeople(num *number, num people, FILE *f);
/*시작 번호 입력함수*/
num firstnum();
/*끝 번호 입력함수*/
num lastnum(num start);
/*결번처리 함수*/
void check_miss(num *number, num *miss_pointer, num people, num missingno);
num missing_num(num *miss_pointer, num missingno, num end, FILE * f);
void check_err(num *number, num people, num start);
num check_missingnum(num missingno, num start, num end);
#endif
