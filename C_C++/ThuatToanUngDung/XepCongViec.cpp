#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

using namespace std;

int A[MAX][MAX];
int x[MAX];//i
int y[MAX];//j
int human[MAX];
int cv[MAX];
int f, f_best, n;
int x_best[MAX];
int y_best[MAX];
int cmin;

void readData(char * fn) {

    FILE *f = fopen(fn, "r+");
    fscanf(f, "%d", &n);
    cmin = 99999999;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fscanf(f, "%d", &A[i][j]);
            if(i != j & A[i][j] < cmin)
                cmin = A[i][j];
        }
    }
    fclose(f);
}
void init() {
    for(int i = 0; i<=n; i++) {
        human[i] = false;
        cv[i] = false;
    }
    f = 0;
    f_best = 99999999;
}
 void updateBest()
 {
    if(f < f_best) {
        f_best = f;
        memcpy(x_best, x, (n + 1)  * sizeof(int));
        memcpy(y_best, y, (n+1) * sizeof(int));
    }
 }

 void Try(int k)
 {
     for(int i = 1; i <= n; i++) {
        if(human[i] == false) {
            for(int j = 1; j <= n; j++) {
                if(cv[j] == false) {
                    x[k] = i;
                    y[k] = j;
                    cv[j] = true;
                    human[i] = true;
                    f += A[x[k]][y[k]];
                    if(k == n) {
                        updateBest();
                    }
                    else
                        if(f + (n + 1 - k) * cmin < f_best)
                            Try(k + 1);
                    human[i] = false;
                    cv[j] = false;
                    f -= A[x[k]][y[k]];
                }
            }
        }
     }
 }

 void genData(char *fn, int n)
 {
    FILE *f = fopen(fn, "w+");
    int t;
    srand(time(NULL));
    for(int i = 0; i<n; i++) {
        for(int j=0; j< n; j++) {
            if(i == j) {
                fprintf(f, "0 ");
            }
            else {
                t = rand() % 1000 + 1;
                fprintf(f, "%d ", t);
            }
        }
        fprintf(f, "\n");
    }
    fclose(f);
 }

 int main()
 {
     genData("E://data.txt", 5);
     readData("E://data.txt");
     init();
     Try(1);
     cout << "fbest = " << f_best <<endl;
     for(int i = 0; i <=n; i++)
        cout << x_best[i] << " ";
     return 0;
 }
