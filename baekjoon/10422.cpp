#include <iostream>
#include <cstring>

using namespace std;
long long answer[5001];

long long go(int n)
{
	if(n == 0)
		return 1;
	else if(answer[n] >= 0)
		return answer[n];

	answer[n] = 0;
	for(int i = 2; i <= n; i+=2)
	{
		answer[n] += go(i-2) * go(n-i);
		answer[n] %= 1000000007;
	}

	return answer[n];
}

int main()
{
	int L;
	scanf("%d", &L);

	int testcases[L];
	for(int i = 0; i < L; i++)
		scanf("%d", &testcases[i]);

	
 	memset(answer, -1, sizeof(answer));


 	go(5000);


	for(int i = 0; i < L; i++)
	{
		if(testcases[i] % 2 == 0)
			printf("%lld\n", answer[testcases[i]]);
		else
			printf("0\n");
	}

	return 0;
}


/*


1. ()를 겉에 싸주는 것
2. () () 처름 concat하는 것


*/