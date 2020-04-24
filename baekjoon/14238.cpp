#include <iostream>
#include <cstring>

using namespace std;

bool check[51][51][51][3][3];//사용한 a,b,c개수, 마지막 2개(전꺼, 전전꺼) 
char answer[51];
string input;

int A = 0;
int B = 0; 
int C = 0;
bool go(int l, int a, int b)
{
	//종료조건
	if(l == input.size())
		return true;
	// A = 0, B = 1, C = 2

	//이미 방문했는지 체크 
	if(l>=2 && check[a][b][l-a-b][answer[l-1]][answer[l-2]] == true)
		return false;
	else if(l == 1 && check[a][b][l-a-b][answer[l-1]][0] == true)
		return false;
	else if(l == 0 && check[a][b][l-a-b][0][0] == true)
		return false;


	//방문체크 123, 
	if(l>=2)
		check[a][b][l-a-b][answer[l-1]][answer[l-2]] = true;
	else if(l == 1)
		check[a][b][l-a-b][answer[l-1]][0] = true;
	else if(l == 0)
		check[a][b][l-a-b][0][0] = true;

	// A검사 -> A은 매일 출근 가능 / 횟수가 가능한지 
	
 	if(a+1 <= A)
 	{	
 		answer[l] = 'A';
		if(go(l+1, a+1, b) == true)
			return true;
 	}
	
 	
	// B검사 -> 갯수확인, 연속근무 X 

 	if(b+1 <= B && (l == 0 || answer[l-1] != 'B')) //1번째는 바로 올 수 있음, l-1 에러방지
 	{
 		
 		answer[l] = 'B';
 		if(go(l+1, a, b+1) == true)
 			return true;
 	}


	// C검사 // 갯수확인
 	if((l-a-b)+1<= C)
 	{	
 		//2일 쉬어야함 
 		bool check = false;
 		for(int i = l-1; i >= l-2; i--)
 		{
 			if(i < 0) //범위 벗어남 
 				break;
 			if(answer[i] == 'C'){//C가 일했음
 				check = true;
 				break;
 			}

 		}

 		//지난 2일 둘다 쉬었으면 
 		if(check == false)
 		{
 			answer[l] = 'C';
 			if(go(l+1, a, b) == true)
 				return true;
 		}
 		
 	}

 	return false;
}


int main()
{
	
	cin >> input;

	int a, b, c;
	
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == 'A')
			A += 1;
		else if(input[i] == 'B')
			B += 1;
		else
			C += 1;
	}
	//cout << "A = " << A <<" B = " << B << " C = " << C << endl;


	if(go(0, 0, 0) == true)
			cout << answer;
	else
		cout << "-1";


	return 0;
}