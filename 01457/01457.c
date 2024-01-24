/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count(int* arr){
    int cnt=0;
    for (size_t i =1; i <10; ++i){
        if(arr[i] %2 == 1 ) cnt++;
    }
    return cnt;
}

int dfs(struct TreeNode* root, int* freq) {
    freq[root->val]++;

    if (root->left == NULL && root->right == NULL) {
        int cnt = count(freq);
        freq[root->val]--;
        return (cnt <= 1);
    }

    int ret = 0;

    if (root->left != NULL)
        ret += dfs(root->left, freq);
    if (root->right != NULL)
        ret += dfs(root->right, freq);
    freq[root->val]--;

    return ret;
}

int pseudoPalindromicPaths(struct TreeNode* root) { int freq[10] = {0};
    return dfs(root, freq);
 }