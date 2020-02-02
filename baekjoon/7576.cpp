#include <iostream>
#include <queue>

using namespace std;

/*
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1
*/

int tomatoes[1000][1000];
int t[1000][1000]={0,};

queue<pair<int, int>> where_tomato;

int m, n;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int num_tomato = 0;
int main()
{
	scanf("%d %d", &m, &n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &tomatoes[i][j]);
			if(tomatoes[i][j] == 1){
				where_tomato.push({i, j});
			}


			if(tomatoes[i][j] == 0){
				num_tomato+=1;
			}
		}
	}

	//토마토가 모두 익어있는 상태
	if(num_tomato == 0){
		printf("0");
		return 0;
	}


	while(!where_tomato.empty())
	{
		pair<int, int> head = where_tomato.front();
		where_tomato.pop();

		for(int d = 0; d < 4; d++)
		{
			pair<int, int> next = {head.first + dir[d][0],
								   head.second + dir[d][1]};

			if(0<=next.first && next.first < n
			&& 0<=next.second&& next.second< m
			&& tomatoes[next.first][next.second] == 0 //안익은 토마토고 
			&& t[next.first][next.second] == 0) //간적없음 
			{
				where_tomato.push({next.first, next.second});
				t[next.first][next.second] = t[head.first][head.second] + 1;
			}
		}

	}

	int max_t = 0;
	for(int i = 0; i<n; i ++)
	{
		for(int j = 0; j < m; j++)
		{
			if(tomatoes[i][j] == 0 && t[i][j] == 0){
				printf("-1");
				return 0;
			}
			if(t[i][j] > max_t){
				max_t = t[i][j];
			}
		}
	}

	printf("%d", max_t);
	return 0;
}