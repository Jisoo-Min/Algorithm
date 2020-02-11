#include <iostream>

using namespace std;
int n;
int ans = 0;
int pan[15][15];

bool check(int row, int col) //놓는데, 위의 row랑 겹치는지 확인 
{
	//위에 
	for(int i = 0; i < row; i++)
	{
		if(pan[i][col] == 1)
			return false;
	}

	//왼쪽 위 대각선
	int tmp_col = col-1;
	for(int i = row-1; i >= 0; i--)
	{	
		if(tmp_col < 0)
			break;
		if(pan[i][tmp_col] == 1) //범위 벗어나거나, 퀸있으면
			return false;
		tmp_col--;
	}

	tmp_col = col+1;
	for(int i = row-1; i >= 0; i--)
	{	
		if(tmp_col >= n)
			break;
		if(pan[i][tmp_col] == 1) //범위 벗어나거나, 퀸있으면
			return false;

		tmp_col++;
	}

	return true;
	//오른쪽 위 대각선
}

void calc(int row)
{
	// 0 ~ n-1 행
	if(row == n)
	{
		ans += 1;
	}

	for(int col = 0; col < n; col++)
	{
		pan[row][col] = true; //일단 퀸 놓고 
		if(check(row, col)) // 놓을 수 있는 자리 인가? 
		{
			calc(row+1);
		}
		pan[row][col] = false;
	}
}


int main()
{

	scanf("%d", &n);

	calc(0);

	cout << ans;


	return 0;
}