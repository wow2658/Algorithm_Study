#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first   // pair에서 첫 번째 요소를 의미하는 매크로
#define Y second  // pair에서 두 번째 요소를 의미하는 매크로

int board[55][55];                      // 도시 정보를 저장하는 2차원 배열
int n, m;                               // 도시 크기 n, 선택할 치킨집의 최대 개수 m
vector<pair<int, int>> chicken;          // 치킨집의 좌표를 저장하는 벡터
vector<pair<int, int>> house;            // 집의 좌표를 저장하는 벡터

int main(void)
{
    ios::sync_with_stdio(0);            // 입출력 속도 향상을 위한 설정
    cin.tie(0);                         // C++ 표준 스트림과의 동기화를 끊음

    cin >> n >> m;                      // 도시 크기 n과 최대 선택 치킨집 개수 m 입력

    for (int i = 0; i < n; i++)         // 도시 크기 n만큼 반복하여
    {
        for (int j = 0; j < n; j++)     // 각 행의 열에 대해 반복
        {
            cin >> board[i][j];         // 도시의 현재 칸 정보를 입력받음

            if (board[i][j] == 1)       // 현재 칸이 집(1)이라면
            {
                house.push_back({ i, j }); // 해당 좌표를 house 벡터에 추가
            }

            if (board[i][j] == 2)       // 현재 칸이 치킨집(2)이라면
            {
                chicken.push_back({ i, j }); // 해당 좌표를 chicken 벡터에 추가
            }
        }
    }

    vector<int> brute(chicken.size(), 1); // 치킨집 선택 여부를 나타내는 벡터 생성 (모든 값을 1로 초기화)
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 앞쪽부터 chicken.size() - m개까지 0으로 설정, 뒤쪽 m개는 1로 유지

    int mn = 0x7f7f7f7f;                 // 도시의 최소 치킨 거리를 저장할 변수, 매우 큰 값으로 초기화

    do
    {
        int dist = 0;                    // 현재 선택한 치킨집 조합의 도시 치킨 거리를 저장할 변수

        for (auto h : house)             // 모든 집에 대해 반복
        {
            int tmp = 0x7f7f7f7f;        // 현재 집의 치킨 거리를 저장할 변수, 매우 큰 값으로 초기화

            for (int i = 0; i < chicken.size(); i++)  // 모든 치킨집에 대해 반복
            {
                if (brute[i] == 0)       // 해당 치킨집이 선택되지 않았다면
                {
                    continue;            // 다음 치킨집으로 건너뜀
                }

                int dist_to_chicken = abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y); // 현재 집과 선택된 치킨집 간의 거리 계산
                tmp = min(tmp, dist_to_chicken); // 현재 집의 치킨 거리 중 최솟값으로 갱신
            }

            dist += tmp;                 // 현재 조합에 대해 모든 집의 치킨 거리를 합산
        }

        mn = min(mn, dist);              // 현재 조합의 도시 치킨 거리를 최소값과 비교하여 갱신
    } while (next_permutation(brute.begin(), brute.end())); // 다음 치킨집 선택 조합으로 넘어감

    cout << mn;                          // 도시의 최소 치킨 거리를 출력
}
