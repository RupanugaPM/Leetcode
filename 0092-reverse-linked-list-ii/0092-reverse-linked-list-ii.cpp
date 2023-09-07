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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        l--;
        r--;
        while(l<r){
            swap(v[l],v[r]);
            l++;
            r--;
        }
        ListNode* ans=new ListNode(v[0]);
        ListNode* t=ans;
        for(int i=1;i<v.size();i++){
            ListNode* tmp=new ListNode(v[i]);
            t->next=tmp;
            t=tmp;
        }
        return ans;
    }
};