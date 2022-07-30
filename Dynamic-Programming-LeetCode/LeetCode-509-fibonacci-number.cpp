Date: 30/07/2022 Time: 01:36:00 PM

// 509. Fibonacci Number

// https://leetcode.com/problems/fibonacci-number/

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
  
  *** Solution **
  
class Solution {
public:
    int fib(int n) {
        
        vector<int> fib(n+1,0);
      
        // base or edge case check that we will forgot to think/write.
        // Code fails with indexOutOfBound Exception in next line for n=0 & we don't have this check. 
        if(n==0) return 0; 
        
        fib[1]=1; // or we can have a check here as follows if(n>0) fib[1]=1;
        
        for(int i=2;i<=n;++i)
            fib[i] = fib[i-1] + fib[i-2];
        
        return fib[n];
        
    }
};


// Time Complexity: O(n);
// Space Complexity: O(n)


