#include <iostream>
#include <string>
using namespace std;


int t[15];
int p[15];
int n;

int money = -1;

void profit(int now_date, int now_profit)
{
	if(now_date >= n){ //마지막까지오면
		if(now_profit > money){
			money = now_profit;
		}
		return;
	}

	if(now_date+t[now_date] <= n){
		profit(now_date+t[now_date], now_profit+p[now_date]);
	}else{
		profit(now_date+t[now_date], now_profit);
	}

	//오늘꺼 선택 X 
	profit(now_date+1, now_profit);

}


int main()
{

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> t[i] >> p[i];
	}

	profit(0, 0);
	cout << money ;

	return 0;
}

