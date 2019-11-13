/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p, *q, *tmp = new ListNode(0), *result;
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        p = head;
        result = head -> next;
        while (p->next != NULL) {
            q = p->next;
            p->next = q->next;
            q->next = p;
            tmp->next = q;
            if (p->next == NULL) break;
            tmp = p;
            p = p->next;
        }
        return result;
    }
};
// @lc code=end

