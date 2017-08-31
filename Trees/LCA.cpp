/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isPresent(TreeNode* root, int num)
{
    if(root == NULL)
                    return false;

    if(root->val == num)
                    return true;
    
    return isPresent(root->left,num) || isPresent(root->right,num); 
}
TreeNode* solve(TreeNode* root, int val1, int val2)
{
    if(root == NULL)
                    return root;
                    
    if(root->val == val1 && root->val == val2)
                                                return root;
    
    TreeNode *x, *y;
    x = solve(root->left, val1, val2);
    
    if(x!= NULL && x->val != val1 && x->val != val2)    // already found the lca in subtree
    {
        return x;
    }
    
    y = solve(root->right, val1, val2);
    if(y!= NULL && y->val != val1 && y->val != val2)    // already found the lca in subtree
    {
        return y;
    }
    
    if(x!=NULL && y!=NULL)
    {
        return root;            // x and y in different subtrees
    }
    else if(root->val == val1 || root->val == val2)
    {
        return root;
    }
    else
    {
        if(x == NULL)
                    return y;
        return x;
    }
}
int Solution::lca(TreeNode* root, int val1, int val2) 
{
    if(!isPresent(root,val1) || !isPresent(root,val2))
                                            return -1;
    
    TreeNode *LCA = solve(root,val1,val2);
    
    return LCA->val;
}
