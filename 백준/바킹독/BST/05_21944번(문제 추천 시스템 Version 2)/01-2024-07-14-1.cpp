#include <iostream>
#include <set>
#include <tuple>
using namespace std;

string op;
int N, L, P, G, x;

// 문제 번호를 키로 사용하여 (난이도, 분류)를 저장하는 배열
// 예: probLevel[1] = {3, 2} -> 문제 1의 난이도는 3, 분류는 2
pair<int, int> probLevel[100'002];

// 난이도별로 문제 번호를 저장하는 set 배열
// 예: probByL[3] = {1, 2, 5} -> 난이도 3인 문제 번호들
set<int> probByL[102];

// (분류, 난이도)별로 문제 번호를 저장하는 2차원 set 배열
// 예: probByGL[2][3] = {1, 4} -> 분류 2, 난이도 3인 문제 번호들
set<int> probByGL[102][102];


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 초기 문제 목록 입력
    cin >> N;
    while (N--)
    {
        cin >> P >> L >> G;
        // 문제 정보를 각 자료구조에 저장
        probLevel[P] = { L, G };   // 문제 번호에 대한 난이도와 분류 정보 저장
        probByL[L].insert(P);      // 난이도별 문제 번호 저장
        probByGL[G][L].insert(P);  // (분류, 난이도)별 문제 번호 저장
    }

    // 명령어 수 입력
    cin >> N;
    while (N--)
    {
        cin >> op;
        if (op == "recommend")
        {
            cin >> G >> x;
            if (x == 1)
            {
                // 가장 어려운 문제 찾기 (난이도가 높은 순서대로 검사)
                for (int i = 100; i >= 0; i--)
                {
                    if (probByGL[G][i].empty()) continue;  // 해당 난이도에 문제가 없으면 다음 난이도로
                    // 해당 난이도의 가장 큰 문제 번호 출력
                    cout << *(prev(probByGL[G][i].end())) << '\n';
                    break;
                }
            }
            else
            {
                // 가장 쉬운 문제 찾기 (난이도가 낮은 순서대로 검사)
                for (int i = 0; i < 101; i++)
                {
                    if (probByGL[G][i].empty()) continue;  // 해당 난이도에 문제가 없으면 다음 난이도로
                    // 해당 난이도의 가장 작은 문제 번호 출력
                    cout << *probByGL[G][i].begin() << '\n';
                    break;
                }
            }
        }
        else if (op == "recommend2")
        {
            cin >> x;
            if (x == 1)
            {
                // 분류 상관없이 가장 어려운 문제 찾기 (난이도가 높은 순서대로 검사)
                for (int i = 100; i >= 0; i--)
                {
                    if (probByL[i].empty()) continue;  // 해당 난이도에 문제가 없으면 다음 난이도로
                    // 해당 난이도의 가장 큰 문제 번호 출력
                    cout << *(prev(probByL[i].end())) << '\n';
                    break;
                }
            }
            else
            {
                // 분류 상관없이 가장 쉬운 문제 찾기 (난이도가 낮은 순서대로 검사)
                for (int i = 0; i < 101; i++)
                {
                    if (probByL[i].empty()) continue;  // 해당 난이도에 문제가 없으면 다음 난이도로
                    // 해당 난이도의 가장 작은 문제 번호 출력
                    cout << *probByL[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (op == "recommend3")
        {
            cin >> x >> L;
            int ans = -1;  // 조건을 만족하는 문제가 없을 경우 -1 출력
            if (x == 1)
            {
                // L 이상 난이도 중 가장 쉬운 문제 찾기
                for (int i = L; i < 101; i++)
                {
                    if (probByL[i].empty()) continue;  // 해당 난이도에 문제가 없으면 다음 난이도로
                    ans = *probByL[i].begin();         // 해당 난이도의 가장 작은 문제 번호 선택
                    break;
                }
            }
            else
            {
                // L 미만 난이도 중 가장 어려운 문제 찾기
                for (int i = L - 1; i >= 0; i--)
                {
                    if (probByL[i].empty()) continue;  // 해당 난이도에 문제가 없으면 이전 난이도로
                    ans = *(prev(probByL[i].end()));   // 해당 난이도의 가장 큰 문제 번호 선택
                    break;
                }
            }
            cout << ans << '\n';  // 찾은 문제 번호 또는 -1 출력
        }
        else if (op == "add")
        {
            // 새 문제 추가
            cin >> P >> L >> G;
            probLevel[P] = { L, G };   // 문제 정보 저장
            probByL[L].insert(P);      // 난이도별 문제 목록에 추가
            probByGL[G][L].insert(P);  // (분류, 난이도)별 문제 목록에 추가
        }
        else if (op == "solved")
        {
            // 해결한 문제 제거
            cin >> P;
            tie(L, G) = probLevel[P];  // 문제의 난이도와 분류 정보 가져오기
            probByL[L].erase(P);       // 난이도별 문제 목록에서 제거
            probByGL[G][L].erase(P);   // (분류, 난이도)별 문제 목록에서 제거
        }
    }
}