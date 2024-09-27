class Solution {
public:
    ListNode* reverse(ListNode* node, int k) {
        ListNode* curr = node;
        ListNode* prev = nullptr;
        ListNode* next_node = nullptr;
        while (curr && k--) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == left) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev_left = dummy;

        for (int i = 1; i < left; i++) {
            prev_left = prev_left->next;
        }

        ListNode* start = prev_left->next;
        ListNode* end = start;
        for (int i = 0; i < right - left; i++) {
            end = end->next;
        }

        ListNode* next_right = end->next;
        end->next = nullptr;

        ListNode* new_start = reverse(start, right - left + 1);

        prev_left->next = new_start;
        start->next = next_right;

        return dummy->next;
    }
};
