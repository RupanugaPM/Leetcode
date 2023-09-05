/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* tmp=head;
        Node* ans=new Node(tmp->val);
        Node* tmp2=ans;
        while(tmp->next!=nullptr){
            tmp=tmp->next;
            Node* t2=new Node(tmp->val);
            tmp2->next=t2;
            tmp2=t2;
        }
        tmp=head;
        tmp2=ans;
        while(tmp2!=nullptr){
            Node* t=head;
            Node* tt=tmp->random;
            if(tt==nullptr){
                tmp2=tmp2->next;
                tmp=tmp->next;
                continue;
            }
            Node* tt2=ans;
            while(t!=tt){
                tt2=tt2->next;
                t=t->next;
            }
            tmp2->random=tt2;
            tmp2=tmp2->next;
            tmp=tmp->next;
        }
        return ans;
    }
};