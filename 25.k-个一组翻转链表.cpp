/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    void reverse(ListNode* head, ListNode* tail) {
        ListNode *p=head, *q, *tmp;
        q = p->next;
        while (p!=tail) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        cout << tmp->val << endl;
        head->next = tmp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p=head, *q=head, *prev=new ListNode(0);
        int count=0, first=0;
        while (p!=NULL) {
            count++;
            if (count == k) {
                count = 0;
                if (!first) head = p;
                reverse(q, p);
                prev->next = p;
                prev = p;
                p = p->next;
                q = p;
                first++;
            } 
            else p=p->next;
        }

        return head;
    }
};
// @lc code=end

