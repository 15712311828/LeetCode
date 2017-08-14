#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
          return 0;
        }
        vector<int> next(needle.length()+1,0);
        int j=0;
        for(int i=1;i<needle.length();i++){
          while(j!=0&&needle[i]!=needle[j]){
            j=next[j];
          }
          if(needle[i]==needle[j]){
            j++;
          }
          next[i+1]=j;
        }
        j=0;
        for(int i=0;i<haystack.length();i++){
          while(j!=0&&haystack[i]!=needle[j]){
            j=next[j];
          }
          if(haystack[i]==needle[j]){
            j++;
            if(j==needle.length()){
              return i-needle.length()+1;
            }
          }
        }
        return -1;
    }
};

int main()
{
  (new Solution())->strStr("abc","bc");
    cout << "Hello world!" << endl;
    return 0;
}
