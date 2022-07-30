566. Reshape the Matrix

https://leetcode.com/problems/reshape-the-matrix/

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]


Example 2:

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]


/// Solution ////

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(n*m!=r*c) return mat;  // I forgot to check this condition at first, as I haven't read the question properly. So Read the question properly.
        
        vector<vector<int>> res(r,vector<int>(c));
        
        int p=0,q=0;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                
                if(q>=c){
                    q=0; ++p;
                }
                res[p][q] = mat[i][j];
                ++q;
                
            }
        }
        
        return res;
    }
};


// Time Complexity: O(n*m)
// Space Complexity : O(1) - we haven't used any extra space ||  O(r*c) - used for result


