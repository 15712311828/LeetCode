#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
    map<string,int> wl;
    vector<vector<string>> res;
    map<pair<string,string>,bool> path;
    vector<string> v;
    int l=1000000;
public:
    void dfs(const string & word,const string & endWord,vector<string>& wordList){
      v.push_back(word);
      if(word==endWord){
        res.push_back(v);
        l=min(l,(int)v.size());
      }
      else{
        for(auto s:wordList){
          auto it=path.find(make_pair(word,s));
          if(it==path.end()){
            string s1=word;
            string s2=s;
            int c=0;
            for(int k=0;k<s1.length();k++){
              if(s1[k]!=s2[k])
                c++;
            }
            if(c==1){
              path.insert(make_pair(make_pair(s1,s2),1));
              path.insert(make_pair(make_pair(s2,s1),1));
            }
            else{
              path.insert(make_pair(make_pair(s1,s2),0));
              path.insert(make_pair(make_pair(s2,s1),0));
            }
            it=path.find(make_pair(word,s));
          }
          if(wl[s]>=v.size()&&it->second){
            wl[s]=v.size();
            dfs(s,endWord,wordList);
          }
        }
      }
      v.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto s:wordList){
          wl.insert(make_pair(s,100000));
        }
        dfs(beginWord,endWord,wordList);
        for(auto it=res.begin();it!=res.end();){
          if((*it).size()>l)
            res.erase(it);
          else
            it++;
        }
        return res;
    }
};

int main()
{
  string beginWord="aaa";
  string endWord="abc";
  string a[]={"aba","aab","abb","abc"};
  vector<string> aa(a,a+4);

   auto res=(new Solution())->findLadders(beginWord,endWord,aa);
   for(auto v:res){
    for(auto s:v){
      cout<<s<<" ";
    }
    cout<<endl;
   }
    return 0;
}
