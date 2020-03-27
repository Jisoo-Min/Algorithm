#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;


int N, M;
char board[11][11];
int check[11][11][11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int rx, ry, bx, by, hx, hy;
//정답 찾았는지 
int go(int now_rx, int now_ry, int now_bx, int now_by, 
	    int& next_rx, int& next_ry, int& next_bx, int& next_by, int d) 
{
	next_rx = now_rx; 
	next_ry = now_ry; 
	next_bx = now_bx; 
	next_by = now_by;
	while(board[next_rx+dx[d]][next_ry+dy[d]] != '#') //다음이 벽이 아니면
	{
		next_rx += dx[d];
		next_ry += dy[d];
	}

	while(board[next_bx+dx[d]][next_by+dy[d]] != '#') //다음이 벽이 아니면
	{
		next_bx += dx[d];
		next_by += dy[d];
	} 
	//cout << "go (" << next_rx << ", " << next_ry << "), (" << next_bx << ", " <<next_by <<")\n";
	bool dropr = false;
	bool dropb = false;

	//공에 빠졌는지 
	//안빠졌으면 움직이는데, 같은 곳에 위치해 있으면 정상적으로 옮겨주기
	if(d == 0) //오른쪽으로 기울기 
	{
		if(next_rx == hx && now_ry <= hy && hy <= next_ry) //x확인, y사이에 홀있는지 확인
			dropr = true;
		if(next_bx == hx && now_by <= hy && hy <= next_by)
			dropb = true;

		if(next_rx == next_bx && next_ry == next_by) //둘이 같은 위치에 있으면 원래대로
		{
			if(now_ry < now_by)
				next_ry -= 1;
			else
				next_by -= 1;
		}
	}else if(d == 1)//왼쪽으로 기울기 
	{
		if(next_rx == hx && next_ry <= hy && hy <= now_ry) //x확인, y사이에 홀있는지 확인
			dropr = true;
		if(next_bx == hx && next_by <= hy && hy <= now_by)
			dropb = true;
		if(next_rx == next_bx && next_ry == next_by)
		{
			if(now_ry < now_by)
				next_by += 1;
			else
				next_ry += 1;
		}
	}else if(d == 2)//위로 기울기 
	{
		if(next_ry == hy && next_rx <= hx && hx <= now_rx) //y확인, x사이에 홀있는지 확인
			dropr = true;
		if(next_by == hy && next_bx <= hx && hx <= now_bx)
			dropb = true;
		if(next_rx == next_bx && next_ry == next_by)
		{
			if(now_rx < now_bx)
				next_bx += 1;
			else
				next_rx += 1;
		}
	}else if(d == 3)//아래로 기울기
	{
		if(next_ry == hy && now_rx <= hx && hx <= next_rx) //y확인, x사이에 홀있는지 확인
			dropr = true;
		if(next_by == hy && now_bx <= hx && hx <= next_bx)
			dropb = true;
		if(next_rx == next_bx && next_ry == next_by)
		{
			if(now_rx < now_bx)
				next_rx -= 1;
			else
				next_bx -= 1;
		}
	}
	//cout << "Drop " << dropr << "  " << dropb <<"\n";

	if(dropb == true) //불가능한 경우 
	{
		return -1;
	}

	if(dropr == true) //정답찾은 경우
	{
		return 1;
	}

	//그 외의 경우는 
	return 0;

}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j < M; j++)
		{
			board[i][j] = tmp[j];
			if(board[i][j] == 'R')
			{	
				rx = i; ry = j;
			}
			else if(board[i][j] == 'B')
			{
				bx = i; by = j;
			}
			else if(board[i][j] == 'O')
			{
				hx = i; hy = j;
			}
		}
	}



	// cout << "Red (" << rx << ", " << ry << ")\n"; 
	// cout << "Blue (" << bx << ", " << by << ")\n"; 
	// cout << "Hole (" << hx << ", " << hy << ")\n"; 
	memset(check, -1, sizeof(check));

	queue<tuple<int, int, int, int>> q; //red, blue, time
	check[rx][ry][bx][by] = 0;
	q.push(make_tuple(rx, ry, bx, by));

	bool find_answer = false;
	int answer = -1;	
	while(!q.empty())
	{
		tie(rx, ry, bx, by) = q.front();
		q.pop();

		//cout << "\nNow (" << rx << ", " << ry << "), " << "(" << bx << ", " << by << ")\n";
		for(int d = 0; d < 4; d++)
		{
			int nrx, nry, nbx, nby; 
			int result = go(rx, ry, bx, by, nrx, nry, nbx, nby, d);
	
			if(result == -1) //파란공이 빠진 경우
				continue;
			if(result == 1){ //정답 찾은 경우
				find_answer = true;
				answer = check[rx][ry][bx][by] + 1;
			}
			if(result == 0){ //다음 진행
				if(check[nrx][nry][nbx][nby] == -1){//방문안했을떄만
					check[nrx][nry][nbx][nby] = check[rx][ry][bx][by] + 1;
					q.push(make_tuple(nrx, nry, nbx, nby));
					//cout << "Next (" << nrx << ", " << nry << "), " << "(" << nbx << ", " << nby << ")\n";
				}

			}

			
		}

		if(find_answer == true)
			break;
	}


	cout << answer;

	return 0;
}


/*
#######
#.,.RB#
#.#####
#R....#
#####.#
#O....#
#######
*/