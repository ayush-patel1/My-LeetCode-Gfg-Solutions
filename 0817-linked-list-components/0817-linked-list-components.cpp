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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int count=0;
        ListNode* temp=head;
        bool flag=false;
        while(temp){
            while( temp!=NULL && st.find(temp->val)!=st.end()){ 
                flag=true;
                temp=temp->next;     
            }
            if(flag){
                count++;
                flag=false;
            }else{
                temp=temp->next;
            }
        }
        return count;
    }
};