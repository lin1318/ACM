// 赛前冲刺training1B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
struct people {
	string name;
	double fi, ot;
	bool operator<(people fuck) {
		return ot < fuck.ot;
	}
}a[1000];
people fin[1000],tr[1000];
int main()
{
	int i, j, k, n;
	double sum,ans;
	while (cin >> n) {
		for (i = 0; i < n; i++)
			cin >> a[i].name >> a[i].fi >> a[i].ot;
		sort(a, a + n);
		ans = 0x7fffff;
		for (i = 0; i < n; i++)
		{
			sum = 0.0;
			sum += a[i].fi;
			k = 1;
			tr[k] = a[i];
			for (j = 0; j < n; j++) {
				if (j != i) {
					k++;
					sum += a[j].ot;
					tr[k] = a[j];
				}
				if (k == 4)
					break;
			}
			if (sum<ans) {
				ans = sum;
				for (j= 1; j <= 4; j++)
					fin[j] = tr[j];
			}
		}
		cout << fixed << setprecision(9) << ans << endl;
		for (i = 1; i <= 4; i++)
			cout << fin[i].name << endl;
	}
    return 0;
}

