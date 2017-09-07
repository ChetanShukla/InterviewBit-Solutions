/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxPath(TreeNode* root, int &res)
{
    if(root == NULL)        // base case
    {
        return 0;
    }
    
    int lft, rgt;
    
    // if max sum path includes the root and might extend to ancestor nodes of the root
    lft = maxPath(root->left, res);     
    rgt = maxPath(root->right, res);

    // max with at most one subtree included
    int max_single = max(max(lft,rgt) + root->val, root->val);
    
    // max with root node as the topmost node
    int max_top = max(max_single, lft+rgt+root->val);
    
    // updating res so that we can take into consideration the case where max sum
    // path comes from one of the subtree with root excluded
    res = max(res, max_top);
    
    return max_single;
}
int Solution::maxPathSum(TreeNode* root) 
{
    int res = INT_MIN;
    
    int sol = maxPath(root,res);
    
    return res;
}
