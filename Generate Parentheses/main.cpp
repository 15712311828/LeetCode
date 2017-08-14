#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        deque<pair<string,int> > q;
        q.push_back(make_pair("(",1));
        while(q.front().first.length()<2*n){
          auto p=q.front();
          q.pop_front();
          if(p.second>0){
            q.push_back(make_pair(p.first+")",p.second-1));
          }
          if(p.second<2*n-p.first.length()){
            q.push_back(make_pair(p.first+"(",p.second+1));
          }
        }
        vector<string> v;
        for(auto p:q){
          v.push_back(p.first);
        }
        return v;
    }
};

int main()
{
  (new Solution())->generateParenthesis(3);
    cout << "Hello world!" << endl;
    return 0;
}
