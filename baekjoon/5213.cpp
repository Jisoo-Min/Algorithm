#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
int N;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};

int tile[501][1001];

int find_num(int x, int y)
{
	int line = 2*N;
	if(x%2 == 0) //행이 홀수인경우 0, 2, 4, 6  
	{
		return ((x*line + y)/2) + (1 - (x/2));
	}
	else
	{
		if(y%2 == 1)
			return ((x*line + y)/2) + (1 - (x/2));
		else
			return ((x*line + y)/2) - x/2;
	}

}

tuple<int, int, int> find_friend(int x, int y, int tn)//tile num
{
	int nx, ny;
	nx = x;
	ny = y-1;
	//왼쪽에서 짝 찾은 경우 
	if(0<=nx && nx<N && 0<=ny && ny<(2*N) && tile[nx][ny] != -1)
	{
		if(find_num(nx, ny) == tn)
			return make_tuple(nx, ny, 0); //짝이 왼쪽
		
	}

	ny = x;
	ny = y+1;
	//오른쪽에서 짝 찾은 경우 
	if(0<=nx && nx<N && 0<=ny && ny<(2*N) && tile[nx][ny] != -1)
	{
		if(find_num(nx, ny) == tn){
			return make_tuple(nx, ny, 1); //짝이 오른쪽
		}
	}

	//return make_tuple(999,999,0); //나오진 않을거지만 임시로 넣어줌

}


int main()
{
	scanf("%d", &N);

	int from[N*N]; //대충 이정도 타일 존재

	for(int i = 0; i < N; i++)
	{	
		if(i % 2 == 0)
		{
			for(int j = 0; j < 2*N; j+=2)
				scanf("%d %d", &tile[i][j], &tile[i][j+1]);
		}
		else
		{	tile[i][0] = -1;
			for(int j = 1; j < 2*(N-1); j+=2)
				scanf("%d %d", &tile[i][j], &tile[i][j+1]);
			tile[i][2*N-1] = -1;
		}
	}


	memset(from, -1, sizeof(from));

	queue<tuple<int, int, int, int, int>> q; //타일 왼쪽, 타일 오른쪽 
	q.push(make_tuple(0, 0, 0, 1, 1)); //0,0 0,1세트는 1번 타일
	from[1] = 0; //1번째 타일 방문

	while(!q.empty())
	{
		int lx, ly, rx, ry, tn;
		tie(lx, ly, rx, ry, tn) = q.front();
		q.pop();

		//printf("NOW tile %d\n", tn);
		//왼쪽 타일에서 갈 수 있는 곳
		for(int d = 0; d < 3; d++)
		{
			int nx = lx + dx[d];
			int ny = ly + dy[d];
			//printf("check %d %d\n", nx, ny);
			//판 범위 안이여야하고 의미없는 빈 곳이 아니여야함 
			//타일과 숫자가 같아야함
			if(0<=nx && nx<N && 0<=ny && ny<2*N && tile[nx][ny] != -1 && tile[lx][ly] == tile[nx][ny])
			{	//타일 번호 알아낸 다음 체크하기 
				int next_tn = find_num(nx, ny);
				
				//방문했는지 확인하고, 방문안했으면 체크, //bfs라서 더 빨리온건지 비교안해줘도됨
				if(from[next_tn] == -1 )
				{
					from[next_tn] = tn; 
					//printf("from %d to %d\n", tn, next_tn);
					//해당 타일과 짝인 친구 찾아서 push
					int fx, fy, who;
					//printf("find frined of %d = (%d, %d)\n", next_tn, nx, ny);
					tie(fx, fy, who) = find_friend(nx, ny, next_tn);
					if(who == 0){//0왼쪽 1오른쪽
						q.push(make_tuple(fx, fy, nx, ny, next_tn));
						//printf("push tile%d  = (%d, %d) (%d, %d)\n", next_tn, fx, fy, nx, ny);
					}
					else{
						q.push(make_tuple(nx, ny, fx, fy, next_tn));
						//printf("push tile%d  = (%d, %d) (%d, %d)\n", next_tn, nx, ny, fx, fy);
					}
				}
			} 
		}

		//오른쪽 타일에서 갈 수 있는 곳 
		for(int d = 1; d < 4; d++)
		{
			int nx = rx + dx[d];
			int ny = ry + dy[d];
			//printf("right tile of %d(%d, %d) checks (%d, %d)\n", tn, rx, ry, nx, ny);
			//printf("check %d %d\n", nx, ny);
			//판 범위 안이여야하고 의미없는 빈 곳이 아니여야함 
			//타일과 숫자가 같아야함
			if(0<=nx && nx<N && 0<=ny && ny<2*N && tile[nx][ny] != -1 && tile[rx][ry] == tile[nx][ny])
			{	//타일 번호 알아낸 다음 체크하기 
				int next_tn = find_num(nx, ny);
				//printf("Next tile %d\n", next_tn);
				//방문했는지 확인하고, 방문안했으면 체크, //bfs라서 더 빨리온건지 비교안해줘도됨
				if(from[next_tn] == -1)
				{
					from[next_tn] = tn; 
					//printf("from %d to %d\n", tn, next_tn);

					//해당 타일과 짝인 친구 찾아서 push

					int fx, fy, who;
					tie(fx, fy, who) = find_friend(nx, ny, next_tn);
					//printf("find frined of %d(%d, %d) => (%d, %d)\n", next_tn, nx, ny, fx, fy);
					if(who == 0){//0왼쪽 1오른쪽
						q.push(make_tuple(fx, fy, nx, ny, next_tn));
						//printf("push tile%d  = (%d, %d) (%d, %d)\n", next_tn, fx, fy, nx, ny);
					}
					else{
						q.push(make_tuple(nx, ny, fx, fy, next_tn));
						//printf("push tile%d  = (%d, %d) (%d, %d)\n", next_tn, nx, ny, fx, fy);
					}
				}
				

			} 

		}

	}

	
	int last;
	if(N % 2 == 0)
		last = (N + N-1)*(N/2);
	else
		last = (N*(N/2+1)) + ((N-1)*(N/2));

	//마지막에 못도달할 수 있으니까 움직여줌 
	while(from[last] == -1){
		last -= 1;
	}

	//back tracking 
	

	vector<int> answer;

	while(true)
	{
		answer.push_back(last);
		last = from[last];

		if(last == 0)
			break;
	}

	cout << answer.size() << "\n";
	for(int i = answer.size()-1; i >= 0; i--){
		cout << answer[i] << " ";

	}

	return 0;
}