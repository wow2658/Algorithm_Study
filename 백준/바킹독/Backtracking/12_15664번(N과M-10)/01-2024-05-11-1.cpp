#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int num[10];

// isused -> 고를때 같은거 중복해서 골라도 되는지? 이번 문제는 가능해서 isused 안씀
// st -> 비내림차순 요구해서 씀
// tmp -> 그동안(NM9이전)은 알아서 입력값이 다른수로 제한되었으나, 이제 입력값으로 중복값도 들어올때 중복되는 수열을 여러 번 출력하지 않기 위해 사용됨

void func(int k, int st)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}


	int tmp = 0;
	for (int i = st; i < n; ++i)
	{
		if (tmp != num[i])
		{
			arr[k] = num[i];
			tmp = arr[k];
			func(k + 1, i + 1);			 // 다음 st는 i+1이라는 것
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	func(0, 0);							 // 아예 st를 인자로 넘겨서 쓰는 방법 
}