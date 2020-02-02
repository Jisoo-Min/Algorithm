#include <iostream>

using namespace std;


int answer[1001];



int main()
{
	int n;
	scanf("%d", &n);

	answer[1] = 1;
	answer[2] = 3;


	for(int i = 3; i <= n; i++)
	{
		answer[i] = answer[i-1] + (answer[i-2] * 2);
		answer[i] = answer[i] % 10007;
	}


	cout << answer[n];
	return 0;
}