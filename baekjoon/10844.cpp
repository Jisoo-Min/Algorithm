#include <iostream>

using namespace std;


long long answer[101][10]; //row: 길이(n) / col: 마지막 수 

int main()
{

	answer[1][0] = 0;
	for(int i = 1; i < 10; i++){
		answer[1][i] = 1;
	}

	answer[2][0] = 1; //10 
	answer[2][1] = 1; //21
	answer[2][2] = 2; //12 / 32
	for(int i = 3; i < 9; i++){
		answer[2][i] = 2;
	}  
	answer[2][9] = 1; 


	for(int i = 3; i <=100; i++) // n에 맞는 숫자 구하기
	{
		for(int j = 0; j < 10; j++) //마지막수가 0부터 9까지 모두 구하기
		{
			long long tmp_answer = 0;
			if(j-1 >= 0)
			{
				tmp_answer += answer[i-1][j-1];
			}

			if(j+1 <= 9)
			{
				tmp_answer += answer[i-1][j+1];
			}

			answer[i][j] = tmp_answer % 1000000000;
		}
	}



	int n;
	scanf("%d", &n);

	long long final_answer = 0;

	for(int i = 0; i <= 9; i++)
	{
		final_answer += answer[n][i];
		final_answer %= 1000000000;
	}
	cout << final_answer;


	return 0;
}