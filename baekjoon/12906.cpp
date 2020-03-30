#include <iostream>
#include <queue>
#include <map>
#include <array>

using namespace std;

int main()
{

	array<string, 3> start;
	for(int i = 0; i < 3; i++)
	{
		int tmp_int; 
		scanf("%d", &tmp_int); 

		if(tmp_int > 0)
			cin >> start[i];
		else
			start[i] = "";
	}


	array<string, 3> num_stick = {"", "", ""};
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < start[i].size(); j++)
		{
			if(start[i][j] == 'A')
				num_stick[0].push_back('A');
			else if(start[i][j] == 'B')
				num_stick[1].push_back('B');
			else  // C
				num_stick[2].push_back('C');
		}
	}

	
	map<array<string, 3>, int>  visit; //key value

	queue<array<string, 3>> q;
	q.push(start);
	visit[start] = 0; //map에

	while(!q.empty())
	{
		array<string, 3> now = q.front();
		q.pop();
		//i -> j 옮기기 
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(i != j && now[i].size() > 0)
				{
					array<string, 3> next(now); //값 복사
					next[j].push_back(next[i].back());
					next[i].pop_back();
					if(visit.count(next) == 0) //next key에 해당하는 value가 없는 경우
					{
						visit[next] = visit[now] + 1;
						q.push(next);
					}
				}
			}
		}

	}



	cout << visit[num_stick];


	return 0;
}