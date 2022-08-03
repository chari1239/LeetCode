// https://leetcode.com/problems/merge-two-sorted-lists/

// 21. Merge Two Sorted Lists

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
         ListNode* cur = list1;
        
        if(list1->val>list2->val) {
            cur=list2;
            list2 = list2->next;
        }else{
            list1 = list1->next;
        }
        ListNode* ans = cur;
        while(list1!=NULL && list2!=NULL){
            
            if(list1->val<list2->val){
                cur->next = list1;
                list1=list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            
            cur = cur->next;
            
        }
        
        if(list1 != NULL){
            cur->next = list1;
        }
        if(list2 != NULL){
            cur->next = list2;
        }
        return ans;
        
    }
};


// Time Complexity: O(n+m) n&m are lengths of list1 & list2
// Space Complexity: O(1)

