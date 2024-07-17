#include <iostream>
#include <set>

using namespace std;
using ll = long long;

int h[250005];   // 각 노드의 높이를 저장하는 배열
set<int> s;      // 정렬된 노드 값을 저장하는 set
ll res;          // 높이의 합을 저장하는 변수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;                // 트리의 노드 개수를 입력받음
	h[0] = 0; s.insert(0);          // 트리의 경계 처리를 위해 0을 삽입
	h[n + 1] = 0; s.insert(n + 1);  // 트리의 경계 처리를 위해 n+1을 삽입

	n--;                     // 루트 노드를 제외한 나머지 노드 개수

	int a; cin >> a; a++;    // 첫 번째 노드를 1-based index로 처리하기 위해 +1을 함 
	// ex) {0, 11}이 경계값이고 0-base의 크기가 10일때 받을 수 있는 제일 큰 수는 9인데 이것을 ++안하고 넣으면 {0,9,11} 로 10이 비어버리기 때문에 최대한 활용 해야한다. 게다가 0을 받으면 경계값에 씹힌다.

	h[a] = 1; s.insert(a);   // 루트 노드의 높이는 1로 설정하고 set에 삽입
	res = 1;                 // 높이의 합에 루트 노드의 높이를 더함

	while (n--)
	{
		// 남은 노드들을 처리
		cin >> a; a++;              // 각 노드를 입력받고 +1을 함 (1부터 N 사이로)
		auto it = s.lower_bound(a); // 노드의 위치를 찾기 위해 set에서 lower_bound 사용
		// a의 높이는 a보다 작은 수들 중 최댓값과 a보다 큰 수들 중 최솟값의 높이 중 큰 값에 +1
		h[a] = max(h[*prev(it)], h[*it]) + 1;
		s.insert(a);         // 현재 노드를 set에 삽입
		res += h[a];         // 높이의 합에 현재 노드의 높이를 더함
	}

	cout << res;             // 최종 높이의 합을 출력
}

#if 0

초기화

int n;
cin >> n;  // n = 10
h[0] = 0;
s.insert(0);  // s = {0}
h[n + 1] = 0;
s.insert(n + 1);  // s = {0, 11}



첫 번째 노드 (root)

n--;  // n = 9
int a;
cin >> a;  // a = 9
a++;  // a = 10
h[a] = 1;
s.insert(a);  // s = {0, 10, 11}
res = 1;  // res = 1


두 번째 노드

cin >> a;  // a = 1
a++;  // a = 2
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[2] = max(h[0], h[10]) + 1 = 2
s.insert(a);  // s = {0, 2, 10, 11}
res += h[a];  // res = 3


세 번째 노드

cin >> a;  // a = 4
a++;  // a = 5
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[5] = max(h[2], h[10]) + 1 = 3
s.insert(a);  // s = {0, 2, 5, 10, 11}
res += h[a];  // res = 6


네 번째 노드

cin >> a;  // a = 3
a++;  // a = 4
auto it = s.lower_bound(a);  // it points to 5
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[4] = max(h[2], h[5]) + 1 = 4
s.insert(a);  // s = {0, 2, 4, 5, 10, 11}
res += h[a];  // res = 10


다섯 번째 노드

cin >> a;  // a = 2
a++;  // a = 3
auto it = s.lower_bound(a);  // it points to 4
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[3] = max(h[2], h[4]) + 1 = 5
s.insert(a);  // s = {0, 2, 3, 4, 5, 10, 11}
res += h[a];  // res = 15


여섯 번째 노드

cin >> a;  // a = 5
a++;  // a = 6
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[6] = max(h[5], h[10]) + 1 = 4
s.insert(a);  // s = {0, 2, 3, 4, 5, 6, 10, 11}
res += h[a];  // res = 19


일곱 번째 노드

cin >> a;  // a = 6
a++;  // a = 7
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[7] = max(h[6], h[10]) + 1 = 5
s.insert(a);  // s = {0, 2, 3, 4, 5, 6, 7, 10, 11}
res += h[a];  // res = 24

여덟 번째 노드

cin >> a;  // a = 7
a++;  // a = 8
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[8] = max(h[7], h[10]) + 1 = 6
s.insert(a);  // s = {0, 2, 3, 4, 5, 6, 7, 8, 10, 11}
res += h[a];  // res = 30


아홉 번째 노드

cin >> a;  // a = 8
a++;  // a = 9
auto it = s.lower_bound(a);  // it points to 10
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[9] = max(h[8], h[10]) + 1 = 7
s.insert(a);  // s = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
res += h[a];  // res = 37


마지막 노드

cin >> a;  // a = 0
a++;  // a = 1
auto it = s.lower_bound(a);  // it points to 2
h[a] = max(h[*prev(it)], h[*it]) + 1;  // h[1] = max(h[0], h[2]) + 1 = 3
s.insert(a);  // s = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
res += h[a];  // res = 40


#endif