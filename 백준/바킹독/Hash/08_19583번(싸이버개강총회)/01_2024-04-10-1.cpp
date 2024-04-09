#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

int ttoi(string time)
{
    int t = 0;
    string h, m;

    h = time.substr(0, 2); // 01 2 34
    m = time.substr(3, 2); // hh : mm

    t = (60 * stoi(h)) + stoi(m);
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;

    string S, E, Q;
    cin >> S >> E >> Q;

    int st_t, end_t, stream_t;
    st_t = ttoi(S);
    end_t = ttoi(E);
    stream_t = ttoi(Q);

    unordered_set<string> st_list;
    unordered_set<string> atd_list;

    while (true)
    {
        string c_time, name;
        cin >> c_time >> name;
        if (cin.eof() == true) break; // 컨트롤z로 그만

        if (ttoi(c_time) <= st_t)
        {
            st_list.insert(name);
        }
        else if (ttoi(c_time) >= end_t && ttoi(c_time) <= stream_t)
        {
            if (st_list.find(name) != st_list.end())
            {
                atd_list.insert(name);
            }
        }
    }

    cout << atd_list.size() << "\n";
    return 0;
}