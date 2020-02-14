#include <iostream>
#include <cstring>
using namespace std;

char pan[10][10];
int n, m;

int red_x,  red_y;
int blue_x, blue_y;
int hole_x, hole_y;
int answer = 11;

//하, 상, 우, 좌
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
void go(int r_x, int r_y, int b_x, int b_y, int time, int dir)
{	//cout << "Dir: " << dir << endl;
	//cout << " T "<< endl;
	if(time > 10){
		return;
	}

	int tmp_r_x = r_x; int tmp_r_y = r_y;
	int tmp_b_x = b_x; int tmp_b_y = b_y;
	if(dir == 0)//아래로 움직?
	{	

		bool drop_r = false; bool drop_b = false;
		while(pan[tmp_r_x+1][tmp_r_y] != '#')
		{	
			//red 움직
			tmp_r_x += 1;

			if(pan[tmp_r_x][tmp_r_y] == 'O')
				drop_r = true;
			
		}
		while(pan[tmp_b_x+1][tmp_b_y] != '#')
		{
			//blue 움직
			tmp_b_x += 1;

			if(pan[tmp_b_x][tmp_b_y] == 'O')
				drop_b = true;
		
		}
		if(drop_b == true) //안되는 경우: 파란공 빠지면안됨
			return; 
		if(drop_r == true)
		{
			if(time < answer)
				answer = time;
			return;
		}

		if(tmp_r_x == r_x && tmp_r_y == r_y && tmp_b_x == b_x && tmp_b_y == b_y)
			return;
		
		//겹치면
		if(tmp_r_x == tmp_b_x && tmp_r_y == tmp_b_y){
			if(r_x < b_x) //빨간공이 더 위에있었으면
				tmp_r_x -= 1;
			else
				tmp_b_x -= 1;
		}
			
		
		

		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 2);
		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 3);
		//cout << "red: " << tmp_r_x << ", " << tmp_r_y  <<"\n";
		//cout << "blue: " << tmp_b_x << ", " << tmp_b_y  <<"\n";

	}
	else if(dir == 1)//위로 움직?
	{
		//cout << "1" << endl;
		bool drop_r = false; bool drop_b = false;
		while(pan[tmp_r_x-1][tmp_r_y] != '#')
		{	
			tmp_r_x -= 1;

			if(pan[tmp_r_x][tmp_r_y] == 'O')
				drop_r = true;
		}
		while(pan[tmp_b_x-1][tmp_b_y] != '#')
		{
				tmp_b_x -= 1;

			if(pan[tmp_b_x][tmp_b_y] == 'O')
				drop_b = true;
		
		}
		if(drop_b == true) //안되는 경우: 파란공 빠지면안됨
			return; 
		if(drop_r == true)
		{
			if(time < answer)
				answer = time;
			return;
		}
		//안움직임
		
		if(tmp_r_x == r_x && tmp_r_y == r_y && tmp_b_x == b_x && tmp_b_y == b_y)
			return;
		

		//겹치면
		if(tmp_r_x == tmp_b_x && tmp_r_y == tmp_b_y){
			if(r_x < b_x) //빨간공이 더 위에있었으면
				tmp_b_x += 1;
			else
				tmp_r_x += 1;
		}
			
		
		
		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 2);
		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 3);
		//cout << "red: " << tmp_r_x << ", " << tmp_r_y  <<"\n";
		//cout << "blue: " << tmp_b_x << ", " << tmp_b_y  <<"\n";

	}
	else if(dir==2)//오른쪽으로 움직?
	{
		bool drop_r = false; bool drop_b = false;
		while(pan[tmp_r_x][tmp_r_y+1] != '#')
		{	
			tmp_r_y += 1;

			if(pan[tmp_r_x][tmp_r_y] == 'O')
				drop_r = true;
		}
		while(pan[tmp_b_x][tmp_b_y+1] != '#')
		{

			tmp_b_y += 1;

			if(pan[tmp_b_x][tmp_b_y] == 'O')
				drop_b = true;
		
		}
		if(drop_b == true) //안되는 경우: 파란공 빠지면안됨
			return; 
		if(drop_r == true)
		{
			if(time < answer)
				answer = time;
			return;
		}
		//안움직임
		
		if(tmp_r_x == r_x && tmp_r_y == r_y && tmp_b_x == b_x && tmp_b_y == b_y)
			return;
		
		//겹치면
		if(tmp_r_x == tmp_b_x && tmp_r_y == tmp_b_y){
			if(r_y < b_y) //파란공이 더 오른쪽에에있었으면
				tmp_r_y -= 1;
			else
				tmp_b_y -= 1;
		}
			
		


		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 0);
		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 1);
		//cout << "red: " << tmp_r_x << ", " << tmp_r_y  <<"\n";
		//cout << "blue: " << tmp_b_x << ", " << tmp_b_y  <<"\n";

	}
	else if(dir==3)//왼쪽으로 움직?
	{
		
		bool drop_r = false; bool drop_b = false;
		while(pan[tmp_r_x][tmp_r_y-1] != '#')
		{	
			//red 움직
			tmp_r_y -= 1;

			if(pan[tmp_r_x][tmp_r_y] == 'O')
				drop_r = true;

		}
		while(pan[tmp_b_x][tmp_b_y-1] != '#')
		{
			//blue 움직
			tmp_b_y -= 1;

			if(pan[tmp_b_x][tmp_b_y] == 'O')
				drop_b = true;
		
		}

		if(drop_b == true) //안되는 경우: 파란공 빠지면안됨
			return; 
		if(drop_r == true)
		{
			if(time < answer)
				answer = time;
			return;
		}

		//겹치면
		
		if(tmp_r_x == r_x && tmp_r_y == r_y && tmp_b_x == b_x && tmp_b_y == b_y)
			return;
		
		if(tmp_r_x == tmp_b_x && tmp_r_y == tmp_b_y){
			if(r_y < b_y) //파란공이 더 오른쪽에에있었으면
				tmp_b_y += 1;
			else
				tmp_r_y += 1;
		}
			
		

		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 0);
		go(tmp_r_x, tmp_r_y, tmp_b_x, tmp_b_y, time+1, 1);
		//cout << "red: " << tmp_r_x << ", " << tmp_r_y  <<"\n";
		//cout << "blue: " << tmp_b_x << ", " << tmp_b_y  <<"\n";

	
	}
	

}


int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
	{
		string tmp_input;
		cin >> tmp_input;
		for(int j = 0; j < m; j++)
		{
			pan[i][j] = tmp_input[j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			//cout << pan[i][j] << " ";
			if(pan[i][j] == 'R'){
				red_x = i;
				red_y = j;
			}else if(pan[i][j] == 'B'){
				blue_x = i;
				blue_y = j;
			}else if(pan[i][j] == '0'){
				hole_x = i;
				hole_y = j;
			}
		}
		//printf("\n");
	}


	for(int d = 0; d < 4; d++)
	{
		go(red_x, red_y, blue_x, blue_y, 1, d);
	}
	

	if(answer == 11)
		cout << "-1";
	else	
		cout << answer;

	return 0;
}