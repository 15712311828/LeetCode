#include <iostream>
#include <vector>
#include <map>
#include <string>


using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
      map<char,int> charMap;
      for(auto c:t){
        auto it=charMap.find(c);
        if(it==charMap.end()){
          charMap.insert(make_pair(c,1));
        }
        else{
          it->second++;
        }
      }
      int i=0;
      int j=1;
      int count=0;
      int ansi=0;
      int ansj=s.length();
      int ansLength=s.length()+1;
      for(auto c:s){
        auto it=charMap.find(c);
        if(it==charMap.end()){
          j++;
        }
        else{
          it->second--;
          if(it->second>=0){
            count++;
            if(count==t.length()){
              while(count==t.length()){
                auto it=charMap.find(s[i]);
                if(it==charMap.end()){
                  i++;
                }
                else{
                  i++;
                  it->second++;
                  if(it->second>=1){
                    count--;
                  }
                }
              }
              if(j-i+1<ansLength){
                ansi=i-1;
                ansj=j;
                ansLength=j-i+1;
              }
            }
          }
          j++;
        }
      }
      if(ansLength>s.length())
        return "";
      return s.substr(ansi,ansLength);
    }
};

int main()
{
    cout << (new Solution())->minWindow("aa","a")<< endl;
    return 0;
}
