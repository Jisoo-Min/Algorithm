#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);


	int num[n+1];
	num[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
		num[i] += num[i-1];
		num[i] %= m;
	}

	
	long long remains[m];
	memset(remains, 0, sizeof(remains));
	for(int i = 1; i <= n; i++){
		remains[num[i]%m] += 1;
	}

	long long ans = remains[0]; //혼자부분수열인 것
	for(int i = 0; i < m; i++)
	{
		if(remains[i] != 0)
		 	ans += (remains[i]*(remains[i]-1))/2;
	}


	cout << ans;
	return 0;
} 