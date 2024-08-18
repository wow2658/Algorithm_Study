#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

// 부모 노드를 저장하는 배열 (유니온 파인드를 위해 사용)
int parent[51];

// find 함수: 주어진 노드의 루트 노드를 찾음
int find(int x) 
{
    if (parent[x] == x) 
    {
        return x; // 자기 자신이 루트라면 자기 자신을 반환
    }
    else 
    {
        return parent[x] = find(parent[x]); // 재귀적으로 루트 노드를 찾고 경로 압축
    }
}

// union 함수: 두 집합을 합침 (노드 x와 y의 루트를 합침)
void union_set(int x, int y) 
{
    int rootX = find(x); // x의 루트 노드 찾기
    int rootY = find(y); // y의 루트 노드 찾기
    if (rootX != rootY)
    {
        parent[rootY] = rootX; // 두 루트가 다르다면, y의 루트를 x의 루트로 변경
    }
}

int main() 
{
    // 빠른 입출력을 위한 설정
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 사람의 수 N과 파티의 수 M 입력받기
    int N, M;
    cin >> N >> M;

    // 각 사람의 초기 루트는 자기 자신으로 설정
    for (int i = 1; i <= N; i++) 
    {
        parent[i] = i;
    }

    // 진실을 아는 사람 수와 그 사람들의 번호를 입력받기
    int numOfTruth;
    cin >> numOfTruth;
    vector<int> truth(numOfTruth); // 진실을 아는 사람들의 목록
    for (int i = 0; i < numOfTruth; i++) 
    {
        cin >> truth[i];
    }

    vector<vector<int>> parties(M); // 각 파티에 참석하는 사람들 저장
    for (int i = 0; i < M; i++) 
    {
        int num; // 파티에 참석하는 사람의 수
        cin >> num;
        parties[i].resize(num); // 파티에 참석하는 사람들의 수에 맞게 크기 조정
        for (int j = 0; j < num; j++) 
        {
            cin >> parties[i][j];
        }

        // 파티에 참석하는 모든 사람들을 같은 집합으로 묶음
        for (int j = 1; j < num; j++)
        {
            union_set(parties[i][0], parties[i][j]);
        }
    }

    // 진실을 아는 모든 사람의 루트를 찾아서 저장
    unordered_set<int> truth_roots;
    for (int i = 0; i < numOfTruth; i++) 
    {
        truth_roots.insert(find(truth[i])); // 진실을 아는 사람들의 루트를 집합에 추가
    }

    int count = 0; // 거짓말을 할 수 있는 파티 수를 세는 변수

    // 각 파티를 확인하며 거짓말을 할 수 있는지 체크
    for (int i = 0; i < M; i++) 
    {
        bool canLie = true; // 거짓말을 할 수 있다고 가정
        for (int j = 0; j < parties[i].size(); j++) {
            if (truth_roots.count(find(parties[i][j]))) 
            {
                canLie = false; // 파티 참석자 중 루트가 진실을 아는 사람과 같은 경우 거짓말 불가
                break;
            }
        }
        if (canLie) 
        {
            count++; // 거짓말을 할 수 있는 파티 수 증가
        }
    }

    cout << count; // 결과 출력
}
