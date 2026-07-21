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
    int len(ListNode *head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=len(headA);
        int lenB=len(headB);
        int diff=abs(lenA-lenB);
        //length mai jitna differnce ho us node ko phele hi utna aage bdha do
        if(lenA>lenB){
            while(diff--){
                headA=headA->next;
            }
        }
        else{
            while(diff--){
                headB=headB->next;
            }
        }
        ListNode *temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp2;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
        
    }
};