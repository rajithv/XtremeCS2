#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int pay_greedy(int M, vector<int> denoms);
int pay_rec(int M, vector<int> denoms);
int pay_dp(int M, vector<int> denoms);


int dp_array[1000];
int no_of_calls_dp;
int no_of_calls_rec1;


int main(){
	
	int N; // no of denominations
	int M; // the amount to be paid
	
	vector<int> denoms;
	
	cin >> N >> M;
	
	int temp;
	
	for(int i=0; i<N; i++){
		cin >> temp;
		denoms.push_back(temp);
	}
	
	int greedy = pay_greedy(M, denoms);
	cout << "Greedy : " << greedy  << endl;
	
	int rec1 = pay_rec(M, denoms);
	cout << "Rec1 : " << rec1 << " " << no_of_calls_rec1 << endl;
	
	int dp = pay_dp(M, denoms);
	cout << "DP : " << dp << " " << no_of_calls_dp << endl;
	
	return 0;
}

int pay_greedy(int M, vector<int> denoms){
	
	sort(denoms.begin(), denoms.end());
	int ans = 0;
	
	int num;
	
	for(int i=denoms.size() - 1; i >= 0; --i){
		
		num = M / denoms[i];
		M %= denoms[i];
		ans += num;
	}
	
	return ans;
	
}

// basic recursion code - improvements to be done during the workshop
int pay_rec(int M, vector<int> denoms){
	
	if(M == 0){
		return 0;
	}
	
	int num;
	int best = M*1000;
	
	no_of_calls_rec1++;
	
	for(int i=0; i<denoms.size(); i++){
		
		if(denoms[i] <= M){
			num = M / denoms[i];
			best = min(best, num + pay_rec(M % denoms[i], denoms));
		}
		
	}
	
	return best;
}

int pay_dp(int M, vector<int> denoms){
	
	if(M == 0){
		return 0;
	}
	
	if(dp_array[M] != 0){
		return dp_array[M];
	}
	
	int num;
	int best = M*1000;
	
	no_of_calls_dp++;
	
	for(int i=0; i<denoms.size(); i++){
		
		if(denoms[i] <= M){
			num = M / denoms[i];
			best = min(best, num + pay_dp(M % denoms[i], denoms));
		}
		
	}
	
	dp_array[M] = best;
	return best;
}