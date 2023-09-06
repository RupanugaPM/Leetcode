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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* tmp=head;
        int x=0;
        while(tmp){
            tmp=tmp->next;
            x++;
        }
        vector<ListNode*>ans;
        tmp=head;
        int kk=k;
        for(int i=0;i<kk;i++){
            
            ListNode* anspush;
            if(tmp){
                anspush=new ListNode(tmp->val);
            }
            else{
                anspush=nullptr;
            }
            ListNode* tmp1=anspush;
            for(int j=0;j<(x+k-1)/k-1;j++){
                if(tmp->next){
                    tmp=tmp->next;
                    ListNode* tmp2=new ListNode(tmp->val);
                    tmp1->next=tmp2;
                    tmp1=tmp2;
                }
            }
            cout<<x<<" "<<k<<endl;
            x-=(x+k-1)/k;
            k--;
            ans.push_back(anspush);
            if(tmp!=nullptr)
                tmp=tmp->next;
        }
        return ans;
    }
};