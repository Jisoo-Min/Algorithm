#include <iostream>
#include <cstring>
using namespace std;

int N, L;
int answer = 0;

bool can_go(int road[])
{

	// for(int i = 0 ; i < N; i++)
	// {
	// 	cout << road[i] << " ";
	// }
	// cout << " => "; 
	bool slide[N];
	memset(slide, 0, sizeof(slide));
	for(int i = 0 ; i < N-1; i++)
	{
		//같은 경우 
		if(road[i] == road[i+1]) //같으면 상관없음
			continue;

		// 증가하는 경우 확인 
		if(road[i] < road[i+1])
		{
			//높이 차이가 2이상이면 그냥 종료 
			if(road[i+1]-road[i] >= 2)
				return false;

			int height = road[i];
			//1. 확인 : 경사로를 낮은 곳에 놓을 수 있는가? 
			for(int j = i; j > (i - L); j--)
			{	
				//놓을 수 있는 범위 벗어나거나 
				// 슬라이드 놓아야하는데 이미 놓아져 있는 경우 
				// 동일한 높이가 아닌 경우 
				if(j < 0 || slide[j] == true || road[j] != height)
					return false;
			}
			//놓을 수 있으면 
			//2. 놓자
			for(int j = i; j > (i - L); j--)
			{
				slide[j] = true;
			}
		}

		// 감소하는 경우 확인
		if(road[i] > road[i+1])
		{
			//높이 차이가 2 이상이면 종료
			if(road[i] - road[i+1] >= 2)
				return false;
			
			int height = road[i+1];
			for(int j = i+1; j < (i+1+L); j++)
			{
				//범위 초과하거나
				if(j >= N || slide[j] == true || road[j] != height)
					return false;
			}
			//놓을 수 있으면 
			//2. 놓자
			for(int j = i+1; j < (i+1+L); j++)
			{
				slide[j] = true;
			}

		}


	} 
	return true;

}


int main()
{
	
	scanf("%d %d", &N, &L);

	int road[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &road[i][j]);
		}
	}


	int answer = 0;
	int one_road[N];

	//row검사
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			one_road[j] = road[i][j];
		}
		answer += can_go(one_road);
	}

	for(int j = 0; j < N; j++)
	{
		for(int i = 0; i < N; i++)
		{
			one_road[i] = road[i][j];
		}
		answer +=can_go(one_road);
	}

	printf("%d", answer);



	return 0;
}