#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int result[10][10];
int n;
bool visit[21];
int ans[10];

/* 조건 검사 */
bool possible(int idx)
{	
	int sum = 0;
	for(int i = idx; i >= 0; i--)
	{
		sum += ans[i];
		if(sum < 0  && result[i][idx]!= -1)
			return 0;
		if(sum == 0 && result[i][idx]!= 0)
			return 0; 
		if(sum > 0  && result[i][idx]!= 1)
			return 0;
	}
	return 1;
}



int go(int idx)
{
	
	//종료조건 
	if(idx == n) 
		return true;

	//계속 조건 뭐 넣을지: 자기 자신의 부호 판단 
	//1. 0이면 0을 넣자
	//2. +/-이면 1부터 10까지 / -1부터 -10까지
	if(result[idx][idx] == 0){
		return possible(idx) && go(idx+1);
	}
	else if(result[idx][idx] < 0){
		for(int i = -10; i <= -1; i++)
		{
			ans[idx] = i;
			if(possible(idx) && go(idx+1))
				return true;

		}

	}else if(result[idx][idx] > 0){
		for(int i = 1; i <= 10; i++)
		{
			ans[idx] = i;
			if(possible(idx) && go(idx+1))
				return true;
		}
	}

	return false;
}

int main()
{
		
	scanf("%d", &n);

	string s;
	cin >> s;

	int idx = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(s[idx] == '-'){
				result[i][j] = -1;
				idx++;
			}
			else if(s[idx] == '+'){
				result[i][j] = 1;
				idx++;
			}
			else if(s[idx] == '0'){
				result[i][j] = 0;
				idx++;
			}
		}
	}

	

	go(0);
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

	return 0;
}