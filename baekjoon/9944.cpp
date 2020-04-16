#include <iostream>


using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1}; //오, 왼, 아래, 위
int dy[4] = {1, -1, 0, 0};

int total = 0;//지나가야하는 곳의 갯수
char board[30][30]; 
int ans = -1;

void go(int sx, int sy, int cnt, int time)
{
	if(cnt == total)
	{
		//cout << "Total " << total << " " << cnt << endl;
		if(ans == -1 || ans > time)
			ans = time;
		return;
	}
	for(int d = 0; d < 4; d++)
	{
		
		int nx = sx + dx[d];
		int ny = sy + dy[d];

		int new_spot = 0;
		while(0<=nx && nx<n && 0<=ny && ny<m
			&& board[nx][ny] == '.')
		{
			if(board[nx][ny] == '.'){
				board[nx][ny] = 'v';
				new_spot += 1;
			}
			nx += dx[d];
			ny += dy[d];
		}
		nx -= dx[d];
		ny -= dy[d];
		
		//cout << sx << " to " << nx << endl;
		//cout << sy << " to " << ny << endl;
 		if(sx == nx && sy == ny) //움직였는데 같은 자리이면
			continue;
		if(new_spot != 0) //처음방문하는 곳이 없는 곳임 
		{
			go(nx, ny, cnt+new_spot, time+1);
		}

		//원래대로 되돌려주기 //
		while(!(nx==sx && ny==sy))
		{
			board[nx][ny] = '.';
			nx -= dx[d];
			ny -= dy[d];
		}
	
		
		
		
	}
	


}

int main()
{
	int clock = 1;

	while(cin >> n >> m)
	{
		ans = -1; //정답 초기화
		total = 0; //빈곳초기화
		//지나가야하는 곳 계산 
		for(int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			for(int j = 0; j < m; j++)
			{
				board[i][j] = tmp[j];
				if(board[i][j] == '.')
					total += 1;
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(board[i][j] == '.')
				{
					board[i][j] = 'v'; //방문체크
					go(i, j, 1, 0); //1번째칸 방문했고 , 1초쨰임
					board[i][j] = '.'; //방문 취소
				}
			}
		}
		printf("Case %d: %d\n", clock, ans);
		clock += 1;

	}



	return 0;
}