// ThuSauNgay26_01_2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char * Add1(char *a, char *b) {
	int n = strlen(b);
	int k = strlen(b) - strlen(a);
	char * c = (char*)calloc(n + 2, sizeof(char));
	char nho = 0;
	for (int j = n; j > k; j--) {
		c[j] = (b[j-1] + nho + a[j - k - 1] - 96) % 10 + 48;
		nho = (b[j - 1] + nho + a[j - k - 1] - 96) / 10;
	}
	for (int j = k; j > 0; j--) {
		c[j] = (b[j - 1] - 48 + nho) % 10 + 48;
		nho = (b[j - 1] - 48 + nho) / 10;
	}
	c[0] = (nho == 0) ? '0' : '1';
	c[n + 1] = 0;
	return c;
}

//in ra ket qua cua phep cong
void PrintADD(char *c) {
	int len = strlen(c);
	for (int i = (c[0] == '1' ? 0 : 1); i < len; i++)
		cout << c[i];
}

char * Add(char *a, char *b) {
	int lenA = strlen(a);
	int lenB = strlen(b);
	if (lenA > lenB) {
		return Add1(b, a);
	}
	return Add1(a, b);
}
long AddMod(long a, long b, long c) {
	a %= c;
	b %= c;
	return (a < c - b) ? (a + b) : ((a - c) + b);
}

long MulMod1(long a, long b, long c) {
	if (a == 0 || b == 0) return 0;
	if (a & 1) {
		long a1 = (a - 1) / 2;
		a1 = MulMod1(a1, b, c);
		return AddMod(a1, AddMod(a1, b, c), c);
	}
	else {
		long a1 = a / 2;
		a1 = MulMod1(a1, b, c);
		return AddMod(a1, a1, c);
	}
}

long MulMod(long a, long b, long c) {
	a %= c;
	b %= c;
	if (a > b) {
		long t = a; a = b; b = t;
	}
	return MulMod1(a, b, c);
}

int main() {

	char a[10];
	char b[10];
	cin >> a;
	cin >> b;

	char * c = Add(a, b);

	PrintADD(c);


	return 0;
}

