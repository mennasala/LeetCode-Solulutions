/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(original);
        int cntOriginal=0;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            cntOriginal++;
            if(current==target){ 
                 break;
            }
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        } 
        queue<TreeNode*>qCloned;
        qCloned.push(cloned);
        int cntCloned=0;
        while(!qCloned.empty()){
            TreeNode* current=qCloned.front();
            qCloned.pop();
            cntCloned++; 
            if(cntCloned==cntOriginal){ 
                return current;
            }
            if(current->left)
                qCloned.push(current->left);
            if(current->right)
                qCloned.push(current->right);
        }
        return NULL;
    }
};