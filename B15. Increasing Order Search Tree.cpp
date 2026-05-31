TreeNode* curr = nullptr;

void inorder(TreeNode* node) {
    if (node == nullptr) return;
    
    inorder(node->left);
    
    node->left = nullptr;
    curr->right = node;
    curr = node;
    
    inorder(node->right);
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode dummy = TreeNode(0);
    
    curr = &dummy;
    
    inorder(root);
    
    return dummy.right;
}
