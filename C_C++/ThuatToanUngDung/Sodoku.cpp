#include <iostream>
#include <stdio.h>

using namespace std;

int x[9][9];
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
    for(int i = 0; i < r -1; i++) {
        if(x[r][c] == v) return false;
    }
    for(int i = 0; i< c; i++)
        if(x[r][i] == v)
            return false;
    int I = r/3;
    int J = c / 3;
    int i = r - 3*I;
    int j = c - 3*J;
    for(int i1 = 0; i1 < i; i1++) {
        for(int j1 = 0; j1 < 3; j1++) {
            if(x[3 * I + i1][3*J + j1] == v)
                return false;
        }
    }
    for(int j1 = 0; j1 < j; j1++) {
        if(x[3*I + i][3*J + j1] == v)
            return false;
    }
    return true;
}

void Try(int r, int c)
{
    for(int i = 1; i < 10; i++) {
        if(check(i, r, c)) {
            x[r][c] = i;
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
        }
    }
}

int main()
{
    Try(0, 0);
    return 0;
}
