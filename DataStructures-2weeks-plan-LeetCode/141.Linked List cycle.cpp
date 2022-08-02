// https://leetcode.com/problems/linked-list-cycle/

// 141. Linked List Cycle


// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.


// using extra memory

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> s;
        
        while(head!=NULL){
            
            if(s.insert(head).second == false) return true;
            
            head = head->next;
            
        }
        
        return false;
        
    }
};

// Time Complexity: O(n)
// Space Compleity: O(n)

// ************Second Approach (Best Approach) **********
// ***********Also known as Tortoise & Hare Logic ************


class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        if(head==NULL) return false;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
            
        }
        
        return false;
        
    }
};

// Time Complexity: O(n)
// Space Compleity: O(1)


