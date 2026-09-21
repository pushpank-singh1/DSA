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
    bool check(TreeNode* left, TreeNode* right){
        //both are null
        if(left == NULL && right == NULL){
            return true;
        }

        //one is null
        if(left == NULL || right == NULL){
            return false;
        }

        //different values
        if(left->val != right->val){
            return false;
        }

        //check mirror sides
        return check(left->left, right->right) &&
                check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return false;
        }

        return check(root->left, root->right);
    }
};