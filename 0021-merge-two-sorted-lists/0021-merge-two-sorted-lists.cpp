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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* d=new ListNode(-1);
        ListNode* temp=d;
        ListNode* temp1=list1; ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val>temp2->val){
                temp->next=new ListNode(temp2->val);
                temp2=temp2->next;
            }else{
                temp->next=new ListNode(temp1->val);
                temp1=temp1->next;
            }
             temp=temp->next;
        }
        while(temp1!=NULL){
            temp->next=new ListNode(temp1->val);
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            temp->next=new ListNode(temp2->val);
            temp=temp->next;
            temp2=temp2->next;
        }
        return d->next;
    }
};