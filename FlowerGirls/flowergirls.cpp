#include<iostream>

using namespace std;


int N;
string s;
int dp[1000000][10][10];

int Give(char cur, int past){
	
	int ret_val = 0;
	
	if(past == 0) ret_val = 1;
	else{
		if( cur == 'R' ){
			if((past-1) % 3 == 0 && (past-1)/3 == 0) ret_val = 1;
			else if ((past-1) % 3 == 0 || (past-1)/3 == 0) ret_val = 2;
			else if (past == 5 || past == 9) ret_val = 2;
			else ret_val = 3;
		}
		if( cur == 'T' ){
			if((past-1) % 3 == 1 && (past-1)/3 == 1) ret_val = 1;
			else if ((past-1) % 3 == 1 || (past-1)/3 == 1) ret_val = 2;
			else if (past == 1 || past == 9) ret_val = 2;
			else ret_val = 3;
		}
		if( cur == 'L' ){
			if((past-1) % 3 == 2 && (past-1)/3 == 2) ret_val = 1;
			else if ((past-1) % 3 == 2 || (past-1)/3 == 2) ret_val = 2;
			else if (past == 1 || past == 5) ret_val = 2;
			else ret_val = 3;
		}
	}
	
	return ret_val;
	
}

int Flower(int cur, int girl1, int girl2){
	
	if(cur == N) return 0;
	if(dp[cur][girl1][girl2] != 0){
		return dp[cur][girl1][girl2];
	}
	
	int opt1, opt2;
	
	int flower_no;
	
	switch(s[cur]){
		case 'R' : flower_no = 1; break;
		case 'T' : flower_no = 2; break;
		case 'L' : flower_no = 3; break;
	}
	
	opt1 = Flower(cur+1, ( girl1==0?(flower_no-1):((girl1-1)%3) ) * 3 + flower_no, girl2) + Give(s[cur], girl1 );
	opt2 = Flower(cur+1, girl1, ( girl2==0?(flower_no-1):((girl2-1)%3) ) * 3 + flower_no) + Give(s[cur], girl2 ); 
	
	
	dp[cur][girl1][girl2] = max(opt1, opt2);
	return max(opt1, opt2);
	
}

int main(){

	cin >> N;
	cin >> s;
	cout << Flower(0, 0, 0) << endl;


	return 0;
}