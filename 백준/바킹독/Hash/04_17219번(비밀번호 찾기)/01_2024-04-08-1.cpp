#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    string s, p;
    unordered_map<string, string> umap;

    cin >> N >> M;
    while (N--) {
        cin >> s >> p;
        umap[s] = p;
    }
    // p로 s찾는거면 vector필요했을텐데 스무쓰하게 s에서 p찾는거여서 코드가 매우 간단하다.
    while (M--) {
        cin >> s;
        cout << umap[s] << '\n';
    }


    return 0;
}
