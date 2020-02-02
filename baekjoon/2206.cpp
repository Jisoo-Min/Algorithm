#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
int map[1001][1001]; // 가로세로, 벽뚫었는지
int t[1001][1001][2];

using namespace std;


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);


	memset(map, -1, sizeof(map));
	memset(t, -1, sizeof(t));

	int dir_x[4] = {0, 0, 1, -1};
	int dir_y[4] = {1, -1,0,  0 };

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	queue<tuple<int, int, int>> q; 
	t[1][1][0]= 1;
	t[1][1][1]= 1;
	q.push(make_tuple(1, 1, 0));

	
 	if(n == 1 && m == 1){
 		cout<< '1';
 		return 0;
 	}

 	while(!q.empty())
 	{
 		tuple<int, int, int> head = q.front();
 		q.pop();

 		for(int i = 0; i < 4; i++)
 		{
 			int next_x = get<0>(head) + dir_x[i];
 			int next_y = get<1>(head) + dir_y[i];

 			if(1 <= next_x && next_x <= n && 1 <= next_y && next_y <= m) //범위에 포함
 			{
 				if(map[next_x][next_y] == 0 && t[next_x][next_y][get<2>(head)] == -1) // 길이 뚫려 있고, 방문한 적 없으면
 				{
 					t[next_x][next_y][get<2>(head)] = t[get<0>(head)][get<1>(head)][get<2>(head)] + 1;
 					q.push(make_tuple(next_x, next_y, get<2>(head)));
 				}
 				if(get<2>(head) == 0 && map[next_x][next_y] == 1 && t[next_x][next_y][1] == -1) // 길 막혀있고, 처음 가는 경우
 				{
 					t[next_x][next_y][1] = t[get<0>(head)][get<1>(head)][0] + 1;
 					q.push(make_tuple(next_x, next_y, get<2>(head)+1));
 				}
 			}
 		}	
 	}


	if(t[n][m][0] == -1 && t[n][m][1] != -1)
		cout << t[n][m][1];
	else if(t[n][m][0] != -1 && t[n][m][1] == -1)
		cout << t[n][m][0];
	else if(t[n][m][0] == -1 && t[n][m][1] == -1)
		cout << "-1";
	else{
		if(t[n][m][0] < t[n][m][1])
			cout << t[n][m][0];
		else
			cout << t[n][m][1];
	}

	return 0;
}


	/*
	cout << "0th" << endl;x

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << t[i][j][0] << " ";
		}
		cout << endl;
	}

	cout << "1th" << endl;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout << t[i][j][1] << " ";
		}
		cout << endl;
	}
	*/

/*

5 5
0 0 0 0 0
1 1 1 1 0
1 0 0 0 0
1 0 1 1 1
1 0 0 0 0


5 5
0 0 0 0 0
1 1 1 1 0
1 0 0 0 1
1 0 1 1 1
1 0 0 0 0
*/
