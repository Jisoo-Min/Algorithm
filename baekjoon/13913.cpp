#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int check[100001];
	int from[100001];

	memset(check, -1, sizeof(check));


	queue<int> q;
	q.push(n);
	check[n] = 0;


	while(!q.empty())
	{
		int head = q.front();
		q.pop();

		if(head == k)
			break;
		if(head+1 <= 100000 && check[head+1] == -1){
			q.push(head+1);
			check[head+1] = check[head]+1;
			from[head+1] = head; 
			
		}
		if(head-1 >= 0 && check[head-1] == -1){
			q.push(head-1);
			check[head-1] = check[head]+1;
			from[head-1] = head; 
		
		}
		if(head*2 <= 100000 && check[head*2] == -1){
			q.push(head*2);
			check[head*2] = check[head]+1;
			from[head*2] = head; 
		}
	}

	int path[100001];
	int idx = k;
	for(int i = check[k]; i>=0; i--)
	{
		path[i] = idx;
		idx = from[idx];
	}
	cout << check[k] << "\n";
	for(int i = 0; i <= check[k]; i++)
		cout << path[i] << " ";
	
	return 0;
}
