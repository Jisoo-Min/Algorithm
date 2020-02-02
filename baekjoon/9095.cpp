#include <iostream>

using namespace std;


long long answer[1000001];

long long inputs[1000001];


int main()
{

	long long t, n;
	scanf("%d", &t);

	for(int i = 0; i < t; i++)
	{
		cin >> inputs[i];
	}


	answer[0] = 1;
	answer[1] = 1;
	answer[2] = 2;
	answer[3] = 4;


	for(int i = 4; i < 1000001; i++)
	{
		answer[i] = answer[i-3] + answer[i-2] + answer[i-1];
		answer[i] %= 1000000009;
	}

	// 1

	// 1 1
	// 2

	// 1 1 1
	// 1 2
	// 2 1
	// 3


	for(int i = 0; i < t; i++)
	{
		printf("%d\n", answer[inputs[i]]);
	}

	return 0;
}