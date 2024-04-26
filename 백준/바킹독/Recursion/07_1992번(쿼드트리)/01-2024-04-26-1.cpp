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
			if (arr[i][j] == true)
				zero = false;
			else if (arr[i][j] == false)
				one = false;
		}
	}
	// 결과 경우의 수 : 
	//		1. arr 모두 1 일때	-> zero = false,	one = true
	//		2. arr 모두 0 일때	-> zero = true,		one = false
	//      3. arr이 혼종일때		-> zero = false,	one = false

// 일단 혼종이 아니었으면 압축 성공
	if (zero == true)
		cout << 0; // 2번의 경우
	else if (one == true)
		cout << 1; // 1번의 경우

	// 혼종이었어서 압축이 안된다면 쪼개기
	else           // 3번의 경우
	{
		cout << "(";						// n은 2의 제곱수, 반으로 잘라서 036느낌으로 0-1 2-3
		solve(r, c, n / 2);					// 처음 기준 왼쪽위
		solve(r, c + n / 2, n / 2);			// c로 더하니 오른쪽위
		solve(r + n / 2, c, n / 2);			// r로 더하니 왼쪽아래
		solve(r + n / 2, c + n / 2, n / 2);	// r,c 둘다 진출 오른쪽 아래
		cout << ")";
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	//따닥따닥붙은 입력을 string으로 받아서 char배열이 아니라 int배열에 넣는방법
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