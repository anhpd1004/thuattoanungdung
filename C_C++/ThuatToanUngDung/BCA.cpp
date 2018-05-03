#include <stdio.h>
#include <iostream>

#define MAX 31

using namespace std;

bool conflict[MAX][MAX];
bool list_cources[MAX][MAX];
bool assigned[MAX];
int f_best;
int X[MAX];
int load[11];
int n, m;

void init()
{
    f_best = 99999999;
    for(int i=0; i< MAX; i++) {
        for(int j=0; j< MAX; j++)
            conflict[i][j] = 0;
    }
    for(int i = 0; i < 11; i++)
        X[i] = 0;
}
int findMax()
{
    int m = load[1];
    for(int i = 2; i < 11; i++)
        if(m < load[1])
            m = load[i];
    return m;
}

void ReadFile(char * fileName)
{
    FILE *f = fopen(fileName, "r+");

    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);
    for(int i = 0; i < m; i++) {
        int k;
        fscanf(f, "%d", &k);
        for(int j = 0; j < k; j++) {
            fscanf(f, "%d", &list_cources[i+1][j+1]);
        }
    }
    int k1;
    fscanf(f, "%d", &k1);
    for(int i = 0; i < k1; i++) {
        int x, y;
        fscanf(f, "%d", &x);
        fscanf(f, "%d", &y);
        conflict[x][y] = true;
    }
    fclose(f);
}

bool check(int i, int k)
{
    if(assigned[i] == true)
        return false;
    for(int j=0; j < MAX; j++) {
        if(list_cources[i][j]) {
            if(conflict[j][k])
                return false;
        }
    }
    if(list_cources[i][k] == false)
        return false;
    if(load[i] + 1 >= f_best)
        return false;
    return true;
}

void updateBest()
{
    int m = findMax();
    f_best = (f_best < m) ? f_best : m;
}

void Try(int k)
{
    for(int i = 1; i <= m; i++) {
        if(check(i, k)) {
            X[k] = i;
            load[i] = load[i] + 1;
            assigned[k] = true;
            if(k == n) {
                updateBest();
            } else {
                Try(k + 1);
            }
            assigned[k] = false;
            load[i] = load[i] - 1;
        }
    }
}
int main()
{
    init();
    ReadFile("E://BCA.inp");
    Try(1);
    cout << f_best;
    return 0;
}
