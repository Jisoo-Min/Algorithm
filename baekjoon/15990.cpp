#include <iostream>

using namespace std;


long long answer[1000001][4];
//1 : 1로 끝난 더하기
//2 : 2로 끝난 더하기
//3 : 3으로 끝난 더하기 


int main()
{


	int t;
	scanf("%d", &t);


	answer[1][1] = 1; // 1
	answer[1][2] = 0; // 
	answer[1][3] = 0; //

	answer[2][1] = 0; // 1+1(x)
	answer[2][2] = 1; // 2
	answer[2][3] = 0; // (x)

	answer[3][1] = 1; // 2+1
	answer[3][2] = 1; // 1+2
	answer[3][3] = 1; // 3

	answer[4][1] = 2; // 1+2+1 / 3+1
	answer[4][2] = 0; // 
	answer[4][3] = 1; // 1+3


	for(int i = 5; i <=100000; i++)
	{													   
		answer[i][1] = (answer[i-1][2] + answer[i-1][3]) % 1000000009LL;
		answer[i][2] = (answer[i-2][1] + answer[i-2][3]) % 1000000009LL;
		answer[i][3] = (answer[i-3][1] + answer[i-3][2]) % 1000000009LL;
	}


	
	for(int i = 0 ; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", (answer[n][1] + 
						  answer[n][2] + 
						  answer[n][3] ) % 1000000009);
	}

	return 0;
}