#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        deque<string> q;
        for(auto c:digits){
          string str=s[c-'0'];
          if(q.empty()){
            for(auto ch:str){
              string t;
              t+=ch;
              q.push_back(t);
            }
          }
          else{
            int l=q.front().length();
            while(q.front().length()==l){
              string temp=q.front();
              q.pop_front();
              for(auto ch:str){
                string t=temp;
                t+=ch;
                q.push_back(t);
              }
            }
          }
        }
        vector<string> v(q.begin(),q.end());
        return v;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
