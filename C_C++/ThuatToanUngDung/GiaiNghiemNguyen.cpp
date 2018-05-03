#include <iostream>
#define MAX 100

using namespace std;

int n;
int x[MAX];
int M, T;


void display() {
    for(int i=1; i<= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int k) {
    for(int i=1; i<= M - (n-k) - T; i++) {
        x[k] = i;
        T += x[k];
        if(k == n) {
            if(T == M) {
                display();
            }
        }
        else {
            Try(k + 1);
        }
        T -= x[k];
    }
}

int main()
{
    n = 3;
    T = 0;
    M = 10;
    Try(1);
    return 0;
}
