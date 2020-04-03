#include <iostream>

using namespace std;

int ans[1001][1001];

void calculate(int n, int k)
{
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || j == i)
				ans[i][j] = 1;
			else
				ans[i][j] = (ans[i-1][j-1] + ans[i-1][j]) % 10007;
		}
	}

	cout << ans[n][k];
}


int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	
	calculate(n, k);


	return 0;
}