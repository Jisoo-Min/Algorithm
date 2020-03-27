#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;


int main()
{
	int check[1601][1601];
	memset(check, -1, sizeof(check));

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int total = a + b + c;

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(a, b, c));
	check[a][b] = 0;


	bool can_make = false;
	while(!q.empty())
	{
		tie(a, b, c) = q.front();
		q.pop();
		//방문 시점에서 세개가 같은 갯수로 있는지 확인
		if(a == b && b == c)
			can_make = true;

		//a와 b교환
		if(a != b){
			if(a < b){
				if(check[a+a][b-a] == -1){
					q.push(make_tuple(a+a, b-a, c));
					check[a+a][b-a] = check[a][b] + 1;
				}
			}
			else{//b가 더 작음
				if(check[a-b][b+b] == -1){
					q.push(make_tuple(a-b, b+b, c));
					check[a-b][b+b] = check[a][b] + 1;
				}
				
			}
		}
		//b와 c교환
		if(b != c){
			if(b < c){
				if(check[a][b+b] == -1){
					q.push(make_tuple(a, b+b, c-b));
					check[a][b+b] = check[a][b] + 1;
				}
			}
			else{
				if(check[a][b-c] == -1){
					q.push(make_tuple(a, b-c, c+c));
					check[a][b-c] = check[a][b] + 1;
				}
			}
		}

		//c와 a교환
		if(c != a)
		{
			if(a < c){
				if(check[a+a][b] == -1){
					q.push(make_tuple(a+a, b, c-a));
					check[a+a][b] = check[a][b] + 1;
				}
			}
			else{
				if(check[a-c][b] == -1){
					q.push(make_tuple(a-c, b, c+c));
					check[a-c][b] = check[a][b] + 1;
				}
			}
		}
	}


	cout << can_make;
	return 0;
}