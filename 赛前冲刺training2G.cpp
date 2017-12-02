// 赛前冲刺training2G.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int a[100][100];
vector<int> ans;
vector<int>::iterator it;
int main()
{
	int i, j, k, n, m,p;
	while (cin >> n >> k) {
		memset(a, sizeof(a), 0);
		for (i = 1; i <= n; i++) {
			cin >> m;
			for (j = 1; j <= m; j++) {
				cin >> p;
				a[i][p] = 1;
				a[p][i] = 1;
			}
		}
		ans.clear();
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if ((i != j) && (i != k) && (j != k)) {
					if ((a[k][j] == 1) && (a[j][i] == 1) && (a[i][k] == 0))
						ans.push_back(i);
				}
		sort(ans.begin(), ans.end());
		it=unique(ans.begin(), ans.end());
		ans.erase(it, ans.end());
		cout << ans.size() << endl;
		for (i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
    return 0;
}

