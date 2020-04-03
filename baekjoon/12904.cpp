#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	
	for(int i = t.size()-1; i >= s.size(); i--)
	{	
		if(t[i] == 'A')
		{
			t.pop_back();
		}
		else // B 
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if(s == t)
		cout << "1";
	else
		cout << "0";
	return 0;
}