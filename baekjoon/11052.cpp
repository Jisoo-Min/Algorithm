#include <iostream>

using namespace std;

int p[10001];
int answer[10001];

int main()
{

	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}

	answer[0] = 0;
	answer[1] = p[1];


	for(int i = 2; i <= n; i++) //정답 저장할꺼
	{
		int small_answer = 0;
		for(int j = 0; j < i; j++)
		{
			int tmp_answer = answer[j] + p[i-j];\
			if(small_answer < tmp_answer){
				small_answer = tmp_answer;
			}
		}
		answer[i] = small_answer;
	}



	cout << answer[n];



	return 0;
}

/*
1번 정답 

2번정답 -> 1번정답 + 1/ 2번정답 + 0

3번정답 -> 1번정답 + 2 / 2번정답 + 2 / 3번정답 + 0

4번정답 -> 1번정답 + 3 / 2번정답 + 2 / 3번정답 + 1 / 4번정답 + 0

5번정답 -> 1번정답 + 4 / 2번정답 + 3 / 3번정답 + 2 / 4번정답 + 1
*/