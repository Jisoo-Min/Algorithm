#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int D(int num)
{
	num = num * 2;
	if(num<=9999)
		return num;
	else
		return num % 10000;
}

int S(int num)
{
	num = num-1;
	if(num >= 0)
		return num;
	else
		return 9999;

}

int L(int num)
{
	return (num%1000)*10 + (num/1000);
}

int R(int num)
{
	return (num/10) + (num%10)*1000;
}



int main()
{
	

	int t;
	scanf("%d", &t);
	int from[10000]; //어디서 온건지 기록 
	char how[10000];

	for(int i = 0; i < t; i++)
	{
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));

		int before; int after;
		scanf("%d %d", &before, &after);

		from[before] = before; // 처음은 처음에서 옴
		how[before] = 'B'; //시작점 begin


		queue<int> q;
		q.push(before);
		
		while(!q.empty())
		{

			int head = q.front();
			q.pop();
			//cout << "Head: " << head << endl;


			int next;
			next= D(head);
			if(how[next] == 0){ //방문하지 않았으면 
				from[next] = head;
				how[next] = 'D';
				q.push(next);
				//cout << "Next D: " << next << endl;

			} 

			next = S(head);
			if(how[next] == 0){ //방문하지 않았으면 
				from[next] = head;
				how[next] = 'S';
				q.push(next);
				//cout << "Next S: " << next << endl;

			}

			next = L(head);
			if(how[next] == 0){ //방문하지 않았으면 
				from[next] = head;
				how[next] = 'L';
				q.push(next);
				//cout << "Next L: " << next << endl;

			}

			next = R(head);
			if(how[next] == 0){ //방문하지 않았으면 
				from[next] = head;
				how[next] = 'R';
				q.push(next);
				//cout << "Next R: " << next << endl;

			}

		}

		int idx = after;
		string answer = "";
		while(how[idx] != 'B')
		{
			answer = how[idx] + answer;
			idx = from[idx];
		}

		cout << answer << endl;

		
	}




	return 0;
}