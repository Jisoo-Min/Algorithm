#include <iostream>
#include <queue>
#include <cstring>
using namespace std;



int window_emo = 1;
int clip_emo = 0;
int s;
int t[1001][1001];

queue<pair<int, int>> q; // window, clip


int bfs()
{
	t[window_emo][clip_emo] = 0;
	q.push(make_pair(window_emo, clip_emo));


	while(!q.empty())
	{	
		pair<int, int> head = q.front();
		q.pop();

		//1

		int now_wind = head.first;
		int now_clip = head.second;

		if(now_wind == s)
				return t[now_wind][now_clip];

		if(t[now_wind][now_wind] == -1) //아직 방문 안했으면 
		{
			t[now_wind][now_wind] = t[now_wind][now_clip] + 1;
			q.push(make_pair(now_wind, now_wind));


		}

		//2
		if(now_wind+now_clip <= 1000 && t[now_wind + now_clip][now_clip] == -1)
		{
			t[now_wind + now_clip][now_clip] = t[now_wind][now_clip] + 1;
			q.push(make_pair(now_wind + now_clip, now_clip));
		}

		//3
		if(now_wind-1 >= 0 && t[now_wind-1][now_clip] == -1)
		{
			t[now_wind-1][now_clip] = t[now_wind][now_clip] + 1;
			q.push(make_pair(now_wind-1, now_clip));
		}






	}

	return 0;

}

int main()
{
	scanf("%d", &s);

	memset(t, -1, sizeof(t));
	cout << bfs() ;




	return 0;
}