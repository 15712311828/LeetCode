#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty()||words.empty())
          return res;
        int length=words[0].length();
        int num=words.size();
        unordered_map<string,int> wordsMap;
        for(auto word:words){
          if(wordsMap.find(word)==wordsMap.end())
            wordsMap.insert(unordered_map<string,int>::value_type(word,1));
          else
            wordsMap.find(word)->second++;
        }
        for(int i=0;i<length;i++){
          int c=0;
          int j=i;
          for(;j+length<=s.length();j+=length){
            auto it=wordsMap.find(s.substr(j,length));
            if(it!=wordsMap.end()){
              it->second--;
              c++;
              while(it->second<0){
                wordsMap.find(s.substr(j-length*c+length,length))->second++;
                c--;
              }
              if(c==num){
                res.push_back(j-length*c+length);
                wordsMap.find(s.substr(j-length*c+length,length))->second++;
                c--;
              }
            }
            else{
              while(c>0){
                wordsMap.find(s.substr(j-length*c,length))->second++;
                c--;
              }
            }
          }
          while(c>0){
            wordsMap.find(s.substr(j-length*c,length))->second++;
            c--;
          }
        }
        return res;
    }
};

int main(){
  vector<string> s;
  s.push_back(string("aa"));
  s.push_back(string("aa"));
  s.push_back(string("aa"));
  auto v=(new Solution())->findSubstring(string("aaaaaaaa"),s);
  for(auto i:v){
    cout<<i<<" ";
  }
  return 0;
}
