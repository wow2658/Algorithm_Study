#include <iostream>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

#define X first
#define Y second

int n, k;
pair<int, int> jewel[300003]; // {X가격, Y무게}
multiset<int> bag;            // 가방의 최대 무게를 중복허용 정렬저장, 멀티셋을 사용하는 이유는 같은 무게의 가방이 여러 개 있을 수 있기 때문


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k; // N(보석 개수)와 K(가방 개수)를 입력 받음


	for (int i = 0; i < n; i++)
		cin >> jewel[i].Y >> jewel[i].X; // 정렬의 편의를 위해 Y무게, X가격을 반대로 입력받음

	// 보석 배열을 X가격Vi 기준으로 오름차순 정렬
	sort(jewel, jewel + n);

	// 각 가방의 최대 무게(Ci)를 입력받아 멀티셋에 저장
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		bag.insert(c);
	}

	long long ans = 0; // 상덕이가 훔칠 수 있는 보석의 최대 가격의 합을 저장할 변수

	/* 초기 세팅 완료 */

	// 보석 배열을 역순으로 순회하여 가장 비싼 보석부터 처리
	for (int i = n - 1; i >= 0; i--)
	{
		int m, v;
		tie(v, m) = jewel[i];           // 현재 보석의 가격과 무게를 추출해서 임시변수에 저장
		auto it = bag.lower_bound(m);   // 현재 보석의 무게를 담을 수 있는 가방을 찾음

		/*
			m보다 크거나 같은 첫 번째 원소의 반복자를 반환
			만약 m보다 크거나 같은 원소가 없다면 bag.end()를 반환

			예를 들어, 가방의 무게 제한이 {2, 3, 5, 7}일 때
			보석의 무게가 7이라면 lower_bound(7)는 7을 가리키는 반복자를 반환
			보석의 무게가 8이라면 lower_bound(8)는 bag.end()를 반환

		*/


		if (it == bag.end()) continue;  // 적절한 가방이 없으면 다음 보석으로 넘어감
		ans += v;						// 보석의 가격을 총합에 더함
		bag.erase(it);                  // 사용한 가방을 제거
	}
	cout << ans;
}