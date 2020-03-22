#include <iostream>
#include <cstring>
using namespace std;
int triangle[401][801];//400 줄 최대 : 200*(2 + (399)*2)
int s[401][801];
int answer;
int num_lines;
void find_max_triangle(int row, int left, int right, int sum)
{
	if((row < 1) || row > num_lines)
		return;
	if((left < 1) || (right > ((2*row)-1)))
		return;
 
	sum +=(s[row][right] - s[row][left-1]);
	if(sum > answer)
		answer = sum;

	if(left % 2 == 0)
		find_max_triangle(row-1, left-2, right, sum);
	else
		find_max_triangle(row+1, left, right+2, sum);	
}


int main()
{
	int time = 1;

	while(true)
	{
		scanf("%d", &num_lines);

		if(num_lines == 0)
			break;

		answer = -16000000;
		memset(s, 0, sizeof(s));
		//(항의개수)((첫쨰항)+(마지막항))/2


		for(int i = 1; i <= num_lines; i++)
		{
			for(int j = 1; j <= (i*2-1); j++)
			{
				scanf("%d", &triangle[i][j]);
				s[i][j] = s[i][j-1] + triangle[i][j];
			}
		}


		for(int i = 1; i <= num_lines; i++)
		{
			for(int j = 1; j <= (i*2-1); j++)
			{
				find_max_triangle(i, j, j, 0); //합이 0임
			}
		}


		cout << time << ". " << answer << "\n";
		time += 1;
	}


	return 0;
}