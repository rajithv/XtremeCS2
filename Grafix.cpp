#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

ifstream fin("Grafix.in");

// Keeping image as a global map

bool image[400][600];

// Flood fill algo

int fill(int x, int y){
	
	
	// Start from x and y
	image[x][y] = true;
	int sum = 1;
	
	queue<tuple<int,int>> frontier;
	frontier.push(make_tuple(x, y));
	
	
	// Flood in four directions
	
	int s1[] = {-1, 0, +1, 0};
	int s2[] = {0, -1, 0, +1};
	
	while(!frontier.empty()){
		
		// Explore the  node
		
		x = get<0>(frontier.front());
		y = get<1>(frontier.front());
	
		for(int i=0; i<4; i++){
			
			if(x+s1[i] < 0 || x+s1[i] >= 400) continue;
			if(y+s2[i] < 0 || y+s2[i] >= 600) continue;
			
			if(image[x+s1[i]][y+s2[i]]) continue;
			
			image[x+s1[i]][y+s2[i]] = true;
			
			sum += 1;
			
			// Flood the non-flooded and adjacent areas
			frontier.push(make_tuple(x+s1[i], y+s2[i]));
		}
		
		frontier.pop();
	}
	
	return sum;
}



int main(){
	
	int n; // number of masks
	fin >> n;
	
	int x1, y1, x2, y2;
	
	for(int x=0; x<n; x++){
		fin >> x1 >> y1 >> x2 >> y2;
		
		// Mark the masks on the image map
		for(int i=x1; i<=x2; ++i){
			for(int j=y1; j<=y2; ++j){
				image[i][j] = true;
			}
		}
		
	}
	
	int sum = 0;
	vector<int> sums;
	
	int temp;
	
	
	for(int i=0; i<400; i++){
		for(int j=0; j<600; j++){
			
			// If it's not already counted, run the flood fill
			
			if(!image[i][j]){
				temp = fill(i, j);
				sums.push_back(temp);
				sum++;
			}
		}
	}


	cout << sum << endl;
	for(int i=0; i<sums.size(); i++){
		cout << sums[i] << " ";
	}
	cout << endl;

	return 0;
}