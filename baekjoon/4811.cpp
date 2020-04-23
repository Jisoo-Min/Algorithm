#include <iostream>

using namespace std;

int n;
int main()
{
	//약의 개수 최대 30 개 
	long long answer[31][31] = {0,};

	//알약 개수에 따라 답 채우기 
	for(int i = 1; i <= 31; i++)
		answer[0][i] = 1;

	for(int r = 1; r <= 30; r++)
	{

		//c == 0
		answer[r][0] = answer[r-1][1];

		//c >= 1
		for(int c = 1; c <= (30-r); c++)
			answer[r][c] = answer[r-1][c+1] + answer[r][c-1];

	}


	while(true)
	{
		scanf("%d", &n);
		if(n == 0)
			break;

		printf("%lld\n", answer[n][0]);

	}

	return 0;
}