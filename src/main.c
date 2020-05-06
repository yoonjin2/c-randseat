#include "randseat.h"
#include<stdlib.h>
#include<time.h>
typedef unsigned long long num;
int main()
{
    clock_t time_st, time_end;
    register float exec_res;
    FILE *f, *g;
    f = fopen("result.txt", "wt");
    g = fopen("miss.txt", "rt");
    srand(time(NULL));
    register num start, end, people, missnumcheck;
    num *miss_pointer, missingno;
    start = firstnum();
    switch(start)
    {
    case 0:
        exit(1);
    }
    end = lastnum(start);
    switch(end)
    {
    case 0:
        exit(1);
    }
    time_st = clock();
    fscanf(g, "%llu", &missingno);
    printf("결번의 수는 %llu 입니다.\n",missingno);
    miss_pointer = calloc(missingno, sizeof(num));
    missnumcheck = check_missingnum(missingno, start, end);
    switch(missnumcheck)
    {
    case 0:
        free(miss_pointer);
        exit(1);
        break;
    }
    missnumcheck = missing_num(miss_pointer, missingno, end, g);
    if (missnumcheck == 0)
    {
        free(miss_pointer);
        exit(1);
    }
    people = end - start + 1;
    num *number = calloc(people,sizeof(num));
    check_err(number, people, start);
    check_miss(number, miss_pointer, people, missingno);
    printpeople(number, people, f);
    free(number);
    free(miss_pointer);
    time_end=clock();
    exec_res=(float)(time_end-time_st)/CLOCKS_PER_SEC;
    printf("%f\n", exec_res);
    system("python3 gui.py");
    return 0;
}
