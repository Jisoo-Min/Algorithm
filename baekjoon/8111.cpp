#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int n;
		scanf("%d", &n);

		int from[n];
		int how[n];
		int dist[n];
		memset(from, -1, sizeof(from));
		memset(how, -1, sizeof(how));
		memset(dist, -1, sizeof(dist));

		queue<int> q;
		q.push(1%n);
		dist[1%n] = 1; // 처음시작 길이 
		how[1%n] = 1;  // 처음에

		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			//추가할 숫자 0 또는 1 
			for(int i = 0; i <= 1; i++)
			{
				int next = (now*10+i)%n; //수를 만들고 나머지 기록
				if(dist[next] == -1) //방문 안했으면 
				{
					dist[next] = dist[now] + 1;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}

		if(dist[0] == -1) //아무도 여기까지 가서 정답을 만들지 못함
			printf("BRAK\n");
		else{
			string answer = "";
			//방문하지않은점을 만날때까지 계속
			for(int i = 0; i!=-1; i=from[i])
			{
				answer += to_string(how[i]);
			}
			reverse(answer.begin(), answer.end());
			cout << answer << "\n";
		}

	}

	return 0;
}