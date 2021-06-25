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
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }
        if(!head->next || !head->next->next){
            return;
        }
        stack<ListNode*>s;
        ListNode* curr = head;
        int size = 0;
        while(curr!=NULL){
            s.push(curr);
            size++;
            curr=curr->next;
        }
        ListNode* res = head;
        for(int i=0;i<size/2;i++){
            // Between every two nodes insert the one in the top of the stack
            ListNode* element = s.top();
            s.pop();
            element->next = res->next;
            res->next = element;
            res=res->next->next;
        }
        res->next = NULL;
    }
};
