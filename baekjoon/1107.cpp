#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


bool not_working[10];

int can_go(int num)
{
	if(num == 0) {
		if(not_working[num] == true) //0을 누를 수 없으면
			return 0; 
		else 
			return 1; // 0누를 수 있으면 1번 누르면 됨
	}

	int length = 0;
	while(num > 0)
	{
		if(not_working[num%10] ){ //못누름
			return 0; 
		}
		length += 1;
		num /= 10;
	}

	return length;
}

int main()
{
	int n;
	scanf("%d", &n);

	int remote;
	scanf("%d", &remote);

	int num;
	for(int i = 0; i< remote; i++){
		scanf("%d", &num);
		not_working[num] = true;
	}


	int answer = n - 100;
	if(answer<0)
		answer = -answer;

	
	for(int i = 0; i <= 1000000; i++)
	{
		int click = can_go(i);
		if(click > 0) //갈 수 있으면
		{
			int press = n - i;
			if(press < 0)
				press = -press;

			if(click+press < answer)
				answer = click + press;
		}
	}

	printf("%d", answer);

	return 0;
}
