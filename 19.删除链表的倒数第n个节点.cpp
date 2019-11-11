/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode start(0);
        start.next = head;
        ListNode *p=&start, *q=&start;
        while (p != NULL) {
            if (i==n+1) {
                q = q->next;
            } 
            p = p->next;
            if (i<=n) i++;
        }
        q->next = q->next->next;
        return start.next;
    }
};
// @lc code=end

