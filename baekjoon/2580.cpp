#include <iostream>

using namespace std;
int pan[10][10];

//for checking

bool row[10][10]; // i행에 j있으면 true
bool col[10][10]; // i열에 j있으면 true
bool squ[10][10]; // i정사각형에 j있으면 true




/* 스도쿠 판 해석
0 1 2 3 4 5 6 7 8
9 10 11 12 13 14 ... 


n번째 칸 - [n/9][n%9]
(x, y) -> x*9 + y 번째 칸


사각형 위치 찾기
(x, y) = (x/3)*3 + y/3 번째 칸

*/

void show()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}

}

bool go(int num)
{
	if(num == 81){
		show();
		return true;
	}

	int i = num/9;
	int j = num%9;

	if(pan[i][j] != 0)
	{
		return go(num+1);
	}
	else // 채워야 하는 값이면 
	{
		for(int k = 1; k < 10; k++) //어떤 수로 채울까?
		{
			if(row[i][k]==0 
			&& col[j][k]==0
			&& squ[(i/3)*3+(j/3)][k] == 0)//들어갈 수 있으면 
			{
				row[i][k] = 1;
				col[j][k] = 1;
				squ[(i/3)*3+(j/3)][k] = 1;
				pan[i][j] = k;
				//cout << "now : (" << i << ", "<<j << ") = "<<  k << endl;
				if(go(num+1)){
					return true;
				}
				row[i][k] = 0;
				col[j][k] = 0;
				squ[(i/3)*3+(j/3)][k] = 0;
				pan[i][j] = 0;



			}
		}
	}

	return false;
}

int main()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			scanf("%d", &pan[i][j]);
			if(pan[i][j] != 0)
			{
				row[i][pan[i][j]] = 1;
				col[j][pan[i][j]] = 1;
				squ[(i/3)*3 + (j/3)][pan[i][j]] = 1;
			}
		}
	}

	go(0);


	
	return 0; 
}