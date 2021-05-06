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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head)
    {
        int c = 0;
        // ListNode* temp = head;
        while(head!=NULL)
        {
            c++;
            // temp=temp->next;
            head = head->next;
        }
        return c;
    }
    TreeNode* solve(ListNode*& head, int n)
    {
        if(n<=0)
        {
            return NULL;
        }
        TreeNode* l = solve(head,n/2);
        TreeNode* root = new TreeNode(head->val);
        root->left = l;
        head=head->next;
        root->right = solve(head,(n-1)/2);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = count(head);
        return solve(head,n);
    }
};









