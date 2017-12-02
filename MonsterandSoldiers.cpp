// MonsterandSoldiers.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
double dp[100050][6][32];//moves location status
double sum;
int main()
{
	long long i, j, k, n, m, p,sum1;
	memset(dp, 0, sizeof(dp));
	dp[0][3][4] = 1;
	n = 100050; sum = 0.0; 
	for (i = 1; i < n; i++) {
		for (j = 1; j < 6; j++)
			for (k = 1; k < 32; k++) {
				if (j != 1)
					dp[i][(j + 6 - 1) % 6][k|(1<<(j-2))] += 0.5*dp[i - 1][j][k];
				else
					dp[i][0][k]+= 0.5*dp[i - 1][j][k];
					if (j != 5)
						dp[i][(j + 6 + 1) % 6][k | (1 << j)] += 0.5*dp[i - 1][j][k];
					else
						dp[i][0][k] += 0.5*dp[i - 1][5][k];
				}
		sum += dp[i][0][31];
	//cout << fixed <<setprecision(6)<<dp[i][0][31] << endl;
		}
	cout << fixed << setprecision(6) <<sum<< endl;
	memset(dp, 0, sizeof(dp));
	dp[0][2][2] = 1;
	n = 100050; sum = 0.0;
	for (i = 1; i < n; i++) {
		for (j = 1; j < 6; j++)
			for (k = 1; k < 32; k++) {
				if (j != 1)
					dp[i][(j + 6 - 1) % 6][k | (1 << (j - 2))] += 0.5*dp[i - 1][j][k];
				else
					dp[i][0][k] += 0.5*dp[i - 1][j][k];
				if (j != 5)
					dp[i][(j + 6 + 1) % 6][k | (1 << j)] += 0.5*dp[i - 1][j][k];
				else
					dp[i][0][k] += 0.5*dp[i - 1][5][k];
			}
		sum += dp[i][0][31];
	//	cout << fixed <<setprecision(6)<<dp[i][0][31] << endl;
	}
	cout << fixed << setprecision(6) << sum << endl;
	return 0;
}

