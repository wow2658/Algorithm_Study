#include <iostream>
#include <Algorithm>
#include <set>

using namespace std;

int n;  // 학생의 수
pair<int, int> a[500005];  // 학생의 키와 최소 등수를 저장할 배열

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;  // 학생의 수 입력

	// 각 학생의 키와 최소 등수를 입력받음
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	// 키를 기준으로 내림차순 정렬 (키가 큰 학생부터 처리하기 위함)
	sort(a, a + n, greater<pair<int, int>>());

	multiset<int> s;  // 팀원 수를 저장할 멀티셋 (중복 허용)

	// 각 학생을 순회
	for (int i = 0; i < n; i++)
	{
		// 학생의 최소 등수를 만족시키기 위해 현재 학생을 추가할 팀을 찾음
		// 음수를 사용해야 실제 팀원 수를 뜻하는 양수와 충돌이 일어나지 않는다. 그래서 아예 다른 차원을 써버리는 것이다.
		// 원래는 양수영역에서 (최소등수-1)명 "이하"를 찾아야한다.
		// 반대인 음수역역에서는 "이상"을 찾는게 맞으므로 lower_bound가 사용되었다. 근데 어차피 이하를 나타내는 어떤 lower_bound의 반대격인 함수가 없다.
		// 1 2 4 4 5 vs -5 -4 -4 "-2" -1 
		// lower_bound(-3) = -2

		auto it = s.lower_bound(-a[i].second + 1);

		// 적절한 팀이 없다면 새 팀을 만듦
		if (it == s.end()) s.insert(-1);
		else
		{
			// *it는 auto가 사실은 std::multiset<int>::iterator여서 사용하는 것
			int val = *it;     // 찾은 팀의 팀원 수
			s.erase(it);       // 해당 팀을 삭제하고
			s.insert(val - 1); // 팀원 수를 감소시켜 다시 삽입
		}
	}

	// 팀의 개수를 출력
	cout << s.size();
	/*
	 팀1: [188]
	 팀2: [180, 154]
	 팀3: [172, 161]
	*/
}