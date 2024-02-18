[![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/2841ee63-6d1f-4a81-84d9-4ca99cc00618)](https://www.acmicpc.net/problem/1926)

***

<details><summary>1. 왜 502인가?</summary>

![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/d1f65a57-9019-4089-84d8-564e9c33d361)

![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/1b75b494-c98b-4f02-86ba-4c4f8aed6e4c)

구글에 다른사람들 검색하면 501로 한 사람들도 꽤 있긴하다.

</details>
<details><summary>2. == 0 과 != 1 의 차이가 있을까?</summary>
  
![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/62c4d307-a19e-4280-8e07-a73fc4820f99)
</details>

<details><summary>3. 변수명 max 충돌나던데 min은 뭐라고 명명들 하는지?</summary>

![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/fcf3d967-e742-49fb-9ba4-f88cb2512508)

</details>

<details><summary>4. void bfs()로 따는 빼는사람도 있던데 어떨지?</summary>

```
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int start_x, int start_y, int& area) {
    queue<pair<int, int>> Q;
    vis[start_x][start_y] = 1;
    Q.push({ start_x, start_y });

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        area++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;

            vis[nx][ny] = 1;
            Q.push({ nx, ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int mx = 0;
    int num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] == 0)
                continue;

            int area = 0;
            bfs(i, j, area);
            num++;
            mx = max(mx, area);
        }
    }

    cout << num << '\n' << mx;
    return 0;
}
```
![image](https://github.com/wow2658/Algorithm_Study/assets/34699039/0244e4e7-af29-468b-a730-3f7745f0ca36)

동일하게 잘 작동한다. 근데 void bfs(int start_x, int start_y, int& area)에 들어가는 인수들을 까먹지 않을까?
완전 간단하게 void bfs()만으로 돌아가게 한다면?
```
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    int mx = 0;
    int num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || board[i][j] == 0)
                continue;

            int area = 0;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});

            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }

            num++;
            mx = max(mx, area);
        }
    }

    cout << num << '\n' << mx; // 이부분이 아쉽다.
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    bfs();

    return 0;
}
```
구글에 검색해보면 
bfs(int start_x, int start_y) 정도로 인수 두개를 전달하여 구현한 사람이 많았다.
area를 전역변수로 해놓으면 로직따라 되는거 같다.

나는 참조를 잘 쓰고 싶으니 인수 3개 전달해주는 버전으로 연습해봐야겠다.
</details>
