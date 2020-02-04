#include <iostream>

using namespace std;

int answer[1001][10]; 
//row: n길이의 오르막수
//col: 마지막숫자 0-9

int main()
{


 	int n;
 	scanf("%d", &n);

	for(int i = 0; i < 10; i++)
	{
		answer[1][i] = 1; // 길이 1인 것들은 다 1가지
	}
	

	for(int i = 2; i <= n; i++)//2길이부터 1000길이까지 다 구하기
	{
		for(int j = 0; j < 10; j++)
		{
			int tmp_answer = 0;

			for(int k = 0; k <= j; k++){
				tmp_answer += answer[i-1][k];
			}
			answer[i][j] = tmp_answer % 10007;
		}
	}




	int final_answer = 0;
	for(int i = 0; i < 10; i++)
	{
		final_answer += answer[n][i];
		final_answer %= 10007;
	}

	cout << final_answer;
	return 0;
}