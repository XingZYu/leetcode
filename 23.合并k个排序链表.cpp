/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    void mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p, *q, *tmp1, *tmp2;
        p = l1;
        q = l2;
        while (p!=NULL && q!=NULL) {
            if (p->next == NULL) {
                p->next = q;
                break;
            }
            if (p->next->val < q->val) {
                p=p->next;
            }
            else {
                tmp1 = p->next;
                p->next = q;
                while (q!=NULL && q->val<p->val && q->val>=p->next->val) q = q->next;
                if (q!=NULL) {
                    tmp2 = q->next;
                    q->next = tmp1;
                    q = tmp2;
                }
            }
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, n=lists.size();
        if (n==0) return NULL;
        if (n==1) return lists[0];
        for (i=0; i<lists.size()-1; ++i) {
            if (lists[i]==NULL || lists[i+1]==NULL) 
            {
                if (lists[i+1] == NULL) lists[i+1] = lists[i];
                continue;
            }
            if (lists[i]->val < lists[i+1]->val) {
                mergeTwoLists(lists[i], lists[i+1]);
                lists[i+1] = lists[i];
            }
            else mergeTwoLists(lists[i+1], lists[i]);
        }
        return lists[n-1];
    }
};
// @lc code=end

