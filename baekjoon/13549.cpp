#include<iostream>
#include<queue>
#include<deque>
#include<cstring>
using namespace std;



int main()
{
	int a, b;
	scanf("%d %d", &a, &b);


	deque<int> q;
	int visit[100001];

	memset(visit, -1, sizeof(visit));

	

	if(a == b){
		cout << "0";
		return 0;
	}


	visit[a] = 0;
	q.push_front(a);


	while(!q.empty())
	{
		int head = q.front();
		q.pop_front();


		
		if(head*2 <= 100000)
		{
			if(visit[head*2] == -1)
			{
				q.push_front(head*2);
				visit[head*2] = visit[head];
			}
		}

		if(head+1 <= 100000){
			if(visit[head+1] == -1){
				visit[head+1] = visit[head] + 1;
				q.push_back(head+1);
			}  //아직방문안했으면 	
		}
		
		if(head-1 >= 0){
			if(visit[head-1] == -1){
				visit[head-1] = visit[head] + 1;
				q.push_back(head-1);
			}
		}
			


	}

	cout << visit[b];

	
	return 0;
}
