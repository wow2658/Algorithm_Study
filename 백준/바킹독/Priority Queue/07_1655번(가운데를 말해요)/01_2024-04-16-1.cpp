#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, t;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        if (maxHeap.size() <= minHeap.size())
            maxHeap.push(t);
        else
            minHeap.push(t);

        if (!minHeap.empty() && minHeap.top() < maxHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }
}
// 1 max
// 5 min
// 작은걸 max힙에 큰걸 min힙에
// 