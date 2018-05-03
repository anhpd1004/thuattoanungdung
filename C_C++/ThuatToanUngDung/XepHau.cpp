#include <iostream>
#define MAX 20
using namespace std;
int n = 5;
int x[MAX];

bool check(int v, int k)
{
    for(int i = 1; i < k; i++)
    {
        if(v  == x[i] || (x[i]-i) == (v - k) || (x[i] - v) == (k - i))
            return false;
    }
    return true;
}

void display() {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(x[i] == j)
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(check(i, k))
        {
            x[k] = i;
            if(k == n)
                display();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    Try(1);
    return 0;
}
