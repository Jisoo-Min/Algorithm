#include <iostream>
#include <cstring>

using namespace std;
int board[10][10] = {0,};
bool garo[10][10] = {0,};//0번째에, 숫자N이 있니?
bool sero[10][10] = {0,};
bool squa[10][10] = {0,};
bool block[10][10] = {0,};

int dx[4] = {0, 1};
int dy[4] = {1, 0};



bool solve(int z)
{

	if(z == 81) //다 채운경우 
	{
		//정답출력
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		return true;
	}
	//이미 채워져있는 칸이라

	int x = z/9;
	int y = z%9;
	if(board[x][y] != 0)
	{	//다음칸으로 옮겨주기
		return solve(z+1);
	}
	else //빈칸이 아니면 도미노 놓아야함
	{
		for(int d = 0; d < 2; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];

			if(0<=nx && nx<9 && 0<=ny && ny<9 && board[nx][ny] == 0) //범위확인, 채울수있는 칸인지 
			{	
				//두 칸에 i랑 j채울꺼임
				for(int i = 1; i <= 9; i++)
				{
					for(int j = 1; j <= 9; j++)
					{
						if(i == j || block[i][j] == true) //같은스도미노쿠X, 사용한적X
							continue;
						//놓을 수 있는 숫자인지 확인해야함 가로, 세로, 사각
						if(garo[x][i] == false && sero[y][i] == false && squa[(3*(x/3))+(y/3)][i]   == false
						&& garo[nx][j]== false && sero[ny][j]== false && squa[(3*(nx/3))+(ny/3)][j] == false)
						{
							//도미노 넣기 
							board[x][y] = i;
							board[nx][ny] = j;
					
							//넣었다고 확인
							garo[x][i] = true; sero[y][i] = true; squa[(3*(x/3))+(y/3)][i]   = true;
							garo[nx][j]= true; sero[ny][j]= true; squa[(3*(nx/3))+(ny/3)][j] = true;

							//도이노 사용
							block[i][j] = block[j][i] = true;
							//다음칸 고고 
							if(solve(z+1))
								return true;
							
							//여기서 리턴 못했으면, 정답 못찾은거니까 원래대로 되돌려

							board[x][y] = 0;
							board[nx][ny] = 0;

							//넣었다고 확인
							garo[x][i] = false; sero[y][i] = false; squa[(3*(x/3))+(y/3)][i]   = false;
							garo[nx][j]= false; sero[ny][j]= false; squa[(3*(nx/3))+(ny/3)][j] = false;

							//도이노 사용
							block[i][j] = block[j][i] = false;
						}
					}
				}
			}
		}
	}

	return false;
}

int main()
{
	int time = 1;
	while(true)
	{
		int N;
		cin >> N;
		if(N == 0)
			break;

		memset(board, 0, sizeof(board));
		memset(garo, 0, sizeof(garo));
		memset(sero, 0, sizeof(sero));
		memset(squa, 0, sizeof(squa));
		memset(block, 0, sizeof(block));

		//기본 게임정보 입력받기 (스도미노쿠 )
		for(int i = 0; i < N; i++)
		{
			int num1, num2;
			string pos1, pos2;
			cin >> num1 >> pos1 >> num2 >> pos2;
			int x, y;
			x = pos1[0] - 'A';
			y = pos1[1] - '1';
			board[x][y] = num1;
			garo[x][num1] = true;
			sero[y][num1] = true;
			squa[(3*(x/3))+(y/3)][num1] = true;

			x = pos2[0] - 'A';
			y = pos2[1] - '1';
			board[x][y] = num2;
			garo[x][num2] = true;
			sero[y][num2] = true;
			squa[(3*(x/3))+(y/3)][num2] = true;

			block[num1][num2] = block[num2][num1] = true;

		}
		//1개짜리 입력받기 
		for(int i = 1; i <= 9; i++)
		{
			string pos;
			cin >> pos;

			int x, y;
			x = pos[0] - 'A';
			y = pos[1] - '1';
			board[x][y] = i;
			garo[x][i] = true;
			sero[y][i] = true;
			squa[(3*(x/3))+(y/3)][i] = true;
		}

		
		printf("Puzzle %d\n", time);
		solve(0);//(0, 0)부터 풀꺼다
		time += 1;

	}



	return 0;

}