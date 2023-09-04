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
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
        ListNode* l1=head;
        ListNode* l2=head;
        l1=l1->next;
        if(l1==nullptr){
            return false;
        }
        l2=l1->next;
        if(l2==nullptr){
            return false;
        }
        while(l1!=l2){
            l1=l1->next;
            l2=l2->next;
            if(l2==nullptr){
                return false;
            }
            l2=l2->next;
            if(l2==nullptr){
                return false;
            }
        }
        return true;
    }
};