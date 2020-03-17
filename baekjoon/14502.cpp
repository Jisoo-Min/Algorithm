#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int lab[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> zero;
vector<pair<int, int>> virus;

int max_safe = 0;
void count()
{
	bool check[n][m];
	memset(check, 0, sizeof(check));
		
	for(int i = 0 ; i < virus.size(); i++)
	{

		int x = virus[i].first;
		int y = virus[i].second;

		queue<pair<int, int>> q; 
		q.push(make_pair(x, y));
		check[x][y] = true; //바이러스 

		while(!q.empty())
		{
			pair<int, int> now = q.front(); 
			q.pop();

			for(int d = 0 ; d < 4; d++)
			{
				int nx = now.first + dx[d];
				int ny = now.second+ dy[d];

				if(0 <= nx && nx < n && 0 <= ny && ny < m
				&& lab[nx][ny] == 0 && check[nx][ny] == false) //빈 곳 이고 방문하지 않았으면
				{
					check[nx][ny] = true; //바이러스 퍼짐 
					q.push(make_pair(nx, ny));
		
				}
			}

		}
		
	}

	int safe = 0;

	//안전구역 세기 
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(lab[i][j] == 0 && check[i][j] == false) //원래 안전구역이었고 바이러스 안퍼졌으면
				safe += 1;
		}
	}

	if(max_safe < safe)
		max_safe = safe;


}

void dfs(int z, int w)
{
	if(w > 3)
	{
		//계산
		count();
		return;
	}

	if(z >= zero.size()) //범위넘어가면 더이상 진행X
		return;
	

	int x = zero[z].first;
	int y = zero[z].second;

	lab[x][y] = 1; //wall설치
	dfs(z+1, w+1);

	lab[x][y] = 0; //wall설치 취소
	dfs(z+1, w);


}

int main()
{
	
	scanf("%d %d", &n, &m);
	

	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ; j < m; j++)
		{
			scanf("%d", &lab[i][j]); 
			if(lab[i][j] == 0) //안전구역 
				zero.push_back(make_pair(i, j));
			
			else if(lab[i][j] == 2) // 바이러ㅅ
				virus.push_back(make_pair(i, j));
		}
	}
	
	lab[1][0] = 1;
	lab[0][1] = 1;
	lab[3][5] = 1;

	//count();
	dfs(0, 1); //0번쨰 zero부터 보고, 1번째 wall 선택


	cout << max_safe;


	return 0;
}