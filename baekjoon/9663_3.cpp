#include <iostream>

using namespace std;
int n;

bool check_col[15];
bool check_right_upper[40]; //row + col 값 찾기
bool check_left_upper[40]; // (row - col) + (n-1)

int answer = 0;

void go(int row)
{
	if(row == n){
		answer+=1;
		return;
	}

	for(int col = 0; col < n; col++)
	{
		if(check_col[col] == 0 
		&& check_right_upper[row+col] == 0
		&& check_left_upper[(row-col)+(n-1)] == 0)
		{
			check_col[col] = 1;
			check_right_upper[row+col] = 1;
			check_left_upper[(row-col)+(n-1)] = 1;
			go(row+1);
			check_col[col] = 0;
			check_right_upper[row+col] = 0;
			check_left_upper[(row-col)+(n-1)] = 0;
		}
	}	
}
int main()
{
	scanf("%d", &n);

	go(0);
	cout << answer;


	return 0;
}