#include <iostream>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	string ss = "";
	string tt = "";
	
	int length = s.size()*t.size();

	for(int i = 0; i < t.size(); i++)
		ss += s;
	
	for(int i = 0; i < s.size(); i++)
		tt += t;
	

	if(ss == tt)
		cout << "1";
	else
		cout << "0";


	return 0;
}