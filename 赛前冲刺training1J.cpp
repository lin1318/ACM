// 赛前冲刺training1J.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b) {
		if (max(a, b) == 0)
			cout << "Not a moose" << endl;
		else
		{
			if (a == b)
				cout << "Even " << a + b << endl;
			else
				cout << "Odd " << 2 * max(a, b) << endl;
		}
	}
    return 0;
}

