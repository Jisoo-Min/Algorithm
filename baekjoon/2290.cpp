#include <iostream>
#include <string>
using namespace std;
int s;
void print_horizotal(int v)
{
	printf(" "); //글자 빈곳채우기
	if(v == 0){
		for(int t = 0; t < s; t++)
			printf(" ");
	}else{
		for(int t = 0; t < s; t++)
			printf("-");
	}

	printf("  "); //글자 빈곳 + 글자사이 공간(2)

}

void print_vertical_left(int v)
{
	if(v == 1){
		printf("|");
	}else{
		printf(" ");
	}

	for(int t = 0; t < s; t++)
		printf(" ");
	
}

void print_vertical_right(int v)
{
	if(v == 1){
		printf("|");
	}else{
		printf(" ");
	}

	printf(" "); //글자사이 공간(1)
}


int main()
{

	int top[10]        = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
	int middle[10]     = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
	int bottom[10]     = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
	int upper_left[10] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
	int upper_right[10]= {1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
	int lower_left[10] = {1, 0, 1, 0, 0, 0, 1, 0, 1 ,0};
	int lower_right[10]= {1, 1, 0, 1, 1, 1, 1, 1, 1, 1};


	
	string n;
	cin >> s >> n;
	//1. top
	for(int i = 0; i < n.size(); i++){
		print_horizotal(top[n[i]-'0']);
	}
	printf("\n");

	//2. upper
	for(int t = 0; t < s; t++){
		for(int i = 0; i < n.size(); i++){
		print_vertical_left(upper_left[n[i]-'0']);
		print_vertical_right(upper_right[n[i]-'0']);
		}
		printf("\n");
	}

	//3. middle
	for(int i = 0; i < n.size(); i++)
		print_horizotal(middle[n[i]-'0']);
	printf("\n");

	//4. lower
	for(int t = 0; t < s; t++){
		for(int i = 0; i < n.size(); i++){
			print_vertical_left(lower_left[n[i]-'0']);
			print_vertical_right(lower_right[n[i]-'0']);
		}
		printf("\n");
	}

	//5. bottom
	for(int i = 0; i < n.size(); i++){
		print_horizotal(bottom[n[i]-'0']);
	}



	return 0;
}