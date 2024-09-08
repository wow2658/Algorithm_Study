#include <iostream>
#include <vector>

using namespace std;

const int MXN = 2000;  // 배열 크기를 2000으로 설정, 절대값 1000 이하의 정수를 처리하기 위함
const int HALF = MXN / 2;  // 절대값 1000 이하의 정수를 양수로 변환하기 위한 상수

int main(void)
{
    ios::sync_with_stdio(0); 
    cin.tie(0);  

    // 배열 크기를 MXN + 2로 설정하고, 각 값을 false로 초기화 (중복 여부를 체크하는 데 사용)
    vector<bool> arr(MXN + 2);

    int N, t;  // N: 입력되는 수의 개수, t: 각각의 입력된 정수 저장용 변수

    cin >> N; 
    while (N--)  
    {
        cin >> t;  // 정수 t(1 ≤ t ≤ 1,000) 입력
        arr[t + HALF] = true;  // 입력된 정수 t를 배열 인덱스에 매핑 (절대값을 고려해 HALF 더함)
    }

    // 배열 전체를 순차적으로 확인하며, true로 표시된 인덱스만 원래 정수 값으로 출력
    for (int i = 0; i <= MXN; i++)
    {
        if (arr[i])  // arr[i]가 true이면 해당 인덱스는 입력된 숫자임
        {
            cout << i - HALF << '\n';  // HALF를 빼서 원래 정수 값으로 복원 후 출력
        }
    }
}
