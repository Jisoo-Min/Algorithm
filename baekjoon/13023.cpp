#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


vector<int> a[2000];
bool friends[2000];




int n, m;

bool find_relationship(int index, int count)
{
	if(count >= 4)
	{
		return true;
	}

	for(int i = 0; i < a[index].size(); i++)
	{	

		if(friends[a[index][i]] == false)//아직 방문하지 않았고  
		{
			friends[a[index][i]] = 1;
			if(find_relationship(a[index][i], count+1)) return true;
			friends[a[index][i]] = 0;
		}
		
	}

	return false;

	
}

int main()
{

	scanf("%d", &n);
	scanf("%d", &m);

	for(int i = 0; i < m; i ++)
	{
		int from, to;
		scanf("%d", &from); scanf("%d", &to);
	
		a[from].push_back(to);
		a[to].push_back(from);

		friends[from]+=1;
		friends[to]+=1;
	}

	for(int i = 0; i < n; i++)
	{
		memset(friends, false, sizeof(friends));
		friends[i] = 1;
		int answer = find_relationship(i, 0);
		friends[1] = 0;
		if(answer == true){
			printf("1");
			return 0;
		}
	}
	printf("0");

	return 0;
}