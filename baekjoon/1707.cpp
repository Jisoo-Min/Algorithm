#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visit[20000] = {0,};
int color[20000] = {0,};


vector<int> edges[20000];

queue<int> q;

int v, e;

bool bfs(int h)
{
	q.push(h); visit[h] = 1; color[h] = 1;


	while(!q.empty())
	{
		int head = q.front(); 
		q.pop();

		for(int i = 0; i < edges[head].size(); i++)
		{
			int num = edges[head][i];

			if(visit[num] == 0){//방문하지 않았을 때
				q.push(num);
				visit[num] = 1;
				color[num] = (3-color[head]);

			}else{ //이미 방문한 지점일 때 -> 그래도 확인해야함
				if(color[num] != (3-color[head])){ // 색깔이 반대가 아니면 X 
					return false;
				}
			}
		}
	}

	return true;

}

/*
int main(void)
{
    int t,v,e,a,b;
    scanf("%d", &t);
    
    while(t--) {

 
        scanf("%d %d", &v, &e);
        for(int i=0; i<e; i++) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        int flag = 1;
        for(int i=0; i<v; i++) {
            if(visit[i]==0) {
            	int tmp = bfs(i);
                if(tmp==0) {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag == 1)
        	printf("YES\n");
        else
        	printf("NO\n");
        
       
        
        while(!q.empty()) q.pop();
        for(int i=0; i<v; i++) edges[i].clear();
        memset(color,0,sizeof(color));
    	memset(visit,0,sizeof(visit));
    }
    return 0;
}


*/
int main()
{

	int total;
	scanf("%d", &total);
	
	for(int i = 0; i < total; i++)
	{
		
		scanf("%d", &v);
		scanf("%d", &e);

		for(int j = 0; j < e; j++)
		{
			int from, to;
			scanf("%d", &from); scanf("%d", &to);
			from--; to--;
			edges[from].push_back(to);
			edges[to].push_back(from);	
		}


		int flag = 1;
		for(int t = 0; t < v; t++){
			if(visit[t] == 0){
				int output = bfs(t);
				if(output == false){
					flag = 0;
					break;
				}
			}
		}


		if(flag == 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}



		memset(visit, 0, sizeof(visit));
		memset(color, 0, sizeof(color));
		while(!q.empty()){
			q.pop();
		}

		for(int k = 0; k < v; k++)
		{
			edges[k].clear();
		}
	}



	return 0;
}
