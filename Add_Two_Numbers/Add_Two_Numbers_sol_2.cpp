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
        ListNode *head = nullptr;
        ListNode *returnVal = nullptr;
        ListNode *pre = nullptr;

        int borrowDig(0);
        int nowDig(0);
        while (l1 || l2) {
            nowDig = borrowDig + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            borrowDig = (nowDig >= 10);
            nowDig %= 10;

            head = new ListNode(nowDig);
            if (!pre)
                returnVal = head;
            else
                pre->next = head;
            pre = head;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
        }
        if (borrowDig) {
            pre->next = new ListNode(borrowDig);
        }
        return returnVal;
    }
};