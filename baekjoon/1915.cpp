#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int board[1002][1002];
	int answer[1002][1002];

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			scanf("%1d", &board[i][j]);
	}

	

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(board[i][j] == 1)
			{
				answer[i][j] = min(min(answer[i-1][j], answer[i-1][j-1]), answer[i][j-1]) + 1;
			}
			else
			{
				answer[i][j] = 0;
			}
		}
	}

	int ans = 0;
	for(int i = 1 ; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(ans < answer[i][j])
				ans = answer[i][j];
		}
	}

	cout << ans*ans;
	return 0;
}