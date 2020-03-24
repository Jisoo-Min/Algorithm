#include <iostream>

using namespace std;
int n;
int marble[10];

int answer = -1;
void energy(int marble[], int m, int sum)//m은 총 길이
{
	if(m==2)
	{
		if(sum > answer)
			answer = sum;
		return;
	}

	//값 복사
	int tmp_pan[10];
	for(int i = 0; i < 10; i++)
		tmp_pan[i] = marble[i];


	for(int i = 1; i < m-1; i++)
	{
		for(int j = 0; j < i; j++)
			tmp_pan[j] = marble[j];
		for(int j = i; j <= m-1; j++)
			tmp_pan[j] = marble[j+1];
		// for(int j = m; j < 10; j++)//얘는 안해도되긴하겠다.
		// 	tmp_pan[j] = 0;
		energy(tmp_pan, m-1, sum + (marble[i-1]*marble[i+1]));
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &marble[i]);

	energy(marble, n, 0);

	cout << answer;

	return 0;
}