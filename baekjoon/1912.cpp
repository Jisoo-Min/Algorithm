#include <iostream>


using namespace std;

int nums[100001];
long long answers[100001];

int main()
{
	int n; 
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &nums[i]);
	}


	answers[0] = nums[0];

	for(int i =1; i < n; i++)
	{

		if(answers[i-1] + nums[i] < nums[i])
			answers[i] = nums[i];
		else
			answers[i] = answers[i-1] + nums[i];
	} 

	long long max = answers[0];
	for(int i = 1; i < n; i++)
	{
		if(max < answers[i])
			max = answers[i];
	}



	printf("%lld", max);
	return 0;
}