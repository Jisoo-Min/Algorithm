#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int time[100001]; //해당 위치까지 걸린 최소시간
	//visit과 같이 쓰기위해, 초를 1초씩 늘림 
	int how_many[100001]; //해당 위치에 최소시간 걸리는게 몇개나 있니


	queue<int> q;
	q.push(n);
	time[n] = 1;
	how_many[n] = 1;

	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		if(now+1 <= 100000)
		{
			if(time[now+1] == 0 || time[now]+1 < time[now+1])//한번도 간적없거나 더 짧은 경로로왔으면
			{
				time[now+1] = time[now]+1;
				how_many[now+1] = 1; //처음 방문
				q.push(now+1);
			}else if(time[now]+1 == time[now+1])//이 전과 같은 속도로옴
			{
				how_many[now+1] += 1;
				q.push(now+1);
			}
			//더 먼 경로오 왔을 경우 추가하지 않음
		}

		if(now-1 >= 0)
		{
			if(time[now-1] == 0 || time[now]+1 < time[now-1])
			{
				time[now-1] = time[now] + 1;
				how_many[now-1] = 1;
				q.push(now-1);
			}else if(time[now]+1 == time[now-1])
			{
				how_many[now-1] += 1;
				q.push(now-1);
			}
		}

		if(now*2 <= 100000)
		{
			if(time[now*2] == 0 || time[now]+1 < time[now*2])
			{
				time[now*2] = time[now]+1;
				how_many[now*2] = 1;
				q.push(now*2);
			}else if(time[now]+1 == time[now*2])
			{
				how_many[now*2] += 1;
				q.push(now*2);
			}
		}
	}

	//나중에 답에서 1초 뺴줘야함 <- 시작을 1초로 해줘서
	cout << time[k]-1 << "\n";
	cout how_many[k;


	return 0;
}