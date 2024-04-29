#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;

		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);


}

//재료n 자리m 받고 결과arr isused 준비
//func0스타트 0은 재귀될때마다 증가되고 ==m됐을때 출력
//1~n모든재료돌면서 안쓴거만 결과에넣고 썼다고 1체크 자리수올려서재귀, 나중에 탈출했을때 0반환