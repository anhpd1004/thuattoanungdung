#include <stdio.h>
#include <iostream>
#define MAX 41

using namespace std;

int X[MAX];//X[i] luu nguoi day mon thu i
int n, m;
int f_best;
int load[11]; //load[i] la tai trong cua giang vien thu i
bool conflict[MAX][MAX];
bool assigned[MAX];//assigned[i] mon thu i da duoc giao
bool list_courses[11][MAX];//list_courses[i][j] la mon thu j co trong danh sach giang vien thu i
bool list_assigned_courses[11][MAX];
bool rs;

void init()
{
    rs = false;
    f_best = MAX;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++)
            conflict[i][j] = false;
    }
    for(int i = 0; i < MAX; i++)
        X[i] = 0;
    for(int i = 0; i < 11; i++) {
        load[i] = 0;
    }
    for(int i = 0; i < MAX; i++)
        assigned[i] = false;
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < MAX; j++) {
            list_courses[i][j] = false;
        }
    }
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < MAX; j++) {
			list_assigned_courses[i][j] = false;
		}
	}
}

void ReadFile()
{

	scanf("%d", &m);
	scanf("%d", &n);
	for(int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			int temp;
			scanf("%d", &temp);
			list_courses[i + 1][temp] = true;
		}
	}
	int k1;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		int x, y;
		scanf("%d", &x);
		scanf("%d", &y);
		conflict[x][y] = true;
	}
}
bool check(int i, int k)
{
    if (assigned[k])
		return false;
	if (!list_courses[i][k])
		return false;
	if (load[i] + 1 >= f_best)
		return false;
	for (int j = 1; j < k; j++) {
		if (list_courses[i][j] && list_assigned_courses[i][j]) {
			if (conflict[j][k])
				return false;
		}
	}
	return true;
}

void updateBest()
{
    int m = load[1];
    for(int i = 2; i <= m; i++) {
        m = (m > load[i]) ? m : load[i];
    }
    f_best = (f_best < m) ? f_best : m;
}
void Try(int k)
{
	for (int i = 1; i <= m; i++) {
		if (check(i, k)) {
			X[k] = i;
			load[i]++;
			assigned[k] = true;//da duyet
			list_assigned_courses[i][k] = true;
			if (k == n) {
			    rs = true;
				updateBest();
			}
			else {
				Try(k + 1);
			}
			list_assigned_courses[i][k] = false;
			assigned[k] = false;
			load[i]--;
		}
	}
}
int main()
{
    init();
    ReadFile();
    if(m > 10 || n > 40) {
        cout << "-1";
    }
    else {
        Try(1);
    if(rs)
        cout << f_best;
    else
        cout << "-1";
    }

    return 0;
}
