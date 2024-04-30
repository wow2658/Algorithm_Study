#include <iostream>


using namespace std;

bool isused1[40]; //  |  (왜 크기가 40이지?) 14+13?
bool isused2[40]; //  /
bool isused3[40]; //  \

int cnt, n;

void func(int cur) // cur번째 말 을 놓는다
{
	if (cur == n)  // 조건인 n번째까지 개수 채웠다면 (n과m에서 k==m 같네)
	{
		cnt++;     // 여기까지 도달한거면 경우의 수 하나 적립
		return;
	}

	for (int i = 0; i < n; i++)				// i가 열이고 cur이 행 (cur, i)
	{
		if (isused1[i]                      // 열인 i가 같으면 같은 세로선상이다.
			|| isused2[i + cur]             // 열행의 합이 같으면 같은 우상향선상이다.
			|| isused3[cur - i + n - 1])    // 열행의 차가 같으면 같은 우하향선상이다. 배열의 인덱스가 음수일수는 없으니까 한바퀴 돌리는 보상을 해주자. 0 -> n(안되지만 n-1이해하기 위해서, stl의 허공 end생각), -1 -> n-1(끝자락)
			continue;

		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;

		func(cur + 1); // n과m문제랑 역시 닮았다.

		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;	 // 체스판의 크기와 동시에 퀸 몇개 놓을건지 정함
	func(0);
	cout << cnt; // 방법의 수 출력

}
