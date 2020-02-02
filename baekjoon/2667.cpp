#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int map[25][25] = {0,};
int visit[25][25] = {0,};

vector<int> answers;
int n;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 우 하 상 좌
int rooms;

void dfs(int now_i, int now_j)
{	

	visit[now_i][now_j] = 1;
	rooms++;
	for(int d = 0; d < 4; d++)
	{
		int next_i = now_i+dir[d][0];
		int next_j = now_j+dir[d][1];

		if(0<=next_i && next_i<n 
		&& 0<=next_j && next_j<n 
		&& map[next_i][next_j] == 1 && visit[next_i][next_j] == 0){ //길이 있으면 
			dfs(next_i, next_j);
		}
	}

}


int main()
{

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}



	int how_many = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++){
			if(map[i][j] == 1 && visit[i][j] == 0)
			{
				rooms = 0;
				dfs(i, j);
				how_many += 1;
				answers.push_back(rooms);
			}
		}
	}

	sort(answers.begin(), answers.end());
	printf("%d\n", how_many);

	for(int i = 0; i < answers.size(); i++)
	{
		printf("%d\n", answers[i]);
	}


	return 0;
}