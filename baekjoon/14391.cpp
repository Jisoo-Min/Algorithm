#include <iostream>

using namespace std;

int n, m;
int pan[4][4];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%1d", &pan[i][j]);
		}
	}
	//가로 계산
	int answer = 0;
	for(int s = 0; s < (1<<(n*m)); s++) //여러 방법의 수 
	{
		int sum = 0;
		//가로 계산
		for(int i = 0; i < n; i++) //뭐가 가로인지 확인 
		{
			int part_sum = 0;
			for(int j = 0; j < m; j++)
			{
				int k = (i*m) + j; // 번호
				if((s & (1<<k)) == 0){//1이랑 같지 않으면 => 0인것! = 가로
					part_sum = (part_sum*10) + pan[i][j];
				}else{ //1이면 = 세로
					sum += part_sum;
					part_sum = 0;
				}
			}
			sum += part_sum;
		}

		//세로 계산
		for(int j = 0; j < m; j++) //뭐가 세로인지 확인 
		{
			int part_sum = 0;
			for(int i = 0; i < n; i++)
			{
				int k = (i*m) + j; // 번호
				if((s & (1<<k)) != 0){//0이 아닌것 10000이런식으로 나오겠지 =  세로
					part_sum = (part_sum*10) + pan[i][j];
				}else{ //0이면 = 가로
					sum += part_sum;
					part_sum = 0;
				}
			}
			sum += part_sum;
		}

		if(sum > answer)
			answer = sum;

	} 


	cout << answer;

	return 0;
}