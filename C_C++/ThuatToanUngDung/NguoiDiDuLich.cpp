#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

using namespace std;

int A[MAX][MAX];
int x[MAX];int visited[MAX];
int f, f_best, n;
int x_best[MAX];
int cmin;

void readData(char * fn) {

    FILE *f = fopen(fn, "rb");
    int M;
    fscanf(f, "%d", &M);
    n = M-1;
    cmin = 99999999;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            fscanf(f, "%d", &A[i][j]);
            if(i != j & A[i][j] < cmin)
                cmin = A[i][j];
        }
    }
    fclose(f);
}
void init() {
    visited[0] = true;
    x[0] = 0;
    for(int i = 01; i<=n; i++) {
        visited[i] = false;
    }
    f = 0;
    f_best = 99999999;
}
 void updateBest()
 {
    if(f + A[x[n]][0] < f_best) {
        f_best = f + A[x[n]][0];
        memcpy(x_best, x, (n + 1)  * sizeof(int));
    }
 }

 void Try(int k)
 {
     for(int i = 1; i <= n; i++) {
        if(visited[i] == false) {
            x[k] = i;
            visited[i] = true;
            f += A[x[k-1]][x[k]];
            if(k == n) {
                updateBest();
            }
            else
                if(f + (n + 1 - k) * cmin < f_best)
                    Try(k + 1);
            visited[i] = false;
            f -= A[x[k-1]][x[k]];
        }
     }
 }

 void genData(char *fn, int n)
 {
    FILE *f = fopen(fn, "w+");
    fprintf(f, "%d\n", n);
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
     genData("E://data.txt", 20);
     readData("E://data.txt");
     init();
     Try(1);
     cout << "fbest = " << f_best <<endl;
     for(int i = 0; i <=n; i++)
        cout << x_best[i] << " ";
     return 0;
 }
