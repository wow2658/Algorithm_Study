#include <iostream>
using namespace std;

int n;
int a[1010], d[1010];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		//d[i] = a[i];
	}

	fill(d, d + n, 1); // d 배열을 1로 초기화, 각 원소 자체만으로 부분 수열을 구성한다고 가정

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[j] < a[i])
				//d[i] = max(d[i], d[j] + a[i]); 
				d[i] = max(d[i], d[j] + 1); // 누적합이 아니라 누석개수

	cout << *max_element(d, d + n);
}