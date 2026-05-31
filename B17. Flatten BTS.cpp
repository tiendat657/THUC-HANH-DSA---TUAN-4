TreeNode* cur;

void preorder(TreeNode* node) {
    if (node == nullptr) return;
    
    TreeNode* nextLeft = node->left;
    TreeNode* nextRight = node->right;
    
    cur->right = node;
    node->left = nullptr;
    cur = node;
    
    preorder(nextLeft);
    preorder(nextRight);
}

void flatten(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode dummy = TreeNode(0);
    
    cur = &dummy;
    
    preorder(root);
}
