/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Test for the quickest code i've seen.
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        if (!l1) return l2;
        else if (!l2) return l1;
        ListNode *res = new ListNode((l1->val + l2->val) % 10);
        ListNode *head = res;
        add = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != nullptr && l2 != nullptr){
            res->next = new ListNode((l1->val + l2->val + add) % 10);
            res = res->next;
            add = (l1->val + l2->val + add) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != nullptr){
            while(l1 != nullptr){
                res->next = new ListNode((l1->val + add) % 10);
                res = res->next;
                add = (l1->val + add) / 10;
                l1 = l1->next;
            }
        }
        else if (l2 != nullptr){
            while(l2 != nullptr){
                res->next = new ListNode((l2->val + add) % 10);
                res = res->next;
                add = (l2->val + add) / 10;
                l2 = l2->next;
            }
        }
        if (add != 0){
            res->next = new ListNode(add);
        }

        return head;
    }
};