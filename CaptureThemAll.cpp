#include<iostream>
#include<fstream>
#include<queue>
#include<tuple>

using namespace std;

// returns the 0-base column number
int get_col(string s){
	return s[0] - 'a';
}

// returns the 0-base row number
int get_row(string s){
	return s[1] - 1 - '0';
}

ifstream fin("CaptureThemAll.in");

int main(){
	
	string K, R, Q; // positions of the pieces
	
	fin >> K >> R >> Q;
	
	int capture_count = 0;
	int total_pieces = 2;
	
	// mark the board for Queen and Rook positions
	
	bool board2[8][8];
	memset(board2, 0, sizeof(bool) * 8 * 8);
	
	board2[ get_col(Q) ][ get_row(Q) ] = true;
	board2[ get_col(R) ][ get_row(R) ] = true;
	
	// frontier : col, row, step
	queue<tuple<int,int, int>> frontier;
	
	// start with Knight's position, with step count 0
	frontier.push( make_tuple( get_col(K), get_row(K) , 0) );

	int cur_col, cur_row, cur_step;

	while(!frontier.empty()){
		
		// explore the current node
		
		cur_col = get<0>(frontier.front());
		cur_row = get<1>(frontier.front());
		
		cur_step = get<2>(frontier.front());
		
		if(board2[cur_col][cur_row]){
			
			board2[cur_col][cur_row] = false;
			
			queue<tuple<int,int, int>> empty;
			swap(empty, frontier);
			
			capture_count++;
			if(capture_count == total_pieces){
				cout << cur_step;
				return 0;
			}
			
		}
		
		
		
		for(int i=-2; i<=2; i++){
			for( int j=-2; j<=2; j++){
				
				// wrong combinations for knight moves
				if(j==0 || i==0 || i == j || i == -  j) continue;
				
				// check for board's bounds
				if(cur_col + i > 7 || cur_col + i < 0) continue;
				if(cur_row + j > 7 || cur_row + j < 0) continue;
				
				// expand the frontier
				// we do not keep a grey list because the knight might need to
				// come to a previous position in order to get back quickly
				frontier.push( make_tuple (cur_col + i, cur_row + j, cur_step + 1)); 
				
				//cout << (char)(cur_col + i +'a') << cur_row + j +1 << " " << cur_step + 1 << endl;
				
			}
		}
		
		/* print board 
		for(int x=0; x< 8; x++){
			for(int y=0; y<8; y++){
				if(cur_col == x && cur_row == y) cout << "X ";
				else if (board2[x][y]) cout << "$ "; 
				else cout << board[x][y] << " ";
			}
			cout << endl;
		}
		
		cout << endl;
		
		/* print board end */

		
		frontier.pop();
	}

	return 0;
}