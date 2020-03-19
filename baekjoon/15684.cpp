#include <iostream>

using namespace std;

bool ladder[31][11];
int N, M, H;



bool check()
{
	for(int j = 1; j <= N; j++)
	{
		int r = 1;
		int c = j;
		while(r <= H)
		{
			//오른쪽사다리
			if(ladder[r][c] == true)
				c += 1; //오른쪽으로 가는 사다리 있으니까 오른쪽으로
			//왼쪽사다리
			else if(c-1 >= 0 && ladder[r][c-1] == true) //왼쪽꺼는 범위확인해주고, 왼쪽으로 옮기기
				c -= 1;

			r += 1; //한칸 내려가자
		}

		if(c != j)
			return false;
	}

	//다 잘 갔으면 true
	return true;
}


void put_ladder(int x, int y, int l, int m) //p: 자리 순회, l: 지금 놓을 사다리의 번호, m: 최대 몇개 넣을 것인지
{
	if(y > N)
	{
		x += 1;
		y = 0;
	}
	
	if(l > m)
	{
		if(check() == true)
		{
			cout << m;
			exit(0);
		}
		return;
	}

	if(x == H+1 && y == 0){ //범위 넘어갔을 때 
		return;
	}

	if(ladder[x][y] == 0){
		ladder[x][y] = 1;
		put_ladder(x, y+1, l+1, m);

		ladder[x][y] = 0;
		put_ladder(x, y+1, l, m);
	}else
	{
		put_ladder(x, y+1, l, m);
	}



}


int main()
{	
	scanf("%d %d %d", &N, &M, &H); //N: 가로길이 //H: 세로길이

	if(M == 0)
	{
		cout << "0";
		return 0;
	}

	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ladder[a][b] = true;
	}

	//사다리 0번 놓기
	if(check() == true)
	{
		cout << "0";
		return 0;
	}

	//사다리 1번 놓기
	put_ladder(1, 1, 1, 1); //시작지점은 1, 1임, 행이 0이 아니라 1부터 시작해서 

	//사다리 2번 놓기
	put_ladder(1, 1, 1, 2); 

	//사다리 3번 놓기
	put_ladder(1, 1, 1, 3); 

	cout << "-1";


	return 0;
}