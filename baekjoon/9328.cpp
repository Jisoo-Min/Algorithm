#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t++)
	{
		int h, w;
		scanf("%d %d", &h, &w);
		char building[102][102];
		bool visit[102][102];
		bool keys[26];
		memset(building, 0, sizeof(building));
		memset(visit, 0, sizeof(visit));
		memset(keys, 0, sizeof(keys));

		for(int i = 1; i <= h; i++)
		{
			string tmp;
			cin >> tmp;
			for(int j = 1; j <= w; j++)
			{
				building[i][j] = tmp[j-1];
			}
		}
		//이미 가지고 있는 열쇠
		string k;
		cin >> k;
		if(k[0]!='0'){
			for(int i = 0; i < k.size();i++)
			keys[k[i]-'a'] = k[i];
		}

		int answer = 0;

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		visit[0][0] = true;

		int dir_x[4] = {1, -1, 0, 0};
		int dir_y[4] = {0, 0, 1, -1};
		//열지못한 문 저장
		queue<pair<int, int>> door[26];
		while(!q.empty())
		{
			pair<int, int> now = q.front();
			q.pop();

			for(int d = 0; d < 4; d++)
			{
				int nx = now.first + dir_x[d];
				int ny = now.second+ dir_y[d];
				if(0<=nx && nx <= h+1 && 0<= ny && ny <= w+1
				&& visit[nx][ny] == false)//범위내에있고, 방문안했으면
				{	
					//cout << "visit: " << nx << ", "<< ny << endl;
					if('a'<=building[nx][ny] && building[nx][ny] <= 'z')
					{
						keys[building[nx][ny]-'a'] = true;
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));

						//이전에 못갔던 문을 열 수 있는 지 확인 // 문여러개 일 수도 있음 
						int a = building[nx][ny]-'a';
						
						while(!door[a].empty())
						{
							q.push(door[a].front());
							door[a].pop();
						}
						
					}
					else if('A'<=building[nx][ny] && building[nx][ny] <= 'Z')
					{
						if(keys[building[nx][ny]-'A'] == true)//키가 있으면
						{
							visit[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
						else
						{
							visit[nx][ny] = true;
							//열지 못한 문 추가// 같은 문이 여러개 일 수도 있음 
							door[building[nx][ny]-'A'].push(make_pair(nx, ny)); 
						}
					}
					else if(building[nx][ny] == '$')
					{
						visit[nx][ny] = true;
						//cout << "find a key" << endl;
						answer += 1;
						q.push(make_pair(nx, ny))
;
					}
					else if(building[nx][ny] == '.' || building[nx][ny] == 0)
					{
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}

				}
			}

		}

		printf("%d\n", answer);

	}

	return 0;
}