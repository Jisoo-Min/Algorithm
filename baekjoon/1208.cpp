#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n, s;
	scanf("%d %d", &n, &s);

	int num[40];

	vector<int> left_half(1<<n/2);
	vector<int> right_half(1<<(n-(n/2)));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &num[i]);
	}

	for(int i = 0 ; i < (1<<(n/2)); i++)
	{
		for(int j = 0; j < (n/2); j++)
		{
			if(i&(1<<j)){ //0이 아니면 -> 1이 하나라도 있는거
				left_half[i] += num[j];
			}

		}
	}

	for(int i = 0; i < (1 << (n-(n/2))); i++)
	{
		for(int j = 0 ; j < (n-(n/2)); j++)
		{
			if(i&(1<<j)){
				right_half[i] += num[j+(n/2)];
			}
		}
	}



	sort(left_half.begin(), left_half.end());
	sort(right_half.begin(), right_half.end());

	int left = 0 ;
	int right = right_half.size() - 1;

	long long answer = 0 ;
 
 	while(left < left_half.size() && right >= 0)
	{
		if(left_half[left] + right_half[right] == s)
		{
			long long c_l = 1;
			long long c_r = 1;
			left+=1;
			right-=1;
			//left꺼 갯수세기
			while(left < left_half.size() && left_half[left] == left_half[left-1])
			{
				c_l += 1;
				left+= 1;
			}

			//right꺼 갯수세기
			while(right >= 0 && right_half[right] == right_half[right+1])
			{
				c_r += 1;
				right -= 1;
			}
			answer += (c_l * c_r);
		}else if(left_half[left] + right_half[right] > s)
		{	
			right-=1;
		}else if(left_half[left] + right_half[right] < s)
		{
			left += 1;
		}
	}

	if(s==0) answer-=1;
	cout << answer;
	return 0;

}