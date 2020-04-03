#include <iostream>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int num[n+1];
	int sum[n+1];
	sum[0] = 0;

	for(int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1];
		sum[i] += num[i];
	}


	for(int t = 0; t < m; t++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		cout << sum[e] - sum[s-1] << "\n";
	}


	return 0;
}