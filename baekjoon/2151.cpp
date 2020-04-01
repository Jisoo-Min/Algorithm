#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	char room[50][50];

	int door1x, door1y, door2x, door2y;
	door1x = -1;
	for(int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j < n; j++)
		{
			room[i][j] = tmp[j];
			if(room[i][j] == '#')
			{
				if(door1x == -1)
				{
					door1x = i;
					door1y = j;
				}
				else
				{
					door2x = i;
					door2y = j;
				}
			}
		}
	}

	int check[50][50];
	memset(check, -1, sizeof(check));
	//위치
	queue<tuple<int, int>> q;
	q.push(make_pair(door1x, door1y));
	check[door1x][door1y] = 0;

	while(!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		//오른쪽왼쪽아래위 다 봐 
		//오른쪽 
		for(int j = y+1; j < n; j++)
		{
			if(room[x][j] == '!' && check[x][j] == -1)//거울 놓을 수 있는 위치고, 방문한 적없으면
			{
				q.push(make_pair(x, j));
				check[x][j] = check[x][y] + 1;
			}
			else if(x == door2x && j == door2y)
			{
				cout << check[x][y];
				return 0;
			}
			else if(room[x][j] == '*') //벽 
				break;
		}
		//왼쪽
		for(int j = y-1; j >= 0; j--)
		{
			if(room[x][j] == '!' && check[x][j] == -1)//거울 놓을 수 있는 위치고, 방문한 적없으면
			{
				q.push(make_pair(x, j));
				check[x][j] = check[x][y] + 1;
			}
			else if(x == door2x && j == door2y)
			{
				cout << check[x][y];
				return 0;
			}
			else if(room[x][j] == '*') //벽 
				break;
		}
		//아래
		for(int i = x+1; i < n; i++)
		{
			if(room[i][y] == '!' && check[i][y] == -1)//거울 놓을 수 있는 위치고, 방문한 적없으면
			{
				q.push(make_pair(i, y));
				check[i][y] = check[x][y] + 1;
			}
			else if(i == door2x && y == door2y)
			{
				cout << check[x][y];
				return 0;
			}
			else if(room[i][y] == '*') //벽 
				break;
		}
		//위
		for(int i = x-1; i >= 0; i--)
		{
			if(room[i][y] == '!' && check[i][y] == -1)//거울 놓을 수 있는 위치고, 방문한 적없으면
			{
				q.push(make_pair(i, y));
				check[i][y] = check[x][y] + 1;
			}
			else if(i == door2x && y== door2y)
			{
				cout << check[x][y];
				return 0;
			}
			else if(room[i][y] == '*') //벽 
				break;
		}


	}

	cout <<"CHECK" << endl;
	for(int i = 0 ; i < n; i ++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << endl;
	}




	return 0;
}