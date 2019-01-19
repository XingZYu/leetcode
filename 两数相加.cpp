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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode * result, * tmp, * p;
        result = new ListNode((l1->val + l2->val)%10);
        tmp = result;
        carry = (l1->val + l2->val)/10;
        l1 = l1->next; l2 = l2->next;
        while (l1!=NULL && l2!=NULL) {
            p = new ListNode((l1->val + l2->val + carry)%10);
            tmp -> next = p;
            carry = (l1->val + l2->val + carry)/10;
            tmp = tmp->next; l1 = l1->next; l2 = l2->next;
        }
        while (l1!=NULL)
        {            
            p = new ListNode((l1->val + carry)%10);
            tmp -> next = p;
            carry = (l1->val + carry)/10;
            tmp = tmp->next; l1 = l1->next;
        }
        while (l2!=NULL)
        {            
            p = new ListNode((l2->val + carry)%10);
            tmp -> next = p;
            carry = (l2->val + carry)/10;
            tmp = tmp->next; l2 = l2->next;
        }
        if (carry != 0) 
        {
            p = new ListNode(carry%10);
            tmp -> next = p;
        }
        return result;
    }
};
