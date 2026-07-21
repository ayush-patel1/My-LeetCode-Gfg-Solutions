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
    int len(ListNode* head) {
        int l = 0;
        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = len(head);

        if (l == n) {
            ListNode* t = head;
            head = head->next;
            delete t;
            return head;
        }

        ListNode* temp = head;
        for (int i = 1; i < l - n; i++)
            temp = temp->next;

        ListNode* t = temp->next;
        temp->next = t->next;
        delete t;

        return head;
    }
};