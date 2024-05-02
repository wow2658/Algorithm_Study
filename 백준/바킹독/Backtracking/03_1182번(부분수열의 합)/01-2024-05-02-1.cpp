#include <iostream>

using namespace std;

int arr[21];
int cnt, n, s;

void func(int cur, int tot)
{
	if (cur == n)
	{
		if (tot == s)
		{
			cnt++;
		}
		return; // 디버깅으로 잡아낸곳. 이걸 저위의 tot==s 괄호안에 넣으면 stackoverflow가 발생하니 생각 잘하기.
	}

	func(cur + 1, tot + 0);
	func(cur + 1, tot + arr[cur]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; // 공집합 빼기
	cout << cnt;
}
