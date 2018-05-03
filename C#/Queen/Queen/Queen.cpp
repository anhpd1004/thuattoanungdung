#include "stdafx.h"
#include <iostream>
#define MAX 20
using namespace std;
int n = 8;
int x[MAX];
int dem;

bool check(int v, int k)
{
	for (int i = 1; i < k; i++)
	{
		if (v == x[i] || (x[i] - i) == (v - k) || (x[i] - v) == (k - i))
			return false;
	}
	return true;
}

void display() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (x[i] == j)
				cout << "-1-";
			else
				cout << "-0-";
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (check(i, k))
		{
			x[k] = i;
			if (k == n) {
				dem++;
			}
			else {
				Try(k + 1);
			}
				
		}
	}
}

int main()
{
	dem = 0;
	Try(1);
	cout << dem << endl;
	return 0;
}
