#include<iostream>

using namespace std;

long long p[100000], f[100000];
long long total_food;
long long max_possible;
long long N;

long long next_food = 0;

bool isPossible(int no){
	long long fwd = 0;
	next_food = f[0];
	for(int i=0; i<N-1; i++){
		fwd = next_food - no;
		if(fwd < 0){
			next_food = f[i+1];
			next_food += fwd;
			next_food -= (p[i+1] - p[i]);
		}else if(fwd > 0){
			next_food = f[i+1];
			next_food += fwd - (p[i+1] - p[i] ) > 0 ? fwd - (p[i+1] - p[i] ) : 0;
		}
	}
	
	if( next_food >= no){
		return true;
	}
	
	return false;
}

int main(){

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> p[i] >> f[i];
		total_food += f[i];
	}
	
	max_possible = total_food / N;
	
	long long upper = max_possible;
	long long lower = 0;
	
	while(upper - lower > 1){
		
		//cout << lower << " " << upper << " " << (upper+lower)/2 << " " << isPossible( (upper+lower)/2 ) << endl;
		
		if (isPossible( (upper+lower)/2 ) ){
			if(upper - lower > 1)
				lower = (upper+lower)/2;
		}else{
			upper = (upper+lower)/2;
		}
		
	}
	
	cout << (isPossible(upper)?upper:lower) << endl;

}