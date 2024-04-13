#include <iostream>
using namespace std;

int heap[100005];
int sz = 0;
void push(int n)
{
	heap[++sz] = n;
	int idx = sz;
	while (idx > 1 && heap[idx] < heap[idx / 2])
	{
		swap(heap[idx], heap[idx / 2]);
		idx = idx / 2;
	}
}

int top()
{
	return heap[1];
}

void pop()
{
	heap[1] = heap[sz--];
	int idx = 1;
	int ch = 2 * idx;
	while (ch <= sz)
	{
		if (ch != sz && heap[ch] > heap[ch + 1]) ch = ch + 1;
		if (heap[idx] > heap[ch])
		{
			swap(heap[idx], heap[ch]);
			idx = ch;
			ch = 2 * idx;
		}
		else
			break;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N = 0;
	cin >> N;
	while (N--)
	{
		int t = 0;
		cin >> t;
		if (t > 0)
		{
			push(t);
		}
		else
		{
			if (sz == 0) cout << 0 << '\n';
			else
			{
				cout << top() << '\n';
				pop();
			}
	
		}
	}
	return 0;
}