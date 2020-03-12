#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int x, y, direction;
	scanf("%d %d %d", &x, &y, &direction);

	int room[N][M];
	bool check[N][M];
	memset(check, 0, sizeof(check));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &room[i][j]);
		}
	}


	int answer = 0;


	int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서 
	int dy[4] = {0, 1, 0, -1};


	while(true)
	{
		//1. 현재위치를 청소한다. 
		if(check[x][y] == false){
			answer += 1;
			check[x][y] = true;
 		}
 		//청소했거나, 길이 막혀있으면
 		if((check[x+1][y] == true || room[x+1][y] == 1) &&
 		   (check[x][y+1] == true || room[x][y+1] == 1) &&
		   (check[x-1][y] == true || room[x-1][y] == 1) &&
		   (check[x][y-1] == true || room[x][y-1] == 1))
 		{
 			//후진
 			int back_dir = (direction + 2)%4;
 			if(room[x+dx[back_dir]][y+dy[back_dir]] == 1) //벽이면 종료
 			{ 
 				break;
 			}
 			else
 			{
 				x = x + dx[back_dir];
 				y = y + dy[back_dir];
 				continue;
 			}

 		}

 		int left = (direction+3)%4;
 		if(room[x+dx[left]][y+dy[left]] == 0 
 	   && check[x+dx[left]][y+dy[left]] == false) //갈 수 있고 청소할 수 있으면 
 		{
 			x = x + dx[left];
 			y = y + dy[left];
 			direction = left;
 		}
 		else
 		{
 			direction = left;
 		}


	}

	printf("%d", answer);

	return 0;
}