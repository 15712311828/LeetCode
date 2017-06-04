#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   TreeNode* last=new TreeNode(-10000);
   TreeNode* first=NULL;
   TreeNode* second=NULL;
public:
    void pretraval(TreeNode* root){
      if(!root){
        return;
      }
      pretraval(root->left);
      if(root->val<last->val){
        if(!first){
          first=last;
          second=root;
        }
        else
          second=root;
      }
      last=root;
      pretraval(root->right);
    }
    void recoverTree(TreeNode* root) {
        pretraval(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};

void print(TreeNode* root){
  if(!root){
    return;
  }
  print(root->left);
  cout<<root->val<<" ";
  print(root->right);
}

int main()
{
  TreeNode * _0=new TreeNode(0);
  TreeNode * _1=new TreeNode(1);
  //TreeNode * _2=new TreeNode(2);
  _0->left=_1;
  //_0->left=_2;
  //_1->left=_0;
  print(_0);
  (new Solution())->recoverTree(_0);
  print(_0);

    return 0;
}
