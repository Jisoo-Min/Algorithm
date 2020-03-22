#include <iostream>
#include <cstring>
using namespace std;

int C, P;
int height[101];

int answer = 0;

bool check(int start, string tet)
{


	if(start + tet.size() -1 >= C) //범위 확인
		return 0;

	int base = height[start] - (tet[0] - '0');
	for(int j = 0; j < tet.size(); j++)
	{
		if(base != (height[start + j] - (tet[j] - '0')) )
			return 0;
	}

	return 1;
}
int main()
{
	scanf("%d %d", &C, &P);

	for(int i = 0 ; i < C; i++)
		scanf("%d", &height[i]);

	for(int i = 0; i < C; i++){
		if(P == 1)
		{
			answer += check(i, "0");
			answer += check(i, "0000");
		}
		else if(P == 2)
		{
			answer += check(i, "00");
		}
		else if(P == 3)
		{
			answer += check(i, "001");
			answer += check(i, "10");
		}
		else if(P == 4)
		{
			answer += check(i, "100");
			answer += check(i, "01");
		}
		else if(P == 5)
		{
			answer += check(i, "000");
			answer += check(i, "101");
			answer += check(i, "01");
			answer += check(i, "10");
		}
		else if(P == 6)
		{
			answer += check(i, "000");
			answer += check(i, "00");
			answer += check(i, "20");
			answer += check(i, "011");
		}
		else if(P == 7)
		{
			answer += check(i, "000");
			answer += check(i, "00");
			answer += check(i, "02");
			answer += check(i, "110");
		}
	}
	

	cout << answer;
	return 0;
}

