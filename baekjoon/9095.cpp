#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int add_num(int n, int sum)
{

	int count = 0;
	if(sum == n) return 1;
	if(sum < n){
		count += add_num(n, sum+1);
		count += add_num(n, sum+2);
		count += add_num(n, sum+3);

	}
	
	return count;
}



int main()
{

	int num_int;
	cin >> num_int;

	int n;
	for(int i = 0; i < num_int; i++){
		cin  >> n;
		cout << add_num(n, 0)<< "\n";
	}

	return 0;
}