/*

https://leetcode.com/problems/intersection-of-two-arrays-ii/ 

************ Problem  ********************



Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000


************************

*/

/*********** Solution ***************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        
        unordered_map<int,int> store;
        
        for(int k:nums1) ++store[k];
        
        for(int k:nums2){
            if(store[k]>0) {
                res.push_back(k);
                --store[k];
            }
        }
        
        return res;
        
    }
};

