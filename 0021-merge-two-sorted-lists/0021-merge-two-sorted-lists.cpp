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
        ListNode*ans=new ListNode(0);
        ListNode* tmp=ans;
        while(list1 && list2){
            ListNode* tmp1=new ListNode(0);
            if(list1->val>list2->val){
                tmp1->val=list2->val;
                list2=list2->next;
            }
            else{
                tmp1->val=list1->val;
                list1=list1->next;
            }
            tmp->next=tmp1;
            tmp=tmp1;
        }
        while(list1){
            ListNode* tmp1=new ListNode(0);
            tmp1->val=list1->val;
            list1=list1->next;
            tmp->next=tmp1;
            tmp=tmp1;
        }
        while(list2){
            ListNode* tmp1=new ListNode(0);
            tmp1->val=list2->val;
            list2=list2->next;
            tmp->next=tmp1;
            tmp=tmp1;
        }
        return ans->next;
    }
};