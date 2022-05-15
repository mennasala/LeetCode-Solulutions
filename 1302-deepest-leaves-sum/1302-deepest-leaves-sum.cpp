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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int sz=q.size();
            sum=0;
            for(int i=1;i<=sz;i++){
                TreeNode* current=q.front();
                q.pop();
                sum+=current->val;
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
        }
        return sum;
    }
};