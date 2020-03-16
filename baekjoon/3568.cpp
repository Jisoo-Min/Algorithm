#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input_str;
	getline(cin, input_str);

	vector<string> declare;
	string now = "";

	for(char x : input_str)
	{
		if((x == ' ') || (x == ',') || (x == ';')){
			if(now.length() > 0){
				declare.push_back(now);
			}
			now = "";
		}else{
			now += x;
		}
		
	}

	for(int i = 1; i < declare.size(); i++)
	{
		string type = declare[0];

		string variable = declare[i];

		while(true)
		{
			if(('a' <= variable.back()) && (variable.back() <= 'z'))
				break;

			if(variable.back() == '[')
			{
				type += ']';
			}
			else if(variable.back() == ']')
			{
				type += '[';
			}
			else
			{
				type += variable.back();
			}
			variable.pop_back();
		}


 			
		cout << type << " " << variable << ";\n";

	}


	return 0;
}