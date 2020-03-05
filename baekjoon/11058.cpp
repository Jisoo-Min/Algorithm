#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	long long answer[n+1];
	memset(answer, -1, sizeof(answer));


	answer[1] = 1;

	for(int i = 1; i <= n; i++)
	{
		//A를 출력
		if(i+1 <= n){//범위 확인
			if(answer[i+1] == -1  //방문한적 없거나 
			|| answer[i] + 1 > answer[i+1]) //A추가 한게 더 작으면 
			{
				answer[i+1] = answer[i] + 1;
			}
		}
	
		//전체선택 -> 버퍼복사 -> 출력 
		if(i+3 <= n) //범위 확인 
		{
			if(answer[i+3] == -1 //방문한적 없거나
			|| answer[i]*2 > answer[i+3])
			{
				answer[i+3] = answer[i]*2;
			}

			if(i+4<=n){
				long long copy_size = answer[i];
				int paste = 2;
				for(int k = i+4; k <= n; k++)
				{
					if(answer[k] == -1 //방문한적 없거나
					|| answer[i] + (copy_size*paste) > answer[k])
					{
						answer[k] = answer[i] + (copy_size*paste);
					}	
					paste += 1;

				}
			}
			
		}
	}

	printf("%lld", answer[n]);

	return 0;
}