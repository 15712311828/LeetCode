#include <iostream>

using namespace std;

class Solution {
public:
    /*bool isMatch(string s, string p) {
        if(s.size()==0&&p.size()==0){
          return true;
        }
        if(p.size()==0){
          return false;
        }
        if(p[0]=='*'){
          int c=0;
          for(;c<p.size();c++){
            if(p[c]!='*')
              break;
          }
          for(int i=0;i<=s.size();i++){
            if(isMatch(s.substr(i,s.size()-i),p.substr(c,p.size()-c)))
              return true;
          }
          return false;
        }
        if(s.size()==0){
          return false;
        }
        if(p[0]=='?'||p[0]==s[0]){
          return isMatch(s.substr(1,s.size()-1),p.substr(1,p.size()-1));
        }
        return false;
    }*/

    bool isMatch(string s, string p) {
      int ls=s.length();
      int lp=p.length();
      if(ls==0){
        int temp=true;
      for(auto c:p){
        if(c!='*'){
          temp=false;
        }
      }
        return lp==0||temp;
      }
      bool dp[ls+1]={0};
      for(int i=0;i<lp;i++){
        if(p[i]=='*'){
            dp[0]=i==0||dp[0];
            for(int j=1;j<ls;j++){
              dp[j]=dp[j]||dp[j-1];
            }
        }
        else{
            for(int j=ls-1;j>=0;j--){
              if(j==0){
                int temp=true;
                for(int k=0;k<i;k++){
                if(p[k]!='*'){
                    temp=false;
                }
                }
                dp[j]=(i==0||temp)&&(p[i]=='?'||p[i]==s[j]);
              }
              else
                dp[j]=dp[j-1]&&(p[i]=='?'||p[i]==s[j]);
            }
        }
      }
      return dp[ls-1];
    }
};

int main()
{
    if((new Solution())->isMatch(string("c"),string("*?"))){
      cout<<"Y";
    }
    else{
      cout<<"N";
    }
    return 0;
}
