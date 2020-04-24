#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int n;
int scv[3] = {0, 0, 0};
int ans = -1;
int check[61][61][61]; //a,b,c의 남은 체력 

void go(int t, int a, int b, int c)
{

	//(정답) 모두 다 0보다 작은 경우 
	if(a <= 0 && b <= 0 && c <= 0)
	{
		if(ans == -1 || ans > (t-1))
			ans = t-1;

		return;
	}

	//음수인 경우 0으로 바꿔줌
	if(a < 0)
		a = 0;

	if(b < 0)
		b = 0;

	if(c < 0)
		c = 0;


	if(check[a][b][c] != -1)
		return;

	check[a][b][c] = t; 


	//3개니까 방법은 6가지 3! 
	if(a > 0){
		//1. abc
		go(t+1, a-9, b-3, c-1);
		//2. acb 
		go(t+1, a-9, b-1, c-3);
	}

	if(b > 0)
	{
		//3. bac 
		go(t+1, a-3, b-9, c-1);
		//4. bca
		go(t+1, a-1, b-9, c-3);
	}	

	
	if(c > 0)
	{	//5. cab
		go(t+1, a-3, b-1, c-9);
		//6. cba
		go(t+1, a-1, b-3, c-9);
	}

}


int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &scv[i]);

	memset(check, -1, sizeof(check));
	//fill(&check[0][0][0], &check[60][60][60]+1, -1);

	go(1, scv[0], scv[1], scv[2]);//1번째로 뿌순다


	cout << ans;

	return 0;
}