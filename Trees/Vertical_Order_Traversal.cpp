/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root, map<int, vector<int> > &Hash, int HD)
{
    if(root == NULL)
                    return;
                    
    queue< pair <TreeNode* , int > > Q;
    
    pair <TreeNode* , int > cur, nxt;
    
    cur = make_pair(root, HD);
    
    Q.push(cur);
    
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        
        TreeNode* NODE = cur.first;
        int dist = cur.second;
        
        Hash[dist].push_back(NODE->val);
        
        if(NODE->left != NULL)
        {
            nxt = make_pair(NODE->left, dist-1);
            Q.push(nxt);
        }
        if(NODE->right != NULL)
        {
            nxt = make_pair(NODE->right, dist+1);
            Q.push(nxt);
        }
    }
    
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root)
{
    vector<vector<int> > ans;
    
    if(root == NULL)
                    return ans;
                    
    map<int, vector<int> > Hash;
    
    solve(root, Hash, 0);
    
    vector<int> temp;
    for(auto it = Hash.begin(); it != Hash.end(); it++)
    {
        temp = it->second;
        
        ans.push_back(temp);
    }
    return ans;
}
