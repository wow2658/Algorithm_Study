#include <iostream>
using namespace std;

// 길이가 i이고 마지막 숫자가 j인 계단 수
long long d[101][10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	// 길이가 1인 계단 수는 1부터 9까지 각각 1개
	for (int i = 1; i <= 9; ++i) d[1][i] = 1;

	// 길이가 2부터 n까지의 계단 수를 계산
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 0; k <= 9; ++k)
		{
			// k가 0이 아니면 k-1에서 올 수 있음
			if (k != 0) d[i][k] += d[i - 1][k - 1];
			// k가 9가 아니면 k+1에서 올 수 있음
			if (k != 9) d[i][k] += d[i - 1][k + 1];
			d[i][k] %= 1000000000;
		}
	}
	long long ans = 0;
	// 길이가 n인 모든 계단 수의 개수를 더함
	for (int i = 0; i <= 9; ++i)
	{
		ans += d[n][i];
	}
	// 최종 결과도 1,000,000,000으로 나눈 나머지를 저장
	ans %= 1000000000;
	cout << ans;
}

/*
	마지막 숫자가 0이면 그 앞자리 숫자는 1
	마지막 숫자가 1이면 그 앞자리 숫자는 0 또는 2
	마지막 숫자가 2이면 그 앞자리 숫자는 1 또는 3
	...
*/