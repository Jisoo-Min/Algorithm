#include <iostream>
#include <cstring>
using namespace std;


int find_max(int a, int b, int c)
{
	int answer = a;
	if(answer < b)
		answer = b;
	if(answer < c)
		answer = c;

	return answer;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int maze[1001][1001];
	int candy[1001][1001];
	//memset(maze, 0, sizeof(maze));
	//memset(candy, 0, sizeof(candy));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			candy[i][j] = maze[i][j] + find_max(candy[i-1][j-1], candy[i-1][j], candy[i][j-1]);
			//printf("compare (%d, %d, and %d) + %d \n", maze[i-1][j-1], maze[i-1][j], maze[i][j-1], maze[i][j]);
		}
	}


	printf("%d", candy[n][m]);
}