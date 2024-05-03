#include <iostream>

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
		cout << "\n";
		return;
	}

	int st = 1;						 // 맨 첫자리 수 일때는 뭐 가려낼게 없다. 어차피 막내라서
	if (k != 0) st = arr[k - 1] + 1; // 그러나 그 다음 자리수 부터는 선배만 불러와야한다. 선배는 나보다 +1인것부터 시작. 
									 // 여기에서 나는 arr[k]가 아니다. 그건 이번 회차에서 바꿀 수다. 
									 // 그전에 확실했던 arr[k-1]의 +1한게 확실한 나다. 칸으로 생각한다면, 
									 // 이번 k칸에 넣을 재료는 바로 직전 칸 수의 +1한 녀석부터 시작이라고 이해하자.

	for (int i = st; i <= n; i++)    // 쓸수 있는 재료는 선배들로 한정되어있다. 2라면 3 4
	{
		if (isused[i]) continue;
		arr[k] = i;
		isused[i] = 1;
		func(k + 1);
		isused[i] = 0;

	}


}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	func(0);

}
