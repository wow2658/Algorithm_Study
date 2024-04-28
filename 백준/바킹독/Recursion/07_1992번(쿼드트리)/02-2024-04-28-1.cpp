#include <iostream>

using namespace std;

int n;
int arr[65][65];

void solve(int r, int c, int n)
{
	if (n == 1)
	{
		cout << arr[r][c];
		return;
	}

	bool zero = true, one = true;

	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (arr[i][j]) zero = false;
			else one = false;
		}
	}

	if (zero) cout << 0;
	else if (one) cout << 1;
	else
	{
		cout << "(";
		solve(r, c, n / 2);
		solve(r, c + n / 2, n / 2);
		solve(r + n / 2, c, n / 2);
		solve(r + n / 2, c + n / 2, n / 2);
		cout << ")";
	}
	return;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}
	solve(0, 0, n);
}

//str2차원에담기
//n==1base
//스타팅포인트에서싹돌면서false끄는검증하기
//true편들기
//"("혼종일때4경우")" 
//끝내기