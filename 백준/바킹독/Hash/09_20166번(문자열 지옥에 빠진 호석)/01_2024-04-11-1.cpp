#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

string board[10];
int n, m, k;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 8방향!
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 00은 없다!
unordered_map<string, int> cnt;

void dfs(int i, int j, string s)
{
    cnt[s]++; // a도 올리고 ababa도 올리고!
    if (s.size() == 5) return; // 길이 5가 최대이고 이미 충분하다면 탐색할 필요가 없다
    for (int dir = 0; dir < 8; dir++)
    {
        int nx = (i + dx[dir] + n) % n; // (현재 + 다음스텝 + 음수방지용) % 순환용
        int ny = (j + dy[dir] + m) % m;
        dfs(nx, ny, s + board[nx][ny]); // 꼬리재귀인데 호출될때 마다 cnt map을 업데이트하고 빠져나오는 역할
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dfs(i, j, string(1, board[i][j])); // 처음보는 string 생성자였다 // construct from _Count * _Ch
    // 어디에서 시작하는지 기준이 없으니 모든곳에서 한번씩 다 시작해본다... 정말 무섭다


    // 좋아하는 문자열 받기 전에 이미 모든 경우의수는 수집되어있다!
    while (k--)
    {
        string s;
        cin >> s;
        cout << cnt[s] << '\n'; // 그냥 쏙쏙 골라서 던져줄뿐
    }
}