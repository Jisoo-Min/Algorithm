#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int main()
{

	int dir_x[4] = {1, -1, 0, 0};
	int dir_y[4] = {0, 0, -1, 1};

	int puzzle = 0;
	int zero;
	for(int i = 0 ; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			int tmp;
			scanf("%d", &tmp);
			if(tmp == 0){
				tmp = 9;
				zero = i*3 + j;
			}
			puzzle = puzzle*10 + tmp;
		}
	}


	
	queue<pair<int, int>> q; //판상태, 0의 위치
	map<int, int> time; //key value //판 상태, 횟수

	q.push(make_pair(puzzle, zero));
	time[puzzle] = 0;

	while(!q.empty())
	{
		pair<int, int> head = q.front();
		q.pop();

		//0의 위치 
		int x = (head.second)/3;
		int y = (head.second)%3;
		for(int i = 0 ; i < 4; i++)
		{
			int next_x = x + dir_x[i];
			int next_y = y + dir_y[i];
			if(0<=next_x && next_x<3 && 0<=next_y && next_y<3)
			{
				string next = to_string(head.first);
				swap(next[x*3+y], next[next_x*3+next_y]);

				int num_puzzle = stoi(next);
				if(time.count(num_puzzle) == 0)//처음 방문
				{
					q.push(make_pair(num_puzzle, next_x*3+next_y));
					time[num_puzzle] = time[head.first] + 1;
				}
			}

		}

	}

	if(time.count(123456789) == 0)
		cout << "-1";
	else
		cout << time[123456789];
	return 0;
}
