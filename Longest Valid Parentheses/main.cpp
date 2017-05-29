#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    const int L_=-1;
    const int _R=-2;
    int longestValidParentheses(string s) {
        stack<int> ss;
        int max=0;
        for(auto c:s){
          if(c=='(')
              ss.push(L_);
          else{
            if(ss.empty()||ss.top()==_R)
              ss.push(_R);
            else if(ss.top()==L_){
              ss.pop();
              int temp=1;
              if(!ss.empty()&&ss.top()!=L_&&ss.top()!=_R){
                temp+=ss.top();
                ss.pop();
              }
              if(temp>max)
                max=temp;
              ss.push(temp);
            }
            else{
              int temp=ss.top();
              ss.pop();
              if(!ss.empty()&&ss.top()==L_){
                ss.pop();
                temp++;
                if(!ss.empty()&&ss.top()!=L_&&ss.top()!=_R){
                  temp+=ss.top();
                  ss.pop();
                }
                if(temp>max)
                  max=temp;
                ss.push(temp);
              }
              else{
                ss.push(temp);
                ss.push(_R);
              }
            }
          }
        }
        return 2*max;
    }
};

int main(){
  cout<<(new Solution())->longestValidParentheses("(()))()");
  return 0;
}
