#include <iostream>
#include <algorithm>
using namespace std;

char alpha[50];
int N, K;
int main()
{

	scanf("%d %d", &N, &K);


	for(int a = 0; a <= N; a++)//A를 몇개 놓을까?
	{
		int b = N - a;
		int put_a[51] = {0,};
		if(a*b >= K)
		{
			for(int i = 0; i < a; i++)
			{
				int idx = min(b, K);
				put_a[idx] += 1;
				K -= idx;
			}

			// 출력
			for(int i = b; i >= 0; i--)
			{
				if(put_a[i] > 0)
				{
					for(int j = 0; j < put_a[i]; j++)
						cout << "A";
				}
				if(i != 0)
				{
					cout << "B";
				}
			}

			return 0;
		}
	}


	cout << "-1";
	return 0;
}