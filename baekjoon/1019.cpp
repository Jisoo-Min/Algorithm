#include <iostream>

using namespace std;
long long ans[10] = {0,};

//숫자 보면서 1의 자리 숫자 뭐있는지 확인
void count(long long n, long long ten)
{
	while(n > 0)
	{
		ans[n%10] += ten;
		n = n/10;
	}
}

int main()
{
	long long end;
	scanf("%lld", &end);


	long long start = 1;

	long long ten = 1; //자리수 

	while(start<=end)
	{	
		while(start % 10 != 0 && start <= end) //끝자리 0으로 맞춰주기
		{
			count(start, ten);
			start += 1;
		}

		if(start > end)
			break;

		while(end % 10 != 9 && start <= end) //끝자리 9으로 맞춰주기
		{
			count(end, ten);
			end -= 1;
		}

		long long amount = (end/10) - (start/10) + 1;
		for(int i = 0; i < 10; i++)
			ans[i] += amount*ten;

		start /= 10;
		end /= 10;
		ten *= 10;
	}



	for(int i = 0; i < 10; i++)
		cout << ans[i] << " ";


	return 0;
}