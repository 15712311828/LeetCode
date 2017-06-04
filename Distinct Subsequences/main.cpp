#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(s.length()+1,1);
        vector<int> lastdp(s.length()+1,1);
        for(int i=0;i<t.length();i++){
            dp[0]=0;
          for(int j=0;j<s.length();j++){
            dp[j+1]=dp[j]+lastdp[j]*(s[j]==t[i]?1:0);
          }
          dp.swap(lastdp);
        }
        return lastdp[s.length()];
    }
};

int main()
{
    cout << (new Solution())->numDistinct("aaa","aa") << endl;
    return 0;
}
