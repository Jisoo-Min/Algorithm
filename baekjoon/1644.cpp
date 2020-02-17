#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	bool prime[4000001];
	memset(prime, 1, sizeof(prime));
	prime[0] = 0;
	prime[1] = 0;
	//cout << "T" << endl;

	for(int i = 2; i <= n; i++)
	{
		if(prime[i] == 1)
		{
			for(int j = i+i; j <= n; j+=i)
			{
				prime[j] = 0;
			}
		}
	}

	
	vector<int> p;
	for(int i = 0; i <= n; i++)
	{
		if(prime[i] == 1){
			p.push_back(i);
		}
	}

	if(n == 1){
		cout << "0";
		return 0;
	}
	int left = 0;
	int right = 0;

	int sum = p[0];
	int cases = 0;
	while(left<=right && right<p.size())
	{
		if(sum == n)
		{
			cases += 1;
			right += 1;
			sum += p[right];
		}else if(sum > n)
		{
			sum -= p[left];
			left += 1;
		}else if(sum < n)
		{
			right += 1;
			sum += p[right];
		}
	}

	
	cout << cases;
	
	
	return 0;
}