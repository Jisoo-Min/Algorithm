#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int num[4][4000];
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &num[0][i], &num[1][i], &num[2][i], &num[3][i]);

	}

	//(A, B)쌍
	vector<int> ab;
	for(int a = 0; a < n; a++)
	{
		for(int b = 0; b < n; b++)
		{
			ab.push_back(num[0][a] + num[1][b]);
			
		}
	}

	//(C, D)쌍
	vector<int> cd;
	for(int c = 0; c < n; c++)
	{
		for(int d = 0; d < n; d++)
		{
			cd.push_back(num[2][c] + num[3][d]);
		}
	}

	//sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long long answer = 0;
	for(int i = 0 ; i < ab.size(); i++)
	{
		auto p = equal_range(cd.begin(), cd.end(), -ab[i]);
		answer += p.second - p.first;
	}

	cout << answer;

	return 0;
}