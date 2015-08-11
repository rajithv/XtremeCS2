#include<iostream>

using namespace std;


int N;
string s;

int Give(char cur, string past){
	int len = past.length();
	
	int score;

	bool R = false; 
	bool T = false;
	bool L = false;
	
	R = cur == 'R' || past[len-1] == 'R' || past[len-2] == 'R';
	T = cur == 'T' || past[len-1] == 'T' || past[len-2] == 'T';
	L = cur == 'L' || past[len-1] == 'L' || past[len-2] == 'L';
	
	score = (int)R + (int)T + (int)L;
	
	return score;
	
}

int Flower(int cur, string girl1, string girl2){
	
	if(cur == N) return 0;
	
	int opt1 = Flower(cur+1, girl1+s[cur], girl2) + Give(s[cur], girl1 );
	int opt2 = Flower(cur+1, girl1, girl2+s[cur]) + Give(s[cur], girl2 ); 
	
	return max(opt1, opt2);
	
}

int main(){

	cin >> N;
	cin >> s;
	cout << Flower(0, "", "") << endl;


	return 0;
}