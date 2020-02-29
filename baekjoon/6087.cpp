#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int w, h;
	scanf("%d %d", &w, &h);

	int m[102][102];

	// 지도 정보 가지고 오기
	int s_x, s_y;//시작점
	int e_x, e_y;//종료점
	bool flag = false;
	for(int i = 0; i < h; i++){
		string tmps;
		cin >> tmps;
		for(int j = 0; j < w; j++){
			m[i][j] = tmps[j];
			if(m[i][j] == 'C'){
				if(flag == false){
					s_x = i; s_y = j;
					flag = true;
				}else{
					e_x = i; e_y = j;
				}
			}
		}
	}

	int mirror[102][102];
	memset(mirror, -1, sizeof(mirror));


	//시작점 넣기 
	queue<pair<int, int>> q;
	q.push(make_pair(s_x, s_y));
	mirror[s_x][s_y] = 0;

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	//cout << "START at : ("<< s_x << ", " << s_y << ")\n";
	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		int num_mirror = mirror[now.first][now.second] + 1;
		for(int d = 0; d < 4; d++)
		{
 			int nx = now.first + dx[d];
			int ny = now.second+ dy[d];

			while(0<=nx && nx<h && 0<=ny && ny<w ) //그쪽 방향으로 쭉 탐색
			{
				//cout << "MOVE then,, (" << nx << ", " << ny << ")" << " ";
				//방문
				if(m[nx][ny] == '*')
					break;
				if(mirror[nx][ny] == -1){
					q.push(make_pair(nx, ny));
					mirror[nx][ny] = num_mirror;
				}
				
				//한칸 전진
				nx += dx[d];
				ny += dy[d];

			
			}
			//cout << endl;

		}
		/*
		for(int i = 0 ; i < h; i++)
		{
			for(int j = 0; j <w; j++)
			{
				cout << mirror[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n\n";
		*/
	}

	printf("%d", mirror[e_x][e_y]-1);
	return 0;
}