#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
int arr[17];
char s[17];
bool isused[17];

// isused -> 고를때 같은거 중복해서 골라도 되는지? 불가능하니까 isused 사용
// st -> 사전식으로 나열


bool aeiou(char t)
{
	return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void func(int k,int st)
{
	if (k == l)
	{
		//bool flag = false;
		int cnt1 = 0;				// 모음
		int cnt2 = 0;				// 자음

		for (int i = 0; i < l; i++)
		{
			if (aeiou(s[arr[i]]))	// isused찍은 i가 둔갑한 s가 aeiou인지
				cnt1++;				// 모음수 올리고
			else 
				cnt2++;             // 아니면 자음수
		}

		//if (cnt1 >= 1 && cnt2 >= 2) // 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음
		//	flag = true;

		//if (flag)
		if (cnt1 >= 1 && cnt2 >= 2)
		{
			for (int i = 0; i < l; i++)
				cout << s[arr[i]];
			cout << "\n";
		}
	}


	for (int i = st; i < c; i++) 
	{
		arr[k] = i;
		isused[i] = 1;
		func(k + 1, i + 1);
		isused[i] = 0;
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> s[i];
	sort(s, s + c);
	func(0,0);
}