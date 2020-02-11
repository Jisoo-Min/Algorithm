#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;


int r, c;
char pan[20][20];
int lengths[20][20];
bool visit[100];


int dir_x[4] = {0, 0, 1, -1 };
int dir_y[4] = {1, -1, 0, 0 };

int answer = 0;

void go(int i, int j, int length)
{
	//cout << "visit: (" << i << ", " << j << ")\n "; 
	visit[pan[i][j]] = true; //방문한 알파벳 체크 

	if(length > lengths[i][j]){
		lengths[i][j] = length;
	}

	for(int k = 0; k < 4; k++)
	{
		int next_x = i + dir_x[k];
		int next_y = j + dir_y[k];
		if(0<=next_x && next_x<r
			&& 0<=next_y && next_y<c) //범위안에 있고
		{
			if(visit[pan[next_x][next_y]] == false)// 방문한적없는 알파벳이면
			{
				visit[pan[next_x][next_y]] = true;
				go(next_x, next_y, length+1);
				visit[pan[next_x][next_y]] = false;
			}
		}

	}

}


int main()
{

	scanf("%d %d", &r, &c);

	for(int i = 0; i < r; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j =0; j <c; j++)
		{
			pan[i][j] = tmp[j];
		}
	}


	go(0, 0, 1);

	int max = 0;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if(lengths[i][j] > max)
				max = lengths[i][j];
		}
	}

	cout << max;

	return 0;
}