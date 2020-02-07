#include<iostream>


using namespace std;


int num_length(long long n)
{
	int len = 0;
	while(n>0)
	{
		n /= 10;
		len+= 1;	
	}
	return len;
}


int main()
{


	int n;
	scanf("%d", &n);

	int answer = 0;

	int len =  num_length(n);



	int mul = 10;

	for(int i = 1; i <= len; i++)
	{
		if(n >= mul){
			answer += (mul - mul/10) * i;
		}else{ // n < mul
			answer += (n - mul/10 + 1) * i;
		}	
		mul *= 10;
	}

	cout << answer;

	return 0;
}