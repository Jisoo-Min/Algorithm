#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{

	int col, row;

	char room[21][21];

	scanf("%d %d", &col, &row);

	while(true){

		memset(room, 0, sizeof(room));

		vector<pair<int, int>> dirts(1); //더러운 곳 저장

		int r_x, r_y;
		for(int i = 0 ; i < row; i++){
			string tmp;
			cin >> tmp;
			for(int j = 0; j < col; j++){
				room[i][j] = tmp[j];
				if(room[i][j] == '*'){//더러운 칸
					dirts.push_back(make_pair(i, j));
				}
				else if(room[i][j] == 'o'){
					dirts[0] = make_pair(i, j);
					r_x = i;
					r_y = j;
				}	
			}
		}
		//각 spot 사이의 거리 구하기 = 미리 로봇, 먼지들 사이 거리 구하기
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};

		int num_spot = dirts.size();
		int length[11][11];
		memset(length, 0, sizeof(length));
		//i에서 j로 가는 경로
		for(int i = 0 ; i < num_spot; i++)
		{
			for(int j = i+1; j < num_spot; j++)
			{
				int step[21][21]; 
				memset(step, -1, sizeof(step));
				queue<pair<int, int>> q;
				//시작 점 -> i 
				q.push(make_pair(dirts[i].first, dirts[i].second));
				//시작을 1로하고 마지막에 1 빼주기
				step[dirts[i].first][dirts[i].second] = 0;

				while(!q.empty())
				{
					pair<int, int> now = q.front(); q.pop();
					for(int d = 0; d < 4; d++)
					{
						int nx = now.first + dx[d];
						int ny = now.second+ dy[d];
						if(0<=nx && nx<row && 0<=ny && ny<col
						&& step[nx][ny] == -1
						&& room[nx][ny] != 'x')
						{
							step[nx][ny] = step[now.first][now.second] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
				/*
				cout << "spot " << i << " to " << j << "   ";
				cout << "From : (" << dirts[i].first << ", "<<  dirts[i].second;
				cout << ") To  : (" << dirts[j].first << ", "<<  dirts[j].second;
				cout << ") length: " << step[dirts[j].first][dirts[j].second] << endl;
				*/
				length[j][i] = step[dirts[j].first][dirts[j].second];
				length[i][j] = step[dirts[j].first][dirts[j].second];
				
			}
		}
		
		//방문 순서를 결정하기 위한 배열 - 먼지들의 개수만큼 
		vector<int> v;
		for(int i = 1; i < num_spot; i++)
			v.push_back(i); 
		
		/*
		cout << "\nDirts num "<< endl;
		for(int i = 0; i < num_spot - 1; i++)
			cout << v[i] << " ";
		cout << endl; 
		cout << "\nDirts position"<< endl;

		for(int i = 1; i < dirts.size(); i++)
			cout << "(" << dirts[i].first << ", " << dirts[i].second << ")" << " ";
		cout << endl; 
		*/

		
		bool flag = false;
		int answer = col * row * num_spot; //대략 최대
		do{
			int start = 0;
			int tmp_answer = 0;
			for(int i = 0; i < v.size(); i++)
			{
				if(length[start][v[i]] == -1){ //갈수있는방법X
					flag=true;
					break;
				}
				tmp_answer += length[start][v[i]];
				start = v[i];
			}
			if(flag == true) //갈 수 없는 루트면 
				break;

			if(tmp_answer < answer)
				answer = tmp_answer;
		}while(next_permutation(v.begin(), v.end()));


		if(flag == true)
			printf("-1\n");
		else
			printf("%d\n", answer);
		


		scanf("%d %d", &col, &row);
		if(col == 0 && row == 0)
			break;

	}

	return 0;
}