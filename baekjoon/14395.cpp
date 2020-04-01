#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int main()
{
	long long limit = 1000000000LL;

	long long s, t; 
	scanf("%lld %lld", &s, &t);
	//둘이 같은 경우 종료 
	
	if(s == t){
		cout << "0";
		return 0;
	}


	set<long long> visit;

	queue<pair<long long, string>> q;
	q.push(make_pair(s, "")); //처음 숫자 
	visit.insert(s);

	while(!q.empty())
	{
		long long x; string how;
		tie(x, how) = q.front();
		q.pop();

		//t와 x가 같은지 확인 -> 출력 후 종료 

		if(x == t){
			cout << how;
			return 0;
		}

		if(x*x <= limit && visit.count(x*x) == 0)//범위체크 //이미 방문했는지 확인
		{
			q.push(make_pair(x*x, how+"*")); // 큐에 넣어주고 
			visit.insert(x*x);//방문 체크 
		}
		if(x+x <= limit && visit.count(x+x) == 0)
		{
			q.push(make_pair(x+x, how+"+"));
			visit.insert(x+x);	
		}
		if(visit.count(0) == 0) //빼기는 항상 0이니까 
		{
			q.push(make_pair(x-x, how+"-"));
			visit.insert(x-x);	
		}
		//나누기도 해줘야되는게 처음 S로 만든게 T가 넘었어도 1부터 다시 찾아볼 수 있게 해줘야함 
		if(x != 0 && visit.count(1) == 0) //나누기는 항상 1
		{
			q.push(make_pair(x/x, how+"/"));
			visit.insert(x/x);	
		}
	}


	cout << "-1"; //못만드는 경우 출력 

	return 0;
}