#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[1500002];
int p[1500002];
int answer[1500002] = {0,};

int main()
{
	scanf("%d", &n); 
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}

	for(int i = 1; i <= n; i++)
	{
		//이날 상담 하는 경우 
		if(i+t[i] <= n+1)
			answer[i+t[i]] = max(answer[i+t[i]], answer[i]+p[i]);


		//이날 상담 안하는 경우
		if(i+1 <= n+1)
			answer[i+1] = max(answer[i+1], answer[i]);
		
	}

	
	cout << answer[n+1];

	return 0;
}