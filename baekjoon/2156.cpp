#include <iostream>

using namespace std;

int grape[10001] = {0,};
long long answer[10001][3] = {0,};

int main()
{
	
	int total_glass;
	scanf("%d", &total_glass);

	for(int i = 1; i <= total_glass; i++)
	{
		scanf("%d", &grape[i]);
	}


	answer[1][0] = 0; //한잔째인데, 안골라
	answer[1][1] = grape[1]; //한잔째인데, 골라
	answer[1][2] = 0; //한잔째인데 2잔일 수 없지


	answer[2][0] = grape[1]; //첫번째꺼고르고,지금안골라-> 이게 2잔쨰일 떄 안먹으면서 최대
	answer[2][1] = grape[2]; //지금 처음 먹어야함
	answer[2][2] = grape[1] + grape[2]; //연속 두잔 먹어야함 


	for(int i = 3; i <= total_glass; i++)
	{
		//0: 지금 안먹을꺼야 
		long long max0 = answer[i-1][0];
		if(max0 < answer[i-1][1])
			max0 = answer[i-1][1];
		if(max0 < answer[i-1][2])
			max0 = answer[i-1][2];

		answer[i][0] = max0;

		answer[i][1] = answer[i-1][0] + grape[i];

		answer[i][2] = answer[i-1][1] + grape[i];

	}

	long long max = answer[total_glass][0];
	if(max < answer[total_glass][1])
		max = answer[total_glass][1];
	if(max < answer[total_glass][2])
		max = answer[total_glass][2];
	cout << max;



	return 0;
}

//연속 0잔인 경우 //지금 안먹어
//연속 1잔인 경우 //지금먹었을 때
//연속 2잔인 경우 //지금먹었을 때