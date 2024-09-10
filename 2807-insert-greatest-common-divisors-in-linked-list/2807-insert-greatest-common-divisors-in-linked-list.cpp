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
    int gcd(int a,int b){
        if(a==0)
            return b;
         return gcd(b%a,a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ptr=head;
        while(ptr!=NULL){
            int a,b;
            a=ptr->val;
            if(ptr->next) {
                b=ptr->next->val;
                int greatest_divisor=gcd(min(a,b),max(a,b));
                ListNode* node=new ListNode(greatest_divisor);
               node->next=ptr->next;
                ptr->next=node;
                ptr=node->next; 
            }
            else ptr=ptr->next;
        }
       return head;
    }
};