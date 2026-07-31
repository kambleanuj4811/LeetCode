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
    void Inorder(TreeNode*root, vector<int>&inorder){
        if(root==NULL){
            return ;
        }
        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>inorder;
        Inorder(root, inorder);
        int Minn = INT_MAX;
        for(int i=0 , j=1 ; j<inorder.size(); i++, j++){
            int currmin = abs(inorder[i]-inorder[j]);
            Minn = min(Minn, currmin);
        }

        return Minn;
    }
};