#include <iostream>

using namespace std;

int main()
{
	int N, S, M;
	scanf("%d %d %d", &N, &S, &M);

	int vol[101];
	for(int i = 1; i <= N; i++)
		scanf("%d", &vol[i]);

	bool can_play[101][1001]; //곡N을 볼륨 M으로 연주할 수 있는지

	can_play[0][S] = true;


	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			if(can_play[i][j] == true){
				if(j-vol[i+1] >= 0)
					can_play[i+1][j-vol[i+1]] = true;

				if(j+vol[i+1] <= M)
					can_play[i+1][j+vol[i+1]] = true;
			}

			
		}
	} 
	//가능한 볼륨 탐색
	int answer = -1;
	for(int j = 0; j <= M; j++)
	{
		if(can_play[N][j] == true)
			answer = j;
	}

	//가능한 거 없었으면 알아서 -1 출력함
	printf("%d\n", answer);
	return 0;
}