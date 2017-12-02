// uva11270.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long f[2][1040];
int main()
{
	long long i, j, k, n, m, p, curr;
	while (scanf("%lld%lld", &n, &m) != EOF) {
		if (n < m) {
			k = n;
			n = m;
			m = k;
		}
		curr = 0;
		memset(f, 0, sizeof(f));
		f[curr][(1 << m) - 1] = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				curr ^= 1;
				memset(f[curr], 0, sizeof(f[curr]));
				for (k = 0; k < (1 << m); k++) {
					if (j!=0 && !(k&(1 << (j - 1))) && (k&(1 << j))) {
						f[curr][k | (1 << (j - 1))] += f[curr ^ 1][k];
					}
					f[curr][k ^ (1 << j)] += f[curr ^ 1][k];
				}
			}
		}
		printf("%lld\n", f[curr][(1 << m) - 1]);
	}
    return 0;
}


