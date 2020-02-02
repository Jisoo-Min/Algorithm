#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int map[50][50] = {0,};
int visit[50][50] = {0,};


int w, h;

int dir[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1},
				{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; 
// 우 하 상 좌 대각선위/오른쪽 아래/오른쪽, 아래/왼쪽, 위/왼쪽

int how_many;
void dfs(int now_i, int now_j)
{	

	visit[now_i][now_j] = 1;
	for(int d = 0; d < 8; d++)
	{
		int next_i = now_i+dir[d][0];
		int next_j = now_j+dir[d][1];

		if(0<=next_i && next_i<h 
		&& 0<=next_j && next_j<w 
		&& map[next_i][next_j] == 1 && visit[next_i][next_j] == 0){ //길이 있으면 
			dfs(next_i, next_j);
		}
	}

}


int main()
{
	scanf("%d %d", &w, &h);
	while(!(w==0 && h==0)){

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				scanf("%1d", &map[i][j]);
				visit[i][j] = 0;
			}
		}





		int how_many = 0;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++){
				if(map[i][j] == 1 && visit[i][j] == 0)
				{
					dfs(i, j);
					how_many += 1;
				}
			}
		}

		printf("%d\n", how_many);



		scanf("%d %d", &w, &h);



	}

	return 0;
}