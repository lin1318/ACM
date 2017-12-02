// hdu5115.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
long long dp[205][205];
long long a[205], b[205];
using namespace std;
int main()
{
	long long i, j, k, m, p,n,t,ans,q,l;
	cin >> t;
	p = 0;
	while (t--) {
		p++;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (i = 1; i <= n; i++)
			cin >> a[i];
		for (i = 1; i <= n; i++)
			cin >> b[i];
		memset(dp, 0x3f, sizeof(dp));
		for (i = 1; i <= n; i++)
			dp[i][i] = a[i] + b[i - 1] + b[i + 1];
		for (j = 2; j <= n; j++)
		{
			for (i = 1; i <= n - j + 1; i++)
			{
				k = i + j - 1;
				dp[i][k] = min(dp[i + 1][k] + a[i] + b[i - 1] + b[k + 1], dp[i][k - 1] + a[k] + b[k + 1] + b[i - 1]);
				for (l = i + 1; l<k; l++)
					dp[i][k] = min(dp[i][k], dp[i][l - 1] + dp[l + 1][k] + a[l] + b[i - 1] + b[k + 1]);
			}

		}
		cout << "Case #"<<p<<": "<< dp[1][n]<< endl;
	}
    return 0;
} 


