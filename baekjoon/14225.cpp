#include <iostream>
#include <cstring>
using namespace std;

int N;
int nums[20];
bool check[2000001];

int min_answer = 2000000;


void dfs(int p, int sum)
{
	if(p >= N){
		check[sum] = true;
		return;
	}

	dfs(p+1, sum+nums[p]);

	dfs(p+1, sum);


}


int main()
{	
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	memset(check, 0, sizeof(check));
	dfs(0, 0);


	for(int i = 1; ;i++)
	{
		if(check[i] == false)
		{
			cout << i;
			break;
		}
	}

	return 0;
}