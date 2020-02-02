#include <iostream>
#include <vector>

using namespace std;


void answer(vector<int> heights){
	sort(heights.begin(), heights.end());
	for(int i = 0; i < heights.size(); i++){
		cout<< heights[i] <<endl;
	}
}

int main(){

	vector<int> heights;

	int num_dwarfs = 9;

	int height;
	int sum = 0;

	for(int i = 0; i < num_dwarfs; i++){
		cin >> height;
		sum += height;
		heights.push_back(height);
		
	}


	for(int h1 = 0; h1 < heights.size(); h1++){
		for(int h2 = 0; h2 < heights.size(); h2++){
			if(h1 == h2)	continue;
			if((sum - heights[h1] - heights[h2]) == 100){
				if(h1 < h2){
					heights.erase(heights.begin() + h2);
					heights.erase(heights.begin() + h1);
					answer(heights);
					return 0;
				}else{
					heights.erase(heights.begin() + h1);
					heights.erase(heights.begin() + h2);
					answer(heights);
					return 0;
				}
			}
		}
	}


	

	

	return 0;
}