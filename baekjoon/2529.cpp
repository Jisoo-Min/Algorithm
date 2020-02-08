#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int symbol[10];


vector<int> big;
vector<int> small;


int main()
{
	int k; 
	scanf("%d", &k);


	for(int i = 0; i < k; i++)
	{
		char c;
		cin >> c;
		if(c == '<')
			symbol[i] = 1;
		else
			symbol[i] = 2;
	}

	for(int i = 9; i >= 9-k; i--)
		big.push_back(i);
	
	for(int i = 0; i <= k; i++)
		small.push_back(i);
	




	do{
		int cnt = 0;
		for(int i = 0; i < k; i++)
		{ 
			if(symbol[i] == 1){ //큰 부등호
				if(big[i] < big[i+1]){
					cnt++;
				}
				else 
					break;
			}else{ // 작은 부등호
				if(big[i] > big[i+1])
					cnt++;
				else	
					break;
			}
		}
		
		if(cnt == k){
			break;
		}

	}while(prev_permutation(big.begin(), big.end()));

	do{
		int cnt = 0;
		for(int i = 0; i < k; i++)
		{ 
			if(symbol[i] == 1){ //큰 부등호
				if(small[i] < small[i+1]){
					cnt++;
				}
				else 
					break;
			}else{ // 작은 부등호
				if(small[i] > small[i+1])
					cnt++;
				else	
					break;
			}
		}
		
		if(cnt == k){
			break;
		}

	}while(next_permutation(small.begin(), small.end()));


	for(int i = 0; i <= k; i++)
		cout << big[i];
	cout << "\n";
	for(int i = 0; i <= k; i++)
		cout << small[i];


	return 0;
}