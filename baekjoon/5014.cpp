#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);


	//총 F층인 건물 
	//G층으로 가야하고
	//현재 위치는 S층
	//위로 U칸, 아래로 D칸 이동가능
	queue<pair<int, int>> q; //현재 층과 버튼 누른 횟수

	int can_go[1000001];
	memset(can_go, -1, sizeof(can_go));

	q.push(make_pair(S, 0));
	can_go[S] = 0;

	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		int next;
		next = now.first + U;
		if(next<=F && can_go[next] == -1)
		{
			can_go[next] = now.second + 1;
			q.push(make_pair(next, now.second+1));
		}

		next = now.first - D;
		if(1<=next && can_go[next] == -1)
		{
			can_go[next] = now.second + 1;
			q.push(make_pair(next, now.second+1));
		}


	}

	if(can_go[G] == -1)
		cout << "use the stairs";
	else
		cout << can_go[G];
	return 0;
}