TreeNode* searchBST(TreeNode* root, int val) {
    // da tim thay hoac cay rong
    if (root == nullptr || root->val == val ) return root;
    
    // tim ben trai va phai
    if (root->val > val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}
