#include <iostream>
#include <queue>

using namespace std;


int visit[1000] = {0,};
vector<int> edges[1000];
queue<int> q;


int n, m;


int num_area = 0;

void bfs(int h)
{
	q.push(h);
	visit[h] = 1;

	while(!q.empty())
	{
		int head = q.front();
		q.pop();
		for(int i = 0; i < edges[head].size(); i++)
		{
			int num = edges[head][i];
			if(visit[num] == false){
				visit[num] = true;
				q.push(num);
			}
		}
	}
}



int main()
{
	scanf("%d", &n);
	scanf("%d", &m);


	for(int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d", &from);
		scanf("%d", &to);

		edges[from-1].push_back(to-1);
		edges[to-1].push_back(from-1);

	}
	int count = 0;
	for(int i = 0; i < n; i ++)
	{
		if(visit[i] == 0){
			bfs(i);
			count +=1;
		}
	}

	printf("%d", count);
	return 0;
}