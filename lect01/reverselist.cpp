// Lecture 1
// Reviewed basic pointer and linked list concepts
// Problem description is available on leet code: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
        
    }
};