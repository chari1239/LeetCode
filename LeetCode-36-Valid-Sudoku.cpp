

36. Valid Sudoku

https://leetcode.com/problems/valid-sudoku/

///  PROBLEM  ///
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
  
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. 
  Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.


  //// Solution //////
  
class Solution {
public:
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
      
        /* we used unordered_set to check the valididty. Because return type of set.insert is a pair<int,bool>  we can utilize 2nd paramter for duplicates*/
      
        int n=9;
        unordered_set<char> row,col;
        
        for(int i=0;i<n;++i){
           for(int j=0;j<n;++j){
               if(board[i][j]!='.' && row.insert(board[i][j]).second == false){  // Checking row
                   return false;
               }
               if(board[j][i]!='.' && col.insert(board[j][i]).second == false){  // Checking column
                   return false;
               }
           }
            row.clear();
            col.clear();
        }
        
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                
                for(int l=i;l<i+3;++l){
                   for(int m=j;m<j+3;++m){
                      if(board[l][m]!='.' && row.insert(board[l][m]).second == false){ // checking th 3x3 grid
                         return false;
                       } 
                   }
                }
                row.clear();
            }
        }
        
        return true;
    }
};

// Time Complexity: O(1) - O(9*9 + 9*9)
// Space Complexity: O(1) - O(9)

