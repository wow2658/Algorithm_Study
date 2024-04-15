#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, N;
    ll ans, left, right;
    cin >> t;
    while (t--) 
    {
        ans = 0;
        priority_queue<ll, vector<ll>, greater<>> pq;

        cin >> N;
        while (N--) 
        {
            cin >> left;
            pq.push(left);
        }
        while (pq.size() != 1) 
        {
            left = pq.top();
            pq.pop();
            right = pq.top();
            pq.pop();
            ans += left + right;
            pq.push(left + right);
        }
        cout << ans << '\n';
    }
}