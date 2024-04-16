#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, dl, cn;
    unsigned int cupNoodles = 0;
    priority_queue<unsigned int> cn_candidate;
    vector<vector<unsigned int>> cn_by_deadline(11);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> dl >> cn;
        cn_by_deadline[dl].push_back(cn);
    }
    for (int curr = 10; curr != 0; curr--)
    {
        for (int noodle : cn_by_deadline[curr])
            cn_candidate.push(noodle);

        if (cn_candidate.empty()) continue;
        cupNoodles += cn_candidate.top();
        cn_candidate.pop();
    }
    cout << cupNoodles;
}
// 주어진 문제 순서대로 풀었을때 컵라면을 얼마나 받나요? 라는 문제가 아니라
// 딱보고 최대로 받으려면 어떤 전략으로 문제를 골라풀어야 하나요? 하는 문제다
// 그러니까 데드라인끼리 컵라면수 높은걸 고르려고 노력하는 전략을 골라야 했었다.
// 그러나 데드라인은 나중이지만 컵라면을 많이 주는 여러 문제도 고려해야한다.
// 1일차에 1개주고 2일차에 20개 30개 주는거 있으면 1일차에 1개짜리 고르는게 아니라 2일차 20개 짜리 골라야한다.
// 그래서 priority_queue가 딱이다