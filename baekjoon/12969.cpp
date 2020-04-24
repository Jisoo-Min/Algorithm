#include <iostream>
#include <cstring>
using namespace std;


int n, k;
bool answer[31][31][31][436]; //가능한지안한지
char str[31];

bool go(int l, int a, int b, int p) // length, a, b, pair
{
	if(l == n){ //0번째부터 시작이라서
		if(p == k)
			return true;
		else 
			return false;
	}
	//이미 찾은거는 X
	if(answer[l][a][b][p] == true) 
		return false;

	//확인했음 
	answer[l][a][b][p] = true;

	//A 넣기 
	str[l] = 'A';
	if(go(l+1, a+1, b, p) == true) 
		return true;

	//B 넣기
	str[l] = 'B';
	if(go(l+1, a, b+1, p+a) == true)
		return true;

	//C 넣기
	str[l] = 'C';
	if(go(l+1, a, b, p+a+b) == true)
		return true;

	return false;
}	


int main()
{
	scanf("%d %d", &n, &k);

	if(go(0, 0, 0, 0) == true) //0번쨰 부터 넣음 
		cout << str;
	else
		cout << "-1";

	return 0;
}