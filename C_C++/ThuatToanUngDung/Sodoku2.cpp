#include <iostream>
#include <stdio.h>

using namespace std;

int x[9][9];
int mc[9][10];
int mr[9][10];
int mrc[3][3][10];
char key;

void display() {
    for(int i=0; i< 9; i++) {
        for(int j = 0; j< 9; j++)
            cout<<x[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool check(int v, int r, int c)
{
    if(mr[r][v]) return false;
    if(mc[c][v]) return false;
    if(mrc[r/3][c/3][v]) return false;
    return true;
}

void Try(int r, int c)
{
    for(int i = 1; i < 10; i++) {
        if(check(i, r, c)) {
            x[r][c] = i;
            mr[r][i] = true;
            mc[c][i] = true;
            mrc[r/3][c/3][i] = true;
            if(r == 8 && c == 8) {
                display();
                cout << "Ban muon xem tiep?";
                key = getchar();
            }
            else {
                if(c < 8) {
                    Try(r, c+1);
                }
                else
                    Try(r+1, 0);
            }

            mr[r][i] = false;
            mc[c][i] = false;
            mrc[r/3][c/3][i] = false;
        }
    }
}

int main()
{

    Try(0, 0);
    return 0;
}

