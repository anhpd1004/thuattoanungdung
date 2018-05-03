#include <stdio.h>
#include <iostream>
#define MAX 100
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int A[MAX][MAX];//mang chi phi
int x[MAX];//mang luu hanh trinh di hien tai
int x_best[MAX];
int n, f, f_best;

void genData(char *fileName, int n)
{
    FILE *f = fopen(fileName, "w+");
    fprintf(f, "%d %d\n", n, m);

}
