/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* dfs(ListNode* A, int B,int& count){
     ListNode* temp = A;

     // check if B size of list is present or not
    for(int i=0;i<B;i++){
        if(temp==NULL){
            return A;
        }
        temp = temp->next;
    }

    // check if we had to ignore or reverse the list
    if(count&1){
        // ignore
        int c  = 0;
        ListNode* curr = A;
        ListNode* prev = NULL;
        while(c<B and curr!=NULL){
            prev = curr;
            curr=curr->next;
            c++;
        }
        count+=1;
        prev->next = dfs(curr,B,count); 
        return A;
    }
    else{
        // reverse the list
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* curr = A;
        int c = 0;
        while(c<B and curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            c++;
        }
        count+=1;
        if(nxt!=NULL){
            A->next = dfs(nxt,B,count);
        }
        return prev;
    }
    return NULL;
 }
ListNode* Solution::solve(ListNode* A, int B) {
    int count = 0;
    return dfs(A,B,count);
}
