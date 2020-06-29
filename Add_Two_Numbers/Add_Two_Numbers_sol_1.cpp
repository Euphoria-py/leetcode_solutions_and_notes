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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode();
        ListNode *returnVal = head;
        int borrowDig(0);
        int nowDig(0);
        while (l1 || l2 || borrowDig != 0) {
            if (l1) {
                nowDig += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                nowDig += l2->val;
                l2 = l2->next;
            }

            nowDig += borrowDig;

            if (nowDig >= 10) {
                borrowDig = 1;
                nowDig -= 10;
            } else {
                borrowDig = 0;
            }
            head->val = nowDig;
            if (!l1 && !l2 && borrowDig == 0)
                break;
            head->next = new ListNode();
            head = head->next;
            nowDig = 0;
        }
        return returnVal;
    }
};