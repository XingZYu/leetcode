/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p, *q, *tmp, *result;
        p = l1;
        q = l2;
        result = new ListNode(0);
        tmp = result;
        while (p!=NULL && q!=NULL) {
            if (p->val < q->val) {
                tmp->next = p;
                p=p->next;
            }
            else {
                tmp->next = q;
                q=q->next;
            }
            tmp = tmp->next;
        }
        if (p==NULL) tmp->next = q;
        else tmp->next = p;
        return result->next;
    }
};
// @lc code=end

