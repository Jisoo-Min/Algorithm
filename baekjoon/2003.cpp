#include <iostream>

using namespace std;
int num[10001];

int main()
{

	int n;
	long long m;
	scanf("%d", &n);
	scanf("%lld", &m);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}


	int cases = 0;

	for(int i = 0; i < n; i++)
	{
		long long sum = 0;
		for(int j = i; j < n; j++)
		{
			sum+=num[j];
			if(sum == m){
				cases+=1;
				break;
			}
		}
	}

	cout << cases;


	return 0;
}