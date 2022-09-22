// 1011. Capacity To Ship Packages Within D Days

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        
        int sum=0, mx=0, n = weights.size(),res=0;
        
        for(int i=0;i<n;++i){
            sum+=weights[i];
            mx = max(mx,weights[i]);
        }
        
        if(days == n) return mx;
        
        int low = mx;
        int high = sum;
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(isPossible(weights,mid,days)){
                res=mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
            
            
        }
        return res;
        
    }
    
    bool isPossible(vector<int>& weights, int ans, int days){
        
        int day = 1,sum=0;
        
        for(int i=0;i<weights.size();++i){
            sum+=weights[i];
            if(sum>ans){
                sum=weights[i];
                ++day;
            }
        }
        
        return day<=days;
    }
};



//Time COmplexity : O(log n)
