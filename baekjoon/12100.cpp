#include <iostream>

using namespace std;
int n;


//우, 좌, 상, 하 
int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};

int max_block = 0;

void show(int p[][20])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
			
		}
		cout << endl;
	}
}
void calculate(int p[][20])
{
	int max_v = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			//cout << pan[i][j] << " ";
			if(p[i][j] > max_v){
				max_v = p[i][j];
			}
		}
		//cout << endl;
	}

	if(max_v > max_block)
		max_block = max_v;
}

//int total = 0;
void play(int p[][20], int d, int time)
{
	//cout << "time : " << time << endl;
	//cout << "time; " << time << endl;
	if(time == 6){
		//total+=1;
		calculate(p);
		return;
	}

	int pan[20][20];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			pan[i][j] = p[i][j];
		}
	}
	if(d == 0)//우
	{
		//cout << "right" << endl;
		//합치기
		for(int i = 0; i < n; i++) //row 다 보고
		{
			for(int j = n-1; j >= 0; j--)
			{
				if(pan[i][j] != 0)
				{
					for(int k = j-1; k >= 0; k--)
					{
						if(pan[i][k] != 0){
							if(pan[i][k] == pan[i][j]){
								pan[i][j] *= 2; //두배해주고
								pan[i][k] = 0;//합쳤으니 0
							}
							//j = k-1;
							break;
						}
					}
				}
			}
		}
		//calculate(p);
		//show(pan);
		//cout << endl;
		//옮기기
		for(int i = 0; i < n; i++) //row 다 보고
		{
			for(int j = n-1; j >= 0; j--)
			{
				if(pan[i][j] == 0){
					for(int k = j-1; k >= 0; k--)
					{
						if(pan[i][k] != 0){
							pan[i][j] = pan[i][k];
							pan[i][k] = 0;
							break;
						}
					}
				}

			}
		}

		//show(pan);
		//calculate(p);
		//show(pan);
		//cout << endl;
		//우, 좌, 상, 하 
	}else if(d == 1)//좌
	{
		//cout << "left "<< endl;
		//합치기
		for(int i = 0; i < n; i++) //row 다 보고
		{
			for(int j = 0; j < n; j++)
			{
				if(pan[i][j] != 0)
				{
					for(int k = j+1; k < n; k++)
					{
						if(pan[i][k] != 0){
							if(pan[i][k] == pan[i][j]){
								pan[i][j] *= 2; //두배해주고
								pan[i][k] = 0;//합쳤으니 0
							}
							//j = k+1;
							break;
						}
					}
				}
			}
		}
		//calculate(p);

		//옮기기
		for(int i = 0; i < n; i++) //row 다 보고
		{
			for(int j = 0; j < n; j++)
			{
				if(pan[i][j] == 0){
					for(int k = j+1; k < n; k++)
					{
						if(pan[i][k] != 0){
							pan[i][j] = pan[i][k];
							pan[i][k] = 0;
							break;
						}
					}
				}

			}
		}
		//calculate(p);


	}else if(d == 2)//상
	{	
		
		//cout << "test " << pan[2][0] << endl;
		//합치기
		for(int j = 0; j < n; j++) //col 다 보고
		{
			for(int i = 0; i < n; i++)
			{
				//cout << "now "<<i <<", " << j<<endl;
				if(pan[i][j] != 0)
				{
					for(int k = i+1; k < n; k++)
					{	
						//cout << "compare : " << k << ", " << j <<  " Is not 0? " << pan[k][j] << endl;
						if(pan[k][j] != 0){
							if(pan[k][j] == pan[i][j]){
								pan[i][j] *= 2; //두배해주고
								pan[k][j] = 0;//합쳤으니 0	
								//cout << "merge (" << i << ", " << j << ") and (" << k << ", " << j << ")"<< endl;
								//i = k+1;
								//break;
								//cout << "Same " << endl;
							}
							
							break;
						}

					}
				}
			}
		}
		//calculate(p);
		//옮기기
		for(int j = 0; j < n; j++) //row 다 보고
		{
			for(int i = 0; i < n; i++)
			{
				if(pan[i][j] == 0){
					for(int k = i+1; k < n; k++)
					{
						if(pan[k][j] != 0){
							pan[i][j] = pan[k][j];
							pan[k][j] = 0;
							break;
						}
					}
				}

			}
		}

		//calculate(p);
		
		
//우, 좌, 상, 하

	}else if (d == 3)//하
	{

		//합치기
		for(int j = 0; j < n; j++) //col 다 보고
		{
			for(int i = n-1; i >= 0; i--)
			{
				if(pan[i][j] != 0)
				{
					for(int k = i-1; k >= 0; k--)
					{
						if(pan[k][j] != 0){
							if(pan[k][j] == pan[i][j]){
								pan[i][j] *= 2; //두배해주고
								pan[k][j] = 0;//합쳤으니 0
							}
							//i = k-1;
							break;
						}
					}
				}
			}
		}

		//옮기기
		for(int j = 0; j < n; j++) //row 다 보고
		{
			for(int i = n-1; i >= 0; i--)
			{
				if(pan[i][j] == 0){
					for(int k = i-1; k >=0; k--)
					{
						if(pan[k][j] != 0){
							pan[i][j] = pan[k][j];
							pan[k][j] = 0;
							break;
						}
					}
				}

			}
		}

		//calculate(p);


	}
	
	play(pan, 0, time+1);
	play(pan, 1, time+1);
	play(pan, 2, time+1);
	play(pan, 3, time+1);

//우, 좌, 상, 하 

}

int main()
{
	int game_pan[20][20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &game_pan[i][j]);
		}
	}

	//cout << "pan test" << game_pan[2][0] << endl;

	//play(game_pan, 0, 1);
	//cout << "total : " << total << endl;
	
	for(int d = 0; d < 4; d++)
	{
		play(game_pan, d, 1);
	}
	
	
	//우, 좌, 상, 하
	
	cout << max_block;

	return 0;
}