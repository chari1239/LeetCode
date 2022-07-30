/*
74. Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix/


//// PROBLEM /////////////

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
  
  */
  
  
  //// SOLUTION  //////

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l=0, r= n*m-1;
        
        while(l<=r){
            
            int mid = l + (r-l)/2;
            int val = matrix[mid/m][mid%m];
          
            if(val==target) return true;
            
            if(target>val) l=mid+1;
            else r=mid-1;
            
        }
        
        return false;
    }
};


// TIME COMPLEXITY: O(log n*m)
// Space Complexity: O(1)
