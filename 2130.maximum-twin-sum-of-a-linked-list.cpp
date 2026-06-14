/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

// @lc code=start
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
    ListNode *reverse(ListNode *a){
        ListNode*prev=nullptr;
        while(a){
            ListNode *b=a->next;
            a->next=prev;
            prev=a;
            a=b;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=slow->next;
        while(fast and fast->next){slow=slow->next;fast=fast->next->next;}
        ListNode*a=reverse(slow->next);
        int maxi=INT_MIN;
        slow->next=nullptr;
        slow=head;
        while(slow and a){
            int aa=slow->val+ a->val;
            maxi=max(maxi,aa);
            slow=slow->next;
            a=a->next;
        }
        return maxi;
    }
};
// @lc code=end

