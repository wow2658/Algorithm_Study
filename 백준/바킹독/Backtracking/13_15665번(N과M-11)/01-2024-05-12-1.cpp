#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[10];
int num[10];

// isused -> 고를때 같은거 중복해서 골라도 되는지? 이번 문제도 가능해서 isused 안씀
// st -> 비내림차순 요구x 안씀
// tmp -> 입력값으로 중복값이 들어올 수 있으나 tmp를 안쓰고 chk와 idx를 쓴다.

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[k] = i;
		func(k + 1);
	}
}

vector<bool> chk(10002);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int idx = 0; // 수를 삽입할 인덱스. tmp대신에 중복된 수를 제거해주는 역할.
	while (n--)
	{
		cin >> num[idx];
		if (chk[num[idx]]) continue; // 이미 이전에 수가 들어온 경우 넘어감
		chk[num[idx]] = true; // 그렇지 않은 경우 수를 num 배열에 추가
		idx++;
	}
	// 현재 num에는 중복되지 않은 수들만 들어가있고 길이는 idx.
	n = idx; // 이전 문제들과 비슷한 표현을 사용하기 위해 n = idx로 둠.
	sort(num, num + n);
	// 시작할때부터 num 재료 다 완성해놓고 편하게 시작하는 느낌
	func(0);
}