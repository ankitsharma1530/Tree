Node* head;

Node *convertToDLL_util(Node *root) {
    if (root == NULL) 
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        root->right = head;
        if (head != NULL) 
            (head)->left = root;
        head = root;
        return NULL;
    }
    root->right = convertToDLL_util(root->right);
    root->left = convertToDLL_util(root->left);
    return root;
}

Node * convertToDLL(Node *root){
    head = NULL;
    root = convertToDLL_util(root);
    return head;
}
