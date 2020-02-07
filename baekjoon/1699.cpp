#include <iostream>

using namespace std;

long long answers[100001] = {0,};

int main()
{	
	int n;
	scanf("%d", &n);

	 
	for(int i = 1; i <= n; i++)
	{
		answers[i] = i;//각 값의 기본 값은 자기 자신 -> 1만 계속 더한것
		//제일 작은 제곱수부터 비교해서 채우자
		for(int j = 1; j*j <= i; j++)
		{
			if(answers[i] > answers[i-(j*j)] + 1)
				answers[i] = answers[i-(j*j)] + 1;
		}

	}

	cout << answers[n];

	return 0;
}