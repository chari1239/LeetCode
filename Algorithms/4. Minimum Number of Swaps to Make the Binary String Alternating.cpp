// Minimum Number of Swaps to Make the Binary String Alternating


// Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

// The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

// Any two characters may be swapped, even if they are not adjacent.



// **** Solution ********

class Solution {
public:
    int minSwaps(string s) {
        
        int cnt0=0,cnt1=0;
      
        //count number of 0s and 1s.
        for(char c:s){
            if(c=='0') ++cnt0;
            else ++cnt1;
        }
        
        if(abs(cnt0-cnt1)>1) return -1;
        
        int mn0=0,mn1=0;
        
        for(int i=0;i<s.size();i+=2){
            
            if(s[i]=='0') ++mn1; 
            if(s[i]=='1') ++mn0;
 
        }
       
        if(cnt0>cnt1){
            return mn0;
        }
         if(cnt0<cnt1){
            return mn1;
        }
     
        return min(mn0,mn1);
    }
};


// Time Complexity: O(n)
