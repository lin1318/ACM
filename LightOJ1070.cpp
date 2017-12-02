// LightOJ1070.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long a, b, p, q, f0, f1;
struct mat {
	unsigned long long a[2][2];
}A;
mat mul(mat &a, mat &b) {
	int i, j, k;
	mat c;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			c.a[i][j] = 0;
	for (i = 0; i<2; i++)
		for (j = 0; j<2; j++)
			for (k = 0; k < 2; k++) {
				c.a[i][j] += (a.a[i][k] * b.a[k][j]);
			}
	return c;
}
mat pow(mat a, long long n) {
	mat b;
	int i, j, k;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			b.a[i][j] = 0;
	b.a[0][0] = 1;
	b.a[1][1] = 1;
	while (n > 0) {
		if (n & 1)
			b = mul(b, a);
		n = n / 2;
		a = mul(a, a);
	}
	return b;
}
int main() {
	long long t, n, k;
	unsigned long long ans;
	cin >> t;
	k = 0;
	while (t--) {
		k++;
		cin >> p >> q >> n;
		if (p == 0 && q == 0) {
			cout << "Case " << k << ": " << 0 << endl;
			continue;
		}
		else
			if (q == 0) {
				f0 = 1;
				f1 = p;
			}
			else
			{
				f0 = 2;
				f1 = p;
			}
		if (n == 0) {
			cout << "Case " << k << ": " << f0 << endl;
			continue;
		}
		if (n == 1) {
			cout << "Case " << k << ": " << f1 << endl;
			continue;
		}
		A.a[0][0] = p; A.a[0][1] = 0ULL - q;
		A.a[1][0] = 1; A.a[1][1] = 0;
		A = pow(A, n - 1);
		ans = f1*A.a[0][0] + f0*A.a[0][1];
		cout << "Case " << k << ": " << ans << endl;
	}
}



