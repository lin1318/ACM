// ProjectEuler250.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
const long long mod = 1e16;
long long dp[300][2];
long long a[250300];
long long quick_pow(long long n, long long k,long long m) {
	long long ans = 1;
	while (k > 0) {
		if (k%2==1)
			ans = ans*n%m;
		n = n * n%m;
		k = k / 2;
	}
	return ans;
}
int main()
{
	long long i, j, k, n, m;
	long long ans=0;
	long long curr;
	memset(a, 0, sizeof(a));
	for (i = 1; i <=250250; i++)
		a[i] = quick_pow(i, i, 250);
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	curr = 0;
	for (i =1;i <=250250; i++) {
		curr = 1 - curr;
		for (j = 0; j < 250; j++) {
			dp[j][curr] = (dp[j][1-curr] + dp[(j + a[i]) % 250][1-curr]) % mod;
		}
	}
	cout << dp[0][0]-1<< endl;
    return 0;
}

