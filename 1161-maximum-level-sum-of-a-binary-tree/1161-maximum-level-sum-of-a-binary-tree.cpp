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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ans = 1;
        int maxSum = INT_MIN;

        while(!q.empty()){
            int n = q.size();
            int sum = 0;

            //process current level
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();

                // add all values in the current level
                sum += curr->val;

                if(curr->left != NULL){
                    q.push(curr->left);
                }

                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }

            // update maxSum
            if(sum > maxSum){
                maxSum = sum;
                ans = level;
            }
            level++;
        }

        return ans;
    }
};