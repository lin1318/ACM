// 赛前冲刺training2H.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct node {
	long long x, y, l, fr;
};
vector<node> a;
char map[20][20];
int tag[20][20];
int dis[20][20];
const int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
long long n, m;
void dfs(int x, int y, int k) {
	int x1, y1,i;
	for (i = 0; i < 4; i++) {
		x1 = x + dir[i][0];
		y1 = y + dir[i][1];
		if (x1 > 0 && x1 <= n&&y1 > 0 && y1 <= m&&map[x1][y1] == 'X')
		{
			tag[x1][y1] = k;
			dfs(x1, y1, k);
		}
	}
}
int main()
{
	long long i, j, k, p, sn,l;
	node x;
	while (cin >> n >> m) {
		a.clear();
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				cin >> map[i][j];
		memset(tag, 0, sizeof(tag));
		l = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if ((map[i][j] == 'X') && (tag[i][j] == 0)) {
					l++;
					tag[i][j] = l;
					dfs(i, j, l);
				}
		memset(dis, 0, sizeof(dis));
		sn = 0;
		for (i = 1; i <= n; i++) {
			x.x = i; x.y = 1; x.l = 1;
			x.fr = 0; a.push_back(x);
			dis[i][1] = 1;
			x.x = i; x.y = m; x.l = 1;
			dis[i][m] = 1;
			x.fr = 0; a.push_back(x);
			sn += 2;
	  }
		for (i = 2; i <= m-1; i++) {
			x.x = 1; x.y = i; x.l = 1;
			x.fr = 0; a.push_back(x);
			dis[1][i] = 1;
			x.x = n; x.y =i; x.l = 1;
			x.fr = 0; a.push_back(x);
			sn += 2;
			dis[n][i] = 1;
		}
		p = 0;
		while (p < sn) {

		}
	}
    return 0;
}

