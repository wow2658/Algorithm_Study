#include <bits/stdc++.h>
using namespace std;

int func(int N, int r, int c)
{
	if (N == 0) return 0;
	int half = 1 << (N - 1);
	if (r < half && c < half) return func(N - 1, r, c);
	else if (r < half && c >= half) return half * half + func(N - 1, r, c - half);
	else if (r >= half && c < half) return half * half * 2 + func(N - 1, r - half, c);
	else if (r >= half && c >= half) return half * half * 3 + func(N - 1, r - half, c - half);

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;

	func(N, r, c);
	cout << func(N, r, c);
}