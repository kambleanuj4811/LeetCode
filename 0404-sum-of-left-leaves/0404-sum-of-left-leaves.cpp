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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int leftsum=0;
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL){
            leftsum=root->left->val;
        }
        else{
            leftsum=sumOfLeftLeaves(root->left);
        }
        int rightsum = sumOfLeftLeaves(root->right);

        return leftsum+rightsum;

        
    }
};