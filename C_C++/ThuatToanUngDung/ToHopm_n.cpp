#include <iostream>
#include <stdio.h>
#define MAX 100

using namespace std;

int visited[MAX];
int x[MAX];
int n, m, vitri, dem;

void display() {
    for(int i = 1; i <= m; i++) {
        cout << x[i] << " " ;
    }
    cout << endl;
}

void init()
{
    for(int i = 1; i<=n; i++) {
        visited[i] = false;
    }
    dem = 0;
}

void Try(int k)
{
    for(int i=1; i<=n; i++) {
        if(!visited[i] && i > x[k-1]) {
            x[k] = i;
            visited[i] = true;
            if(k == m) {
                dem++;
                if(dem == vitri) {
                    display();
                    break;
                }
            } else {
                Try(k + 1);
            }
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;
    cin >> vitri;
    Try(1);
    if(dem < vitri) cout << "-1";
    return 0;
}
