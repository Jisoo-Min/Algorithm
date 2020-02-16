#include <iostream>

using namespace std;

int main()
{
	int n;
	long long s;
	scanf("%d", &n);
	scanf("%lld", &s);

	int num[100001];

	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);


	int min_len = 100001;

	int left = 0;
	int right = 0;
	long long sum = num[0];

	while(left <= right && right < n){
		if(sum == s){
			if(right - left + 1 < min_len){
				min_len = right-left+1;
			}
		right += 1;
		sum += num[right];
		
				
		}else if(sum < s){
			right += 1;
			sum += num[right];
		}else if(sum > s){
			if(right - left + 1 < min_len){
				min_len = right-left+1;
			}
			sum -= num[left];
			left += 1;
		}
		
	}

	if(min_len == 100001){
		cout << "0";
		return 0;
	}
	cout << min_len;

	return 0;
}