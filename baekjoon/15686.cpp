#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;


vector<pair<int, int>> choosen_chicken;
int city[51][51];

int min_distance = -1;//최대는 그렇게 크지않음 100*25정도



void count()
{
	int total = 0;
	for(int h = 0; h < house.size(); h++)
	{
		int h_x = house[h].first;
		int h_y = house[h].second;

		int sub_dist = -1;
		for(int c = 0; c < M; c++)
		{
			int x_gap = h_x - choosen_chicken[c].first;
			int y_gap = h_y - choosen_chicken[c].second;
			if(x_gap < 0)
				x_gap = -x_gap;
			if(y_gap < 0)
				y_gap = -y_gap;

			if(sub_dist == -1 || sub_dist > (x_gap + y_gap))
				sub_dist = x_gap + y_gap;
		}
		total += sub_dist;
	}


	if(min_distance == -1 || min_distance > total)
		min_distance = total;
}

void dfs(int p, int cum)
{
	if(cum > M) //다 구했음 
	{
		count();
		return;
	}

	if(p >= chicken.size()) //범위 벗어나면
		return;

	choosen_chicken.push_back(chicken[p]);
	dfs(p+1, cum+1);

	choosen_chicken.pop_back();
	dfs(p+1, cum);


}
int main()
{

	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j< N; j++)
		{
			scanf("%d", &city[i][j]);
			if(city[i][j] == 1)//집
				house.push_back(make_pair(i, j));
			else if(city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}


	//치킨거리 = 집과 가장 가까운 치킨집 사이의 거리 
	dfs(0, 1); //0번째 치킨집 확인할꺼고, 1번째 치킨집 고를지 말지 결저


	cout << min_distance;
	return 0;
}