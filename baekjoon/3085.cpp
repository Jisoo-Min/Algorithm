#include <iostream>

using namespace std;
int n;
char board[50][50];

int solve()
{
	int ans = 1;
	//행
	for(int i = 0; i < n; i++)
	{
		int cnt = 1;
		for(int j = 0; j < n-1; j++)
		{
			if(board[i][j] == board[i][j+1])
				cnt += 1;
			else//가다가 끊임
				cnt = 1;
			
			if(ans < cnt)
				ans = cnt;
		}
	}

	//열
	for(int j = 0; j < n; j++)
	{
		int cnt = 1;
		for(int i = 0; i < n-1; i++)
		{
			if(board[i][j] == board[i+1][j])
				cnt += 1;
			else//가다가 끊임
				cnt = 1;
			if(ans < cnt)
				ans = cnt;
		}
	}

	return ans;
}


int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for(int j = 0; j < n; j++)
		{
			board[i][j] = tmp[j];
		}
	}



	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//오른쪽이랑 바꾸기
			if(j+1 < n)
			{
				//바꾸고 최댓값 찾은다음 다시 바꾸기
				swap(board[i][j], board[i][j+1]);
				int tmp_ans = solve();
				if(ans < tmp_ans)
					ans = tmp_ans;
				swap(board[i][j], board[i][j+1]);
			}
			if(i+1 < n)
			{
				swap(board[i][j], board[i+1][j]);
				int tmp_ans = solve();
				if(ans < tmp_ans)
					ans = tmp_ans;
				swap(board[i][j], board[i+1][j]);
			}
		}
	}

	cout << ans;

	return 0;
}