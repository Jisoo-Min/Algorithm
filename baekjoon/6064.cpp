#include <iostream>

using namespace std;

int main()
{

	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){

		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);

	
		//y == n 이 같아버리면 나머지가 0이 되버려서 26줄 조건 만족 못하니
		//0으로 바꿔준 것 
		if(y == n){
			y = 0;
		}


		bool flag = 0;
		for(int j = 0; j <= n; j+=1){
			int tmp_y = x + m * j;
			
			if(tmp_y % n == y)
			{
				cout << tmp_y << "\n";
				flag = 1;
				break;
			}

		}

		if(flag == 0)
			cout << "-1" << "\n";

	}
	return 0;
}