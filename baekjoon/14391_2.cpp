#include <iostream>
#include <cstring>
using namespace std;

int pan[4][4];
bool type[4][4];
bool visit[4][4];

int n, m;
int answer = 0;

void show()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << type[i][j] << " ";
		}
		cout << "\n";
	}

}

void cal()
{
	memset(visit, 0, sizeof(visit));
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(visit[i][j] == false)//방문안했을 때만
			{
				int t = type[i][j]; //얘랑 똑같은 애만 찾아서 유지할꺼임

				int x = i;
				int y = j;

				int part_sum = 0;
				while(type[x][y] == t && x < n && y < m)
				{
					part_sum = part_sum*10 + pan[x][y];
					visit[x][y] = true;
					if(t==1) //세로면
					{
						x++;
					}else{ //가로면
						y++;
					}
				}
				sum += part_sum;
			} 
		}
	}

	if(sum > answer)
		answer = sum;


}

void make_pan(int x, int y)
{
	if(x >= n || y >= m)
	{
		//show();
		cal();
		return;
	}
	
	//현재를 0으로 만들기
	type[x][y] = 0;
	if(y+1 < m)
	{
		make_pan(x, y+1);
	}else{//y+1 = m이면 x+1 해줘야함
		make_pan(x+1, 0);
	}
	

	//현재를 1로 만들기
	type[x][y] = 1;
	if(y+1 < m)
	{
		make_pan(x, y+1);
	}else{//y+1 = m이면 x+1 해줘야함
		make_pan(x+1, 0);
	}
	
	

}


int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d", &pan[i][j]);
		}
	}

	make_pan(0, 0);

	cout << answer ;
	return 0;
}