#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
          return "";
        }
        int i=0;
        while(1){
          char c=-1;
          for(auto s:strs){
            if(s.length()>=i+1&&c==-1){
              c=s[i];
            }
            else if(s.length()>=i+1&&s[i]==c){

            }
            else{
              return strs[0].substr(0,i);
            }
          }
          i++;
        }
    }
};

int main()
{
    string s[2]={"abc","aac"};
    vector<string> v(s,s+2);
    cout << (new Solution())->longestCommonPrefix(v) << endl;
    return 0;
}
