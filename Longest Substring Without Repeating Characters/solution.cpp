#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastAppear[255]={0};
        int res=0;
        int last;
        for(int i=0;i<s.length();i++){
            if(i==0){
                last=1;
            }
            else{
                last=min(last+1,i+1-lastAppear[s[i]]);
            }
            res=max(res,last);
            lastAppear[s[i]]=i+1;
        }
        return res;
    }
};

int main(){
    int res=(new Solution())->lengthOfLongestSubstring("abcabcbb");
    cout<<res;
    return 0;
}
