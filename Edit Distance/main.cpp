#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()||word2.empty()){
          return abs((int)word1.length()-(int)word2.length());
        }
        vector<int> dp(word1.length()+1,0);
        vector<int> lastdp(word1.length()+1,0);
        for(int i=0;i<dp.size();i++){
          dp[i]=lastdp[i]=i;
        }
        for(int i=0;i<word2.length();i++){
          for(int j=0;j<=word1.length();j++){
            if(j==0){
              dp[j]=lastdp[j]+1;
              continue;
            }
            dp[j]=min(lastdp[j]+1,dp[j-1]+1);
            if(word2[i]!=word1[j-1])
              dp[j]=min(dp[j],lastdp[j-1]+1);
            else
              dp[j]=min(dp[j],lastdp[j-1]);
          }
          dp.swap(lastdp);
        }
        return lastdp[word1.length()];
    }
};

int main()
{
    cout << (new Solution())->minDistance("","a")<< endl;
    return 0;
}
