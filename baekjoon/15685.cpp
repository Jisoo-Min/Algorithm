#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
using namespace std;

int main()
{


	int N;
	scanf("%d", &N);

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};

	bool pan[102][102];

	memset(pan, 0, sizeof(pan));
	for(int n = 0 ; n < N; n++)
	{
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector<tuple<int, int, int>> dragon; //x좌표y좌표, 방향 
		//0세대
		dragon.push_back(make_tuple(x, y, d));
		dragon.push_back(make_tuple(x+dx[d], y+dy[d], (d+1)%4));

		for(int i = 1 ; i < g; i++) //커브 만들기 
		{
			int idx = dragon.size()-1; //기준 점
			//마지막점 제외하고 다 옮겨줌 
			int moving_idx = idx;
			//cout << "Moving IDX = " << moving_idx<< endl;
			for(int j = idx; j >=0; j--)
			{	

				
				int dir = (get<2>(dragon[j]) + 1)%4;

				int nx = get<0>(dragon[moving_idx]) + dx[get<2>(dragon[moving_idx])];
				int ny = get<1>(dragon[moving_idx]) + dy[get<2>(dragon[moving_idx])];
				dragon.push_back(make_tuple(nx, ny, dir));
				

				moving_idx += 1;

			}

			
		}

		//마지막꺼 한번 더 추가 
		if(g != 0){
			int last = dragon.size()-1;

			int nx = get<0>(dragon[last]) + dx[get<2>(dragon[last])];
			int ny = get<1>(dragon[last]) + dy[get<2>(dragon[last])];
			dragon.push_back(make_tuple(nx, ny, 0));// 마지막꺼 방향은 상관없음
		}
		
 
		//만들어진거다 체크해주기 
		for(int k = 0; k < dragon.size(); k++)
		{
			int visit_x = get<0>(dragon[k]);
			int visit_y = get<1>(dragon[k]);
			pan[visit_x][visit_y] = true;
		}


	}


	//사각형 확인 
	int answer = 0;
	for(int i = 0 ; i <= 101; i++)
	{
		for(int j = 0 ; j <= 101; j++)
		{
			if(pan[i][j] == true && pan[i+1][j] == true &&
			   pan[i][j+1] == true && pan[i+1][j+1] == true)
				answer += 1;
		}
	}

	cout << answer;



	return 0;
}