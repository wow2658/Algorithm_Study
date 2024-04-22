#include <iostream>
#include <algorithm>

using namespace std;

int n, m; //재료 자리
int arr[10];
bool isused[10];

void func(int k)
{
	if (k == m) // 자리 다찼나
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	// 할 일 하자
	for (int i = 1; i <= n; i++) // 재료돌자
	{
		if (!isused[i])			 // false 안쓴거만
		{
			arr[k] = i;			 // 이번 자리에 재료 넣고
			isused[i] = 1;       // 그 재료 썼다고 체크
			func(k + 1);         // 다음 자리수 가는데, k==m하고 return하면 여기로 복귀다.
			isused[i] = 0;       // 다음 경우의 수 써야하니까 없던일로 되돌아가듯이
		}					     // 물론 바로 다음으로는 어차피 i가 +1로 지나가서 당장은 안쓰지만
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);


}
