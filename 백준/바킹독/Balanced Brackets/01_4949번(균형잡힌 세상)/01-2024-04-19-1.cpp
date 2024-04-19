#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        string a;
        getline(cin, a);
        if (a == ".") break; // 입력의 종료조건으로 맨 마지막에 온점 하나(".") 들어왔을때
        // getline 한줄씩 받는것. 개행문자\n 마다 끊는다.
        stack<char> s;
        bool isValid = true;
        for (auto c : a)
        {
            if (c == '(' || c == '[') s.push(c); // 여는 괄호는 일단 push
            else if (c == ')')
            {
                if (s.empty() || s.top() != '(') // 걸리면 안돼
                {
                    isValid = false;             // 실패1
                    break;
                }
                s.pop();                         // 무사 통과시 테트리스 펑
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    isValid = false;             // 실패2
                    break;
                }
                s.pop();
            }
        }
        if (!s.empty()) isValid = false;         // 왜 청소가 안 되어있을까? 실패3

        // isValid 검증의 시간
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}
