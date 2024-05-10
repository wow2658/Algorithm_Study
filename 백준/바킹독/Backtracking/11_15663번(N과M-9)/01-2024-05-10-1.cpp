#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';       // 껍데기 씌워서 출력하는게 아니라 애초부터 둔갑해서 기입. 그래야 미리 중복을 필터링하니까.  
		cout << '\n';
		return;
	}


	int tmp = 0;						 // N개의 자연수는 모두 다른 수인 조건 삭제
	for (int i = 0; i < n; ++i)
	{
		if (!isused[i] && tmp != num[i]) // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
		{

			isused[i] = true;
			arr[k] = num[i];			 // 이건 늘 하던 완성해가는 행위
			tmp = arr[k];				 // k+1자리수로 들어가기전에 저장한 k번째열의 숫자. 즉, 마지막 항을 기억하는 것
			func(k + 1);
			isused[i] = false;
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
	func(0);
}