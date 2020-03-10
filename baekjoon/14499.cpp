#include <iostream>
#include <cstring>
using namespace std;


void go_down(int dice[][4], int floor)
{
	int tmp = dice[2][1];

	dice[2][1] = dice[1][1]; //한칸씩 
	dice[1][1] = dice[0][1]; //한칸씩
	dice[0][1] = dice[3][1]; //원래 바닥꺼 이동

	dice[3][1] = tmp;
	dice[1][3] = tmp;

	
}

void go_up(int dice[][4], int floor)
{
	int tmp = dice[0][1];

	dice[0][1] = dice[1][1]; //
	dice[1][1] = dice[2][1]; //한칸씩 
	dice[2][1] = dice[3][1]; //한칸씩

	dice[3][1] = tmp;
	dice[1][3] = tmp;

}

void go_right(int dice[][4], int floor)
{
	int tmp = dice[1][2];
	dice[1][2] = dice[1][1]; //
	dice[1][1] = dice[1][0]; //
	dice[1][0] = dice[1][3]; //


	dice[1][3] = tmp;
	dice[3][1] = tmp;

}

void go_left(int dice[][4], int floor)
{
	int tmp = dice[1][0];
	dice[1][0] = dice[1][1]; //
	dice[1][1] = dice[1][2]; //
	dice[1][2] = dice[1][3]; //

	dice[1][3] = tmp;
	dice[3][1] = tmp;

}


int get_bottom(int dice[][4])
{
	return dice[1][1];
}

void print_dice(int dice[][4])
{
	cout << "Dice " << endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << dice[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int N, M, X, Y, K;
	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);

	//지도
	int pan[N][M];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &pan[i][j]);
		}
	}

	int move_sequences[K];
	for(int i = 0; i < K; i++){
		scanf("%d", &move_sequences[i]); 
	}

	int dice[4][4];
	memset(dice, 0, sizeof(dice));


	int now_x = X;
	int now_y = Y;
	int dx[5] = {0, 0, 0, -1, 1};
	int dy[5] = {0, 1, -1, 0, 0};
	for(int i = 0; i < K; i++)
	{
		int nx = now_x + dx[move_sequences[i]];
		int ny = now_y + dy[move_sequences[i]];

		if(0<=nx && nx<N && 0<=ny && ny<M)
		{
			if(move_sequences[i] == 1)
				go_right(dice, pan[nx][ny]);
			else if(move_sequences[i] == 2)
				go_left(dice, pan[nx][ny]);
			else if(move_sequences[i] == 3)
				go_up(dice, pan[nx][ny]);
			else
				go_down(dice, pan[nx][ny]);

			if(pan[nx][ny] == 0){
				pan[nx][ny] = dice[1][3]; //바닥이 0이면 바닥에 값 넣어줌
			}
			else{ //판이랑 값을 교환한 셈임 
				dice[1][3] = pan[nx][ny];
				dice[3][1] = pan[nx][ny];
				pan[nx][ny] = 0;
			}

			//cout << "move: " << move_sequences[i] << endl;
			//print_dice(dice);
			cout << get_bottom(dice) << "\n";

			now_x = nx;
			now_y = ny;
		}
		
	}



	return 0;
}