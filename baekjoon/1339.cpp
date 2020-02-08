#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


string word[10];
vector<char> alpha;

int match[256]; // 알파벳 아스키 A-Z = 65-90

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		cin >> word[i];

		for(char w : word[i]){
			alpha.push_back(w);
		}
	}


	sort(alpha.begin(), alpha.end()); // 소트를 하고 중복제거하면 좀 빠른가보다
	//unique는 중복된 값 뒤로 밀어버리고, 쓰레기 값의 첫번째 위치를 반환
	//그로부터 마지막까지 지워주면 -> 중복제거 끝!
	alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());

	int unique_alpha_len = alpha.size();

	vector<int> num;
	for(int i = 9; i > 9-unique_alpha_len; i--)
		num.push_back(i);


	int max = 0;
	do
	{	
		//해쉬마냥 바로 값 ㅍ찾게 만들기
		for(int i = 0; i < unique_alpha_len; i++)
		{
			match[alpha[i]] = num[i]; // ex) match['A'] = 9 
		}

		int sum = 0;
		for(int i = 0 ; i < n; i++) //각 단어에 대해서
		{
			int tmp_sum = 0;
			for(int j=0; j < word[i].size(); j++)//단어의 값을 찾자
			{
				tmp_sum = tmp_sum*10 + match[word[i][j]];
			}
			sum += tmp_sum;
		}


		if(sum > max)
			max = sum;

	}while(prev_permutation(num.begin(), num.end()));

	printf("%d", max); 

	return 0;
}