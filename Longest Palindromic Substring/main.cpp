#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()){
          return 0;
        }
        bool dp[1000][1000];
        int maxn=1;
        int l=0,r=0;
        for(int i=0;i<s.length();i++){
          for(int j=0;j<=i;j++){
            if(i==j){
              dp[i][j]=true;
            }
            else{
              if(s[i]==s[j]){
                if(i-j==1)
                  dp[i][j]=true;
                else
                  dp[i][j]=dp[i-1][j+1];
                if(dp[i][j]){
                  if(i-j+1>maxn){
                    maxn=i-j+1;
                    l=j;
                    r=i;
                  }
                }
              }
              else{
                dp[i][j]=false;
              }
            }
          }
        }
        return s.substr(l,maxn);
    }
};

int main()
{
    cout << (new Solution())->longestPalindrome("babad") << endl;
    return 0;
}
