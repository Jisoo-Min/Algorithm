#include <iostream>
#include <cstring>
using namespace std;

int main()
{

	int T;
	scanf("%d", &T);

	int wheel[T][8];

	for(int i = 0 ; i < T; i++)
	{
		for(int j = 0 ; j < 8; j++)
		{
			scanf("%1d", &wheel[i][j]);
		}
		
	}

	int K;
	scanf("%d", &K);

	for(int k = 0; k < K; k++)
	{
		//printf("Time %d \n", k);
		int wheel_num, rotate_num;
		scanf("%d %d", &wheel_num, &rotate_num);
		wheel_num -= 1; //나는 0부터 3까지로 했으니까 -1해줬음 

		//회전하는 바퀴 왼쪽바퀴들 
		int is_rotate[T];
		memset(is_rotate, 0, sizeof(is_rotate));
		is_rotate[wheel_num] = rotate_num; //기준꺼는 먼저 바꿔줌 


		//회전하는 바퀴 오른쪽바퀴들
		for(int w = wheel_num+1; w < T; w++)
		{
			if(wheel[w-1][2] != wheel[w][6])
			{
				is_rotate[w] = is_rotate[w-1] * (-1);
			}else
			{
				break;
			}

		}

		for(int w = wheel_num-1; w >= 0; w--)
		{
			if(wheel[w][2] != wheel[w+1][6])
			{
				is_rotate[w] = is_rotate[w+1] * (-1);
			}else
			{
				break;
			}

		}


		
		for(int w = 0; w < T; w++)
		{
			if(is_rotate[w] == 1)
			{
				int tmp = wheel[w][0];

				wheel[w][0] = wheel[w][7];
				wheel[w][7] = wheel[w][6];
				wheel[w][6] = wheel[w][5];
				wheel[w][5] = wheel[w][4];
				wheel[w][4] = wheel[w][3];
				wheel[w][3] = wheel[w][2];
				wheel[w][2] = wheel[w][1];
				wheel[w][1] = tmp;

			}
			else if(is_rotate[w] == -1)
			{
				int tmp = wheel[w][0];

				wheel[w][0] = wheel[w][1];
				wheel[w][1] = wheel[w][2];
				wheel[w][2] = wheel[w][3];
				wheel[w][3] = wheel[w][4];
				wheel[w][4] = wheel[w][5];
				wheel[w][5] = wheel[w][6];
				wheel[w][6] = wheel[w][7];
				wheel[w][7] = tmp;
			}

		}

	
	}


	int answer = 0;
	for(int w = 0; w < T; w++)
	{
		if(wheel[w][0] == 1)
		{
			answer += 1;
		}
	}
	printf("%d", answer);



	return 0;
}