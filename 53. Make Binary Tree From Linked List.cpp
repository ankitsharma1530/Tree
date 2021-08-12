void convert(Node *head, TreeNode *&root) {
    // Your code here
    
    if(head == NULL)
    {
        return;
    }
    
    Node *curr = head;
    
    root = new TreeNode(curr->data);
    // copy the head of linkedlist in to the root
    curr = curr->next;
    
    queue<TreeNode*> q;
    // push the root into the queue
    q.push(root);
    
    while(curr != NULL)
    {
        TreeNode *temp = q.front();
        // take the tree node
        
        if(curr)
        {
            // if curr is present put it to the left of the tree node
            temp->left = new TreeNode(curr->data);
            curr = curr->next;
        }
        
        if(curr)
        {
            // if curr->next is present put it to the right of the tree node
            temp->right = new TreeNode(curr->data);
            curr = curr->next;
        }
        
        // if temp->left!=NULL this means we can add node to the left of tree
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
        
        q.pop();
    }
}
