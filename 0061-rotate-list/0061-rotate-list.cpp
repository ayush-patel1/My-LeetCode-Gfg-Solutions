class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        int len = 0;
        ListNode* temp = head;
        ListNode* last_node = nullptr;
        while (temp) {
            len++;
            last_node = temp;
            temp = temp->next;
        }
        
        k = k % len;
        if (k == 0) return head;

        int move_forw = len - k;
        temp = head;
        ListNode* prev = nullptr;
        while (move_forw--) {
            prev = temp;
            temp = temp->next;
        }

        ListNode* new_head = temp;
        prev->next = nullptr;
        last_node->next = head;
        
        return new_head;
    }
};
