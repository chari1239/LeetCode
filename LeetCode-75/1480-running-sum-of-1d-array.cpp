******************************

Date: 30/07/2022 Time: 09:59:59 AM

// 1480. Running Sum of 1d Array

// https://leetcode.com/problems/running-sum-of-1d-array/


// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:

// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
// Example 3:

// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]
 

// Constraints:

// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6



//***** SOLUTION ***********//


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
     // here we are changing the input array itself. Generally it is not recommended, if asked in interview discuss with him.
        for(int i=1;i<nums.size();++i)
            nums[i]+=nums[i-1];
        
        return nums;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)


//**** Extra Space Solution *****

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=nums[0];
        for(int i=1;i<nums.size();++i)
           res[i]=res[i-1]+nums[i];
        
        return res;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)  -- for storing the result

