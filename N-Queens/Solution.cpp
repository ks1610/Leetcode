#include<bits/stdc++.h>

class Solution {
	public:
		bool isValid(std::vector<std::string>& board, int row, int col, int N) {
		   for (int i = 0; i < col; i++) //check whether there is queen in the left or not
			  if (board[row][i] == 'Q')
				 return false;
		   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
			  if (board[i][j] == 'Q') //check whether there is queen in the left upper diagonal or not
				 return false;
		   for (int i=row, j=col; j>=0 && i<N; i++, j--)
			  if (board[i][j] == 'Q') //check whether there is queen in the left lower diagonal or not
				 return false;
		   return true;
		}
	
		void place(std::vector<std::string>& board, int col, int N, std::vector<std::vector<std::string>> & result) {
		   if (col >= N){ //when N queens are placed successfully
			  result.push_back(board);
			  return;
		   }
		   for (int i = 0; i < N; i++) { //for each row, check placing of queen is possible or not
			  if (!isValid(board, i, col, N) ) 
				continue;
	
			  board[i][col] = 'Q'; //if validate, place the queen at place (i, col)
			  place(board, col + 1, N, result);
			  board[i][col] = '.'; //When no place is vacant remove that queen
		   }
		}
		
		std::vector<std::vector<std::string>> solveNQueens(int n) {
			//Using this board to keep track of each solution.
			//Initialize it with '.' -> if n=4 then ["....", "....", "....", "...."]
			std::vector<std::string> board(n, std::string(n, '.'));
			std::vector<std::vector<std::string>> result;
			place(board, 0, n, result);
			return result;
		}
	
		void printBoard(std::vector<std::vector<std::string>> result, int N){
			result = solveNQueens(N);
			for (int i = 0; i < N; i++) {
			   std::cout << "Solution " << i + 1 << ":\n";
			   for (int j = 0; j < N; j++)
				  std::cout << result[i][j] << std::endl;
			}
		}
};

int main(){
	int n;
	std::vector<std::vector<std::string>> result;
	Solution s;

	std::cout<<"Enter Board Size: ";
	std::cin>>n;
	
	s.printBoard(result, n);
}
