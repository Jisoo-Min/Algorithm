#include <iostream>

using namespace std;


int answer[1000001];


int go(int n)
{
	if(n == 1){
		answer[n] = 0;
		return 0;
	}
	if(answer[n] > 0)
	{
		return answer[n];
	}
	//1
	answer[n] = go(n-1) + 1;
	//2
	if(n%2 == 0)
	{
		int tmp = go(n/2) + 1;
		if(answer[n] > tmp){
			answer[n] = tmp;
		}
	}
	//3
	if(n%3 == 0)
	{
		int tmp = go(n/3) + 1;
		if(answer[n] > tmp){
			answer[n] = tmp;
		}
	}

	return answer[n];

}

int main()
{

	int n;
	scanf("%d", &n);

	cout << go(n);


	return 0;
}