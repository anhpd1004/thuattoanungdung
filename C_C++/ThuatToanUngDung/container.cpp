#include <stdio.h>
#include <iostream>

using namespace std;

bool result = false;

typedef struct item {
    int w;
    int h;
} ITEM;

//KHAI BAO
ITEM items[13];
int Xw[13];
int Xh[13];
bool closed[31][31];
int H, W, N;

void init()
{
    for(int i = 0; i <= 13; i++) {
        Xw[i] = 0;
        Xh[i] = 0;
    }
    for(int i = 0; i <= 31; i++)
        for(int j = 0; j <= 31; j++)
        closed[i][j] = false;
}

void ReadData(char * fileName)
{
    FILE *f = fopen(fileName, "r+");
    fscanf(f, "%d", &H);
    fscanf(f, "%d", &W);
    fscanf(f, "%d", &N);
    for(int i = 1; i <= N; i++) {
        fscanf(f, "%d", &items[i].h);
        fscanf(f, "%d", &items[i].w);
    }
}

bool check(int i, int j, int k)
{
    if(i + items[k].w > W)
        return false;
    if(j + items[k].h > H)
        return false;
    for(int x = i; x <= i + items[k].w; x++) {
        for(int y = j; y <= j + items[k].h; y++) {
            if(closed[x][y])
                return false;
        }
    }
    return true;
}

void Try(int k)
{
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            if(check(i, j, k)) {
                Xw[k] = i;
                Xh[k] = j;
                for(int x = i; x <= i + items[k].w; x++) {
                    for(int y = j; y <= j + items[k].h; y++) {
                        closed[x][y] = true;
                    }
                }
                if(k == N) {
                    result = true;
                    break;
                } else {
                    Try(k + 1);
                }
                for(int x = i; x <= i + items[k].w; x++) {
                    for(int y = j; y <= j + items[k].h; y++) {
                        closed[x][y] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    init();
    ReadData("E://BP.inp");
    Try(1);
    if(result)
        cout << "1";
    else
        cout << "0";
    return 0;
}
