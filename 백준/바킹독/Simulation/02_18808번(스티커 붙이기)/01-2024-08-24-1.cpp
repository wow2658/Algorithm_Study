#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(10005, -1); // union find에서 사용하는 parent
                          // 시작할때부터 

int find(int x) 
{
    if (p[x] < 0) return x;         // -1 이면 자기 자신이 부모인 것이다.
    return p[x] = find(p[x]);       // 부모를 가진 녀석으로 판별되면 재귀적으로 더 파고들어가자
}                                   // 결국 자기자신 아니면 부모를 반환하게 되어 있다.

bool is_diff_group(int u, int v)
{
    u = find(u); v = find(v);
    if (u == v) return 0;           // 부모가 같으면 같은 그룹이니까 false -> no diff
   
    if (p[u] == p[v]) p[u]--;       // 다른 그룹일때 rank비교, 둘이 똑같으면 그냥 u쪽을 부모로 올려주자 (부전승~)

    if (p[u] < p[v]) p[v] = u;      // 자식이 더 많은 쪽을
    else p[u] = v;                  // 부모로 정해서 rank를 최적화하자

    return 1;
}

int v, e;
tuple<int, int, int> edge[100005]; // cost a b

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost, a, b };
    }
    sort(edge, edge + e);


    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diff_group(a, b)) continue; // 같은 그룹(false => no diff)이면 스킵
        ans += cost;                        // 비용 수집
        cnt++;                              // 간선 수 올려!
        if (cnt == v - 1) break;            // 간선 수 충족했으니 끝
    }
    cout << ans;
}