#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool alpha[30]; //어떤단어를 쓸껀지 check
string words[50]; //어떤 단어 있는지 검색

int n, k;
vector<char> c;

int answer = 0;
int dic_length;

void print_dic()
{
	cout << "DICT" << endl;
	for(int i = 0 ; i < 30; i++)
	{
		if(alpha[i] == true)
		{
			char t = i + 'a';
			cout << t << " ";
		}
	}
	//cout << endl;
}
void how_many_word_to_read()
{

	int readable = n; //못읽으면 차감하는 형식으로 하자
	for(int i = 0; i < n; i++)
	{
		//cout << "Can read: " << words[i] << "? -  ";
		if(words[i].length() == 8){//공통글자밖에 없어서 바로 읽을 수 있는 경우
			continue;
		} 
		
		for(int j = 4; j < words[i].length()-4; j++)
		{
			if(alpha[words[i][j]-'a'] == false){ //읽을 수 없는 문자면
				readable -= 1;
				//cout << "NO";
				break;

			}
		}
		//cout << "\n\n";

	}

	if(readable > answer)
		answer = readable;
}

void make_dic(int num_learnable, int idx) //
{
	//종료조건
	if(idx ==  dic_length || num_learnable == 0) //배울 수 있는 단어를 다 배웄거나, 배울 수 있는 단어 수가 없는 경우 
	{
		//print_dic();
		how_many_word_to_read();
		
		//cout << endl;
		return;
	}



	alpha[c[idx]-'a'] = true; //이 값을 딕셔너리에 넣을 것인지
	make_dic(num_learnable-1, idx+1);

	alpha[c[idx]-'a'] = false; //이값을 쓰지 않음
	make_dic(num_learnable, idx+1);

}


int main()
{
	scanf("%d %d", &n, &k);

	//k가 a, n, t, i, c 보다 작으면 아무것도 못함
	if(k<5){
		printf("0");
		return 0;
	}
	//k가 5이상아면 진행

	//cout << endl;
	for(int i = 0 ; i < n; i++)
	{
		cin >> words[i];
		for(char w : words[i])
		{
			if(w!='a' && w!='n' && w!='t' && w!='i' && w!='c'){
				c.push_back(w);
				//cout << w << endl;
			}
		}
	}

	//cout << endl;

	//5개이상이면 a n t i c 는 무조건 포함해 줘야함
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;

	//sort
	sort(c.begin(), c.end());
	//remove
	c.erase(unique(c.begin(), c.end()), c.end());

	dic_length = c.size();

	/*
	cout << "TOTAL ALPHA: " ;
	for(int i = 0; i < c.size(); i++)
		cout << c[i] << " ";
	cout << endl;
	*/

	make_dic(k-5, 0); //외울수있는 문자 수, 현재 단어사전 포인터


	cout << answer;
	return 0; 
}