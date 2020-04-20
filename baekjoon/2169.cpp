#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int mars[1002][1002]; //테두리 공간이 필요해서 
int answer[1002][1002][3];//위에서온거, 왼쪽에서온거, 오른쪽에서 온거


int main()
{
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cin >> mars[i][j];
	}
	//fill(answer[0][0][0], answer[1001][1001][2]+1, -100000000);
	for(int i = 0; i < 1002; i++)
	{
		for(int j = 0; j < 1002; j++)
		{
			for(int k = 0; k < 3; k++)
				answer[i][j][k] = -100000000;
		}
	}
	

	for(int j = 2; j <= m; j++)
		answer[1][j][1] = answer[1][j-1][1] + mars[1][j]; //제일 첫줄은 무조건 왼쪽에서만옴 


	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			//위에서오는 거랑, 왼쪽에서 오는거 
			answer[i][j][0] = max(max(answer[i-1][j][0], answer[i-1][j][1]), answer[i-1][j][2]) + mars[i][j];
			answer[i][j][1] = max(answer[i][j-1][0], answer[i][j-1][1]) + mars[i][j];
		}


		//오른쪽에서오는거는 제일 마지막에
		for(int j = m; j >= 1; j--)
			answer[i][j][2] = max(answer[i][j+1][0], answer[i][j+1][2]) + mars[i][j];
	}

	

	int ans = max(max(answer[n][m][0], answer[n][m][1]), answer[n][m][2]);
	cout << ans;

	return 0;
}