#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int R, C;
char cave[101][101];
bool check[101][101];

vector<pair<int, int>> chunk;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void dfs(int x, int y)
{
	//dfs해서 바닥에 있는게 하나도 없으면 공중에 떠있는거니까 -> 내려줘야함, 아니면 땡 
	//종료조건	
	if(cave[x][y] == '.' || check[x][y] == true)
		return;

	check[x][y] = true; //방문했음
	chunk.push_back(make_pair(x, y));

	for(int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(0<= nx && nx < R && 0 <= ny && ny < C)
		{
			dfs(nx, ny);
		}
	}


}

void simulate()
{
	memset(check, 0, sizeof(check));
 	for(int i = 0; i < R; i++)
	{	
		for(int j = 0; j < C; j++)
		{
			//cout << " check (" << i << ", " << j << ")" << endl;
			if(cave[i][j] == 'x' && check[i][j] == 0){ //미네랄이고 방문하지 않았으면
				chunk.clear(); //그룹 초기화해야함
				dfs(i, j);

				int low[C];
				memset(low, -1, sizeof(low)); //chunk에서 낮은 것들 구하기 
				for(pair<int, int> c : chunk)
				{
					if(low[c.second] < c.first) //지금께 청크에서 제일 낮은 미네랄
						low[c.second] = c.first;
					cave[c.first][c.second] = '.'; //chunk미네랄 다 없애기
				}

				int lowest = R; //미네랄 청크충에 어떤 미네랄이 제일 아래있는지
				for(int j = 0; j < C; j++)
				{
					if(low[j] == -1)
						continue;

					int k;
					for(k = low[j]; k < R && cave[k][j]=='.'; k++);

					if(lowest > k-low[j]-1)
						lowest = k-low[j]-1;
				}

				for(pair<int, int> c: chunk)
				{
					c.first += lowest;
					cave[c.first][c.second] = 'x';
					check[c.first][c.second] = true;
				}

			}
			
		}
	}


}
int main()
{
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++)
	{	
		cin >> cave[i];
	}
	int N;
	scanf("%d", &N);

	//첫번째는 왼쪽 -> 오른쪽
	//두번째는 오른쪽-> 왼쪽
	for(int t = 0; t < N; t++)
	{
		int height;
		scanf("%d", &height);
		height = R - height;
		//떨어뜨리고 
		if(t%2 == 0)
		{
			int col = 0;
			while(cave[height][col] == '.')
				col++;
			cave[height][col] = '.';
		}
		else
		{
			int col = C-1;
			while(cave[height][col] == '.')
				col--;
			cave[height][col] = '.';
		}


		//확인
		//모든 미네랄에 대해서 공중에 떠있는지, 바닥에 붙어있는지
		simulate();

		//바닥에 떨어뜨리자 

	}

	//정답 출력
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			cout << cave[i][j];
		}
		cout << endl;
	}


	return 0;
}