/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if(root->val == 2){
        return (evaluateTree(root->left) || evaluateTree(root->right));
    }
    else if(root->val == 3){
        return (evaluateTree(root->left) && evaluateTree(root->right));
    }
    return root->val;
}