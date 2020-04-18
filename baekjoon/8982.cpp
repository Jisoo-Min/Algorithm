#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main() 
{
	int n;
	cin >> n;

	n = (n-2)/2;

	int top[40000] = {0,};
	int bottom[40000];
	bool hole[40000] = {0,}; //구멍
	int width[40000] = {0,}; //선분의 길이 
	

	map<int, int> dict; //선분 번호 -> 구멍 찾는거 쉬우려고 -> 각각의 X좌표를 만족하는게 몇번 선분인


	//점입력받기
	int tmpx, tmpy;
	cin >> tmpy >> tmpx;
	for(int i = 0; i < n; i++) //양 끝 제외
	{
		//점두개씩 받으면 알아서 가로 선분만나옴
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bottom[i] = y1; //y1==y2
		dict[x2] = i;  //몇번 선분인지 저장
		width[i] = (x2-x1);//선분너비

	}
	cin >> tmpy >> tmpx;

	//구멍 입력받
	int h;
	cin >> h;
	for(int i = 0; i < h; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int idx = dict[x2]; //몇분 선분인지 가져오기
		hole[idx] = true; //선분에 구멍있다고 알려주기
	}

	//구멍있는 선분 양쪽으로 쌓일 수 있는 최대 구해주기
	for(int i = 0; i < n; i++)
	{	
		if(hole[i] == true) //구멍있으면
		{
			int surface = bottom[i]; //가장 바닥 높이
			for(int j = i; j >= 0; j--)//자신부터 왼쪽선분들 높이 조절 
			{
				surface = min(surface, bottom[j]); //바닥 높이 비교
				top[j] = max(top[j], surface);
			}


			surface = bottom[i];
			for(int j = i+1; j < n; j++)
			{
				surface = min(surface, bottom[j]);
				top[j] = max(top[j], surface);
			}

		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(bottom[i]>top[i])
			ans += (long long)(bottom[i]-top[i])*width[i];
	}

	cout << ans;
	return 0;
}