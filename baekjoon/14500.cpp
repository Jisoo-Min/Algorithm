#include <iostream>

using namespace std;


int paper[500][500];

int find_max(int max_sum, int now_sum){
	if(max_sum < now_sum)	return now_sum;
	else return max_sum;
}
int main()
{
	int row, col;
	cin >> row >> col;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> paper[i][j];
		}
	}

	int max_sum = 0;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(j<= col-4){
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-4){
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-2 && j<=col-2){ //square
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-3 && j <= col-2){ //orange1
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-2 && j <= col-3){//2
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-3 && j <= col-2){//3
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if( i >= 1 && j <= col-3){//4
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i-1][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i>=2 && j <= col-2){ //5
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i-1][j+1] + paper[i-2][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-2 && j <= col-3){//6
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-3 && j <= col-2){//7
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-2 && j <= col-3){//8
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<= row-3 && j <= col-2){ //green1
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i>=1 && j <= col-3){//2
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i-1][j+1] + paper[i-1][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i <= row-2 && j <= col-3){//3
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i>=2 && j <= col-2){//4
				int now_sum = paper[i][j] + paper[i-1][j] + paper[i-1][j+1] + paper[i-2][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i <= row-2 && j <= col-3){//pink1
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i>=1 && i <= row-2 && j <= col-2){//2
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i-1][j+1] + paper[i+1][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i>= 1 && j <= col-3){//3
				int now_sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i-1][j+1];
				max_sum = find_max(max_sum, now_sum);
			}
			if(i<=row-3 && j <= col-2){//4
				int now_sum = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1];
				max_sum = find_max(max_sum, now_sum);
			}



		}
	}

	cout << max_sum << endl;


	return 0;
}