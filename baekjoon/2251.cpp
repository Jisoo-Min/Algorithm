#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	vector<int> answer;

	int total = c;

	bool water[201][201];

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	water[0][0] = true;

	while(!q.empty())
	{
		pair<int, int> head = q.front();
		q.pop();
		//물양 
		int t_a = head.first;
		int t_b = head.second;
		int t_c = total - t_a - t_b;
		if(t_a == 0){//a가 비어있으면 c의 양 구하기 
			answer.push_back(t_c);
			//cout << "Answer: ";
		}
		//cout << t_a << " " << t_b << " " << t_c << endl;
		
		if(t_b + t_a > b){ //a를 b에 붓기  -> 넘친다 
			if(water[t_a-(b-t_b)][b] == false){ //a를 b에 붓기
				q.push(make_pair(t_a-(b-t_b), b));
				water[t_a-(b-t_b)][b] = true;
			}
		}else{ 
			if(water[0][t_b+t_a] == false){ //a를 b에 붓기
				q.push(make_pair(0, t_b+t_a));
				water[0][t_b+t_a] = true;
			}
		}

		if(t_a + t_b > a){ //b를 a에 붓기  -> 넘친다
			if(water[a][t_b-(a-t_a)] == false){//b를 a에 붓기
				q.push(make_pair(a, t_b-(a-t_a)));
				water[a][t_b-(a-t_a)] = true;
			}
		}else{
			if(water[t_a+t_b][0] == false){//b를 a에 붓기
				q.push(make_pair(t_a+t_b, 0));
				water[t_a+t_b][0] = true;
			}
		}

		if(t_c + t_a > c){ //a를 c에 붓기
			if(water[t_a-(c-t_c)][t_b] == false){ //a를 c에 붓기
				q.push(make_pair(t_a-(c-t_c), t_b));
				water[t_a-(c-t_c)][t_b] = true;
			}

		}else{
			if(water[0][t_b] == false){ //a를 c에 붓기
				q.push(make_pair(0, t_b));
				water[0][t_b] = true;
			}

		}

		if(t_a + t_c > a){ //c를 a에 붓기
			if(water[a][t_b] == false){//c를 a에 붓기
				q.push(make_pair(a, t_b));
				water[a][t_b] = true;
			}
		}else{ 
			if(water[t_a+t_c][0] == false){//c를 a에 붓기
				q.push(make_pair(t_a+t_c, 0));
				water[t_a+t_c][0] = true;
			}
		}


		if(t_c + t_b > c){ //b를 c에 붓기 
			if(water[t_a][t_b-(c-t_c)] == false){ //b를 c에 붓기
				q.push(make_pair(t_a, t_b-(c-t_c)));
				water[t_a][t_b-(c-t_c)] = true;
			}
		}else{
			if(water[t_a][0] == false){ //b를 c에 붓기
				q.push(make_pair(t_a, 0));
				water[t_a][0] = true;
			}
		}


		if(t_b + t_c > b){//c를 b에 붓가
			if(water[t_a][b] == false){//c를 b에 붓기
				q.push(make_pair(t_a, b));
				water[t_a][b] = true;
			}
		}else{ 
			if(water[t_a][t_b+t_c] == false){//c를 b에 붓기
				q.push(make_pair(t_a, t_b+t_c));
				water[t_a][t_b+t_c] = true;
			}
		}

	}

	//정답 출력

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	for(int i = 0 ; i < answer.size(); i++)
		cout << answer[i] << " ";


	return 0;
}