#include <iostream>

using namespace std;


long long answer[100][2]; 
//row: n
//col: 0이면 0으로 끝난거, 1이면 1로 끝난거

int main()
{

	long long n;
	scanf("%lld", &n);

	answer[1][0] = 0; //0 (x)
	answer[1][1] = 1; //1 (o)

	answer[2][0] = 1; //10
	answer[2][1] = 0; //01 (x)

	answer[3][0] = 1; //[2][0] + [2][1] // 100
	answer[3][1] = 1; //[2][0] + 1      // 101
	

	for(int i = 4; i<=n; i++)
	{
		answer[i][0] = answer[i-1][0] + answer[i-1][1];
		answer[i][1] = answer[i-1][0];
	}


	cout << answer[n][0]+answer[n][1];
	return 0;
}
