#include <iostream>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int people[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &people[i]);

	int B, C;
	scanf("%d %d", &B, &C);

	long long ans = 0;
	for(int i = 0; i < N; i++)
	{
		ans += 1;
		if(people[i] <= B)
			continue;

		int sub_dir = (people[i] - B) / C;
		ans += sub_dir;

		int more = (people[i] - B) % C;
		if(more != 0)
			ans += 1;

	}


	cout << ans;


	return 0;
}

