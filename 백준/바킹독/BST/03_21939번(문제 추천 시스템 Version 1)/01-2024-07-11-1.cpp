#include <iostream>
#include <set>

using namespace std;

// 명령어 문자열
string op;
int N, L, P, x;

// 문제 번호와 난이도를 저장하는 배열
int probLevel[100'002];     // probLevel[P]는 문제 번호 P의 난이도를 저장

// 난이도별로 문제 번호를 저장하는 set
set<int> probByLevel[102];  // probByLevel[L]은 난이도 L에 속한 문제 번호들을 저장

// 만약 스위치문으로 푼다면
int getCommandCode(const string& command)
{
	if (command == "recommend") return 1;
	if (command == "add") return 2;
	if (command == "solved") return 3;
	return -1;  // 알 수 없는 명령어인 경우
}

int main(void)
{
	ios::sync_with_stdio(0); // 입출력 속도를 높이기 위해 사용
	cin.tie(0);              // cin과 cout의 묶음을 풀어서 속도를 높임

	// 초기 문제 리스트를 입력받음
	cin >> N;
	while (N--)
	{
		cin >> P >> L;
		probLevel[P] = L;		  // 문제 번호 P의 난이도를 L로 저장
		probByLevel[L].insert(P); // 난이도 L의 문제 리스트에 문제 번호 P를 추가
	}

	// 명령어 개수를 입력받음
	cin >> N;
	while (N--)
	{
#if 0
		cin >> op; // 명령어를 입력받음
		if (op == "recommend")
		{
			cin >> x;
			if (x == 1)
			{
				// 가장 어려운 문제를 추천하는 경우
				for (int i = 100; 0 <= i; i--)
				{
					if (probByLevel[i].empty()) continue;
					// 난이도 i에서 가장 큰 문제 번호를 출력
					cout << *(prev(probByLevel[i].end())) << '\n';
					break;
				}
			}
			else {
				// 가장 쉬운 문제를 추천하는 경우
				for (int i = 0; i < 101; i++)
				{
					if (probByLevel[i].empty()) continue;
					// 난이도 i에서 가장 작은 문제 번호를 출력
					cout << *probByLevel[i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "add")
		{
			// 문제를 추가하는 경우
			cin >> P >> L;
			probLevel[P] = L;         // 문제 번호 P의 난이도를 L로 저장
			probByLevel[L].insert(P); // 난이도 L의 문제 리스트에 문제 번호 P를 추가
		}
		else if (op == "solved")
		{
			// 문제를 제거하는 경우
			cin >> P;
			probByLevel[probLevel[P]].erase(P); // 난이도 probLevel[P]에서 문제 번호 P를 제거
		}

#else
		int commandCode = getCommandCode(op);
		switch (commandCode)
		{
		case 1: // recommend
			cin >> x;
			if (x == 1)
			{
				// 가장 어려운 문제를 추천하는 경우
				for (int i = 100; 0 <= i; i--)
				{
					if (probByLevel[i].empty()) continue;
					// 난이도 i에서 가장 큰 문제 번호를 출력
					cout << *(prev(probByLevel[i].end())) << '\n';
					break;
				}
			}
			else {
				// 가장 쉬운 문제를 추천하는 경우
				for (int i = 0; i < 101; i++)
				{
					if (probByLevel[i].empty()) continue;
					// 난이도 i에서 가장 작은 문제 번호를 출력
					cout << *probByLevel[i].begin() << '\n';
					break;
				}
			}
			break;

		case 2: // add
			cin >> P >> L;
			probLevel[P] = L;         // 문제 번호 P의 난이도를 L로 저장
			probByLevel[L].insert(P); // 난이도 L의 문제 리스트에 문제 번호 P를 추가
			break;

		case 3: // solved
			cin >> P;
			probByLevel[probLevel[P]].erase(P); // 난이도 probLevel[P]에서 문제 번호 P를 제거
			break;

		default:
			// 알 수 없는 명령어인 경우 처리 (생략 가능)
			break;
		}
#endif
	}

}