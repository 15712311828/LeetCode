#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<int> res(s.size(),0);
        vector<int> dp(s.size(),0);
        vector<int> lastdp(s.size(),0);
        for(int i=0;i<s.length();i++){
          for(int j=0;j<=i;j++){
            if(i==j){
              dp[j]=1;
            }
            else if(i==j+1){
              if(s[i]==s[j]){
                dp[j]=1;
              }
              else
                dp[j]=0;
            }
            else if(lastdp[j+1]&&s[i]==s[j]){
              dp[j]=1;
            }
            else
              dp[j]=0;
          }
          res[i]=i+1;
          for(int j=0;j<=i;j++){
            if(dp[j]){
              if(j-1>=0)
                res[i]=min(res[i],res[j-1]+1);
              else
                res[i]=1;
            }
          }
          dp.swap(lastdp);
        }
        return res[s.size()-1]-1;
    }
};

int main()
{
    cout << (new Solution())->minCut("ab") << endl;
    return 0;
}
