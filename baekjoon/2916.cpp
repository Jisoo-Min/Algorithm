#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> A;
	int B[K];

	bool angle[360];
	memset(angle, 0, sizeof(angle));
	angle[0] = true;


	queue<int> q;

	for(int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
		angle[tmp] = true;
		q.push(tmp);

		A.push_back(360-tmp);
		angle[360-tmp] = true;
		q.push(360-tmp);
	}

	for(int i = 0; i < K; i++)
		scanf("%d", &B[i]);


	while(!q.empty())
	{
		int head = q.front();
		q.pop();


		for(int j = 0; j < A.size(); j++)
		{
			int minus = head - A[j];
			int plus  = head + A[j];
			if(minus < 0)
				minus = -minus;
			if(plus > 360)
				plus %= 360;

			if(angle[minus] == false)
			{
				q.push(minus);
				A.push_back(minus);
				angle[minus] = true;

				q.push(360-minus);
				A.push_back(360-minus);
				angle[360 - minus] = true;
			}
			if(angle[plus] == false)
			{
				q.push(plus);
				A.push_back(plus);
				angle[plus] = true;

				q.push(360-plus);
				A.push_back(360-plus);
				angle[360-plus] = true;
			}

		}

		int num = head;
		while(num > 360)
		{
			if(angle[num] == false)
			{
				A.push_back(num);
				angle[num] = true;
				q.push(num);
			}
			num += head;

		}
	}





	for(int i = 0; i < K; i++)
	{
		if(angle[B[i]] == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}