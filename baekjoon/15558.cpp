#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int line[2][100001];
	bool visit[2][100001];
	memset(visit, 0, sizeof(visit));

	//왼쪽줄 오른쪽줄 상태
	for(int i = 1; i <= n; i++){
		scanf("%1d", &line[0][i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%1d", &line[1][i]);
	}


	
	//지금 어디에 있는지(몇째줄, 몇번칸), 지금 몇초인지
	queue<tuple<int, int, int>> q;

	q.push(make_tuple(0, 1, 0));

	int answer = 0;
	while(!q.empty())
	{
		tuple<int, int, int> now = q.front();
		q.pop();
		int line_num = get<0>(now);
		int position = get<1>(now);
		int time 	 = get<2>(now);

		
		//다 넘어간 경우 => 정답

		//앞으로 이동 // 가능한지 확인 후 -> 이동
		if(position+1 <= n  //범위안에 있고
		&& visit[line_num][position+1] == false //방문 안했고 
		&& line[line_num][position+1] == 1 //안전한 칸이고 
		&& position+1 > time+1) //안사라진 칸이어야함
		{
			q.push(make_tuple(line_num, position+1, time+1));
			visit[line_num][position+1] = true;
		}else if(position+1 > n)
		{
			answer = 1;
			break;
		}
		//뒤로 이동
		if(position-1 >= 1 //범위 안에 있고
		&& visit[line_num][position-1] == false //방문 안했고 
		&& line[line_num][position-1] == 1 //안전한 칸이고 
		&& position-1 > time+1) //안사라진 칸이어야함
		{
			q.push(make_tuple(line_num, position-1, time+1));
			visit[line_num][position-1] = true;
		}else if(position-1 > n)
		{
			answer = 1;
			break;
		}

		//반대편으로 이동
		if(position+k <= n //범위 안에 있고 
		&& visit[1-line_num][position+k] == false //방문 안했고 
		&& line[1-line_num][position+k] == 1 //안전한 칸이고 
		&& position+k > time+1) //안사라진 칸이어야함
		{
			q.push(make_tuple(1-line_num, position+k, time+1));
			visit[1-line_num][position+k] = true;
		}else if(position+k > n)
		{
			answer = 1;
			break;
		}
	}

	printf("%d", answer);

	return 0;
}