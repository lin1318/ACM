// CodeForces848B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct person{
	long long l, t, id;
	bool operator<(const person &x) {
		if (l-t == x.l-x.t)
			return l < x.l;
		return l-t< x.l-x.t;
	}
}x[100050],y[100050];
struct coordinate {
	long long x, y;
}ans[100050];
int main()
{
	long long i, j, k, n, m, w, h,g,l0,l1,ptr0,ptr1,p0,p1;
	person kk;
	while (scanf("%lld%lld%lld",&n,&w,&h)!=EOF) {
		l0 = 0; l1 = 0;
		for (i = 0; i < n; i++)
		{
			cin >> g >>kk.l >> kk.t;
			kk.id = i;
			if (g == 1) {
				l0++;
				x[l0] = kk;
			}
			else
			{
				l1++;
				y[l1] = kk;
			}
		}
		sort(x + 1, x + l0 + 1);
		sort(y + 1, y + l1 + 1);
		ptr0 = 1; ptr1 = 1;
		while ((ptr0 <= l0)&&(ptr1 <= l1)) {
			if(x[ptr0].l - x[ptr0].t == y[ptr1].l - y[ptr1].t)
			{
				p0 = ptr0;
				p1 = ptr1;
				while (x[p0].l - x[p0].t == y[p1].l - y[p1].t&&p1 <l1)
					p1++;
				while (x[p0].l - x[p0].t == y[ptr1].l - y[ptr1].t&&p0 <l0)
					p0++;
				if (y[p1].l - y[p1].t != y[ptr1].l - y[ptr1].t)
					p1--;
				if (x[p0].l - x[p0].t != y[ptr1].l-y[ptr1].t)
					p0--;
				if (p0 - ptr0<=p1 - ptr1) {
					i = ptr0; j = ptr1+(p0 - ptr0);
					while (j >=ptr1&&i<=p0) {
						ans[x[i].id].x = w;
						ans[x[i].id].y = y[j].l;
						j--; i++;
					}
					i = ptr1; j = 0;
					while (j<p1-ptr1-(p0-ptr0)) {
						ans[y[i].id].x = w;
						ans[y[i].id].y = y[ptr1+(p0-ptr0)+1+j].l;
						i++;
						j++;
					}
					i = p1; j = 0;
					while (j <= p0 - ptr0) {
						ans[y[i].id].x = x[j + ptr0].l;
						ans[y[i].id].y = h;
						i--; j++;
					}
				}
				else {
					j = p0 - ptr0 - (p1 - ptr1);
					i = 0;
					while (i<j) {
						ans[x[i + ptr0].id].x= x[p0-j + i + 1].l;
						ans[x[i + ptr0].id].y = h;
						i++;
					}
					i = 0;
					while (i<=p1-ptr1) {
						ans[y[p1 - i].id].y = h;
						ans[y[p1 - i].id].x = x[ptr0+i].l;
						i++;
					}
					i = 0;
					while (i<=p1 - ptr1) {
						ans[x[ptr0+j+ i].id].x = w;
						ans[x[ptr0+j + i].id].y = y[p1 - i].l;
						i++;
					}
				}
				ptr0 = p0+1;
				ptr1 = p1+1;
				continue;
			}
			if (ptr0 > l0 || ptr1 > l1)
				break;
			if (x[ptr0].l - x[ptr0].t < y[ptr1].l - y[ptr1].t) {
				ans[x[ptr0].id].x = x[ptr0].l;
				ans[x[ptr0].id].y = h;
				ptr0++;
			}
			else
				if (x[ptr0].l - x[ptr0].t > y[ptr1].l - y[ptr1].t) {
					ans[y[ptr1].id].x = w;
					ans[y[ptr1].id].y = y[ptr1].l;
					ptr1++;
				}
		}
		for (i = ptr0; i <=l0; i++)
		{
			ans[x[i].id].x = x[i].l;
			ans[x[i].id].y = h;
		}
		for (i = ptr1; i <=l1; i++)
		{
			ans[y[i].id].x = w;
			ans[y[i].id].y = y[i].l;
		}
		for (i = 0; i < n; i++)
		{
			printf("%lld %lld\n", ans[i].x, ans[i].y);
		}
	}
    return 0;
}