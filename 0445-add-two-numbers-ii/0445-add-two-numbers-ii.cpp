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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = reverse(l1);
        ListNode* num2 = reverse(l2);
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (num1 || num2 || carry) {
            int sum = carry;
            if (num1) {
                sum += num1->val;
                num1 = num1->next;
            }
            if (num2) {
                sum += num2->val;
                num2 = num2->next;
            }
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return reverse(dummy->next);
    }
};
