#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int symbols[10];
int k;

vector<string> answers;

int check[10];


bool can_do(char before, char after, int op){
	if(op == 1 ){//<
		if(before < after){
			return true;
		}
	}else{//>
		if(before > after){
			return true;
		}
	}
	return false;
}

void go(int idx, string ans)
{
	//종료조건
	if(idx == k+1){ //k번쨰까지는 채워야함
		answers.push_back(ans);
		return;
	}
	//불가능
	//계속
	for(int i = 0; i <= 9; i++)
	{	
		if(check[i]==0) // 방문하지 X
		{
			if(idx == 0 || can_do(ans[idx-1], i+'0', symbols[idx-1]))//처음 들어온건 무조건 넣어줘 && 조건에 맞으면
			{
				check[i] = 1;
				go(idx+1, ans+to_string(i));
				check[i] = 0;
			}
		}
	}
}

int main()
{

	cin >> k;

	for(int i = 0; i < k; i++)
	{
 		char symbol;
 		cin >> symbol;
 		if(symbol == '<'){
 			symbols[i] = 1;
 		}
 		else{
 			symbols[i] = 0;
 		}
	}


	go(0, ""); 

	auto minmax = minmax_element(answers.begin(), answers.end());
	cout << *minmax.second << "\n" << *minmax.first;
}

