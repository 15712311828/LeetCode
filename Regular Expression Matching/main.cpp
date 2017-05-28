#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch_t(string s, string p,int posS,int posP){
      if(posS==s.size()&&posP==p.size()){
        return true;
      }
      else if(posP==p.size()){
        return false;
      }
      else{
        if(p[posP]=='.'){
          return isMatch_t(s,p,posS+1,posP+1);
        }
        else if(p[posP]=='*'){
          bool temp=false;
          for(int i=0;;i++){
            if(i>=2&&p[posP-1]!='.'&&s[posS+i-2]!=s[posS-1]){
              break;
            }
            if(posS+i-1>s.size()){
              break;
            }
            if(temp)
              break;
            temp|=isMatch_t(s,p,posS+i-1,posP+1);
          }
          return temp;
        }
        else{
          if(posS<s.size()&&s[posS]==p[posP]){
            return isMatch_t(s,p,posS+1,posP+1);
          }
          else if(p[posP+1]=='*'){
            return isMatch_t(s,p,posS,posP+2);
          }
          else{
            return false;
          }
        }
      }
    }
    bool isMatch(string s, string p) {
      return isMatch_t(s,p,0,0);
    }
};

int main(){
  auto so=new Solution();
  string s="aaaaaaaaaaaab";
  string p="a*a*a*a*a*a*a*a*a*a*a*b";
  bool b=so->isMatch(s,p);
  return 0;
}
