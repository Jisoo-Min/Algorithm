#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int ability[21][21];

vector<int> team1;
vector<int> team2;
int n;
int min_gap = 999999999;

void calculate(int t1_size, int t2_size)
{

	int t1 = 0;
	int t2 = 0;
	for(int i = 0; i < t1_size; i++)
	{
		for(int j = i+1; j < t1_size; j++)
		{
			t1 += ability[team1[i]][team1[j]];
			t1 += ability[team1[j]][team1[i]];
		}
	}

	for(int i = 0; i < t2_size; i++)
	{
		for(int j = i+1; j < t2_size; j++)
		{
			t2 += ability[team2[i]][team2[j]];
			t2 += ability[team2[j]][team2[i]];
		}
	}

	int gap = t1 - t2;
	if(gap < 0)
		gap = -gap;

	if(min_gap > gap)
		min_gap = gap;

}
void dfs(int p)
{
	if(p > n){
		if(team1.size() > 1 && team2.size() > 1){
			calculate(team1.size(), team2.size());
		}

		return;
	}

	team1.push_back(p);
	dfs(p+1);
	team1.pop_back();

	team2.push_back(p);
	dfs(p+1);
	team2.pop_back();

}


int main()
{
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d",&ability[i][j]);
		}
	}

	dfs(1);


	printf("%d", min_gap);
	return 0;
}