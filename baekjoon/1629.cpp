#include <iostream>

using namespace std;
long long a, b, c;


long long calculate(int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return (a%c);


	if(n % 2 == 0)// 짝수면 
	{
		long long tmp = calculate(n/2) % c;
		return (tmp*tmp) % c;
	}
	else // 홀수면 
	{
		return ((a%c)* (calculate(n-1)%c)) % c;
	}
}

int main()
{
	scanf("%lld %lld %lld", &a, &b, &c);

	cout << calculate(b);

	return 0;
} 