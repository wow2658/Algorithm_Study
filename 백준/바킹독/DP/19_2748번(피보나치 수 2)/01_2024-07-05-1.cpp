﻿#include <iostream>
using namespace std;
using ll = long long;
ll d[95];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    cout << d[n];

}
