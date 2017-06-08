#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int res=-1000000;
public:
    int traval(TreeNode* root){
      if(!root){
        return 0;
      }
      int l=traval(root->left);
      int r=traval(root->right);
      res=max(res,l+r+root->val);
      return max(max(l,r)+root->val,0);
    }
    int maxPathSum(TreeNode* root) {
        traval(root);
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
