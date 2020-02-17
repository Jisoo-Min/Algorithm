#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	long long t;
	int n, m;
	scanf("%lld", &t);


	int a[1000];
	scanf("%d", &n);
	for(int i = 0 ; i < n; i ++)
	{
		scanf("%d", &a[i]);
	}

	int b[1000];
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}


	vector<long long> v_a;
	vector<long long> v_b;


	//v_a채우기 = 부분합
	for(int i = 0 ; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{

			sum += a[j];
			v_a.push_back(sum);
		}
	}


	//v_b채우기 = 부분
	for(int i = 0 ; i < m; i++)
	{
		long long sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += b[j];
			v_b.push_back(sum);
		}
	}


	sort(v_a.begin(), v_a.end());
	sort(v_b.begin(), v_b.end());


	long long answer = 0;
	/*
	for(int i = 0; i < v_a.size(); i++)
	{
		auto p = equal_range(v_b.begin(), v_b.end(), t-v_a[i]);
		answer += p.second-p.first;
	}
	*/
	//위와 동일 코드
	int left = 0; //pointer for a
	int right = v_b.size()-1;//point for b

	while(left < v_a.size() && right>=0) //0은 제외하니 빼고 
	{
	
		if(v_a[left] + v_b[right] == t)
		{

			long long l = 1;
			long long r = 1;
			left += 1;
			right -= 1;
			//같은l찾기
			while(left < v_a.size() && v_a[left] == v_a[left-1]){
				l += 1;
				left+=1;
			}

			//같은r찾기
			while(right >=0 && v_b[right] == v_b[right+1]){
				r += 1;
				right-=1;
			}
			answer += (l*r);
		}
		else if(v_a[left] + v_b[right] < t)
		{
			left += 1;
		}
		else if(v_a[left] + v_b[right] > t)
		{
			right -= 1;
		}
	}
	
	cout << answer;

	return 0;
}