#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool check(string answer){
	int ja = 0;
	int mo = 0;
	for(char c : answer)
	{
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'){
			mo += 1;
		}
		else{
			ja += 1;
		}
	}
	if(mo >= 1 && ja >=2)
		return true;
	else
		return false;
}

void choose_password(int n, vector<char> alpha, string password, int i)
{
	if(password.length() == n){
		if(check(password)){
			cout << password << "\n";;
		}
		
		return;
		
	}

	if(i == alpha.size()){
		return;
	}
		choose_password(n, alpha, password+alpha[i], i+1);
		choose_password(n, alpha, password, i+1);
	

}


int main()
{

	int n, m;
	cin >> n >> m;

	vector<char> alpha(m);

	for(int i = 0; i < m; i ++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	choose_password(n, alpha, "", 0);


	return 0;
}