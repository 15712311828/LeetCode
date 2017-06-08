#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<set<int>> vs;
        for(auto i:nums){
          vector<set<int>>::iterator s1=vs.end();
          vector<set<int>>::iterator s2=vs.end();
          vector<set<int>>::iterator s3=vs.end();
          for(auto it=vs.begin();it!=vs.end();it++){
            if(s1==vs.end()){
              if(it->count(i-1)!=0)
                s1=it;
            }
            if(s2==vs.end()){
              if(it->count(i)!=0)
                s2=it;
            }
            if(s3==vs.end()){
              if(it->count(i+1)!=0)
                s3=it;
            }
          }
          if(s2==vs.end()){
            if(s1!=vs.end()&&s3!=vs.end()){
              s1->insert(s3->begin(),s3->end());
              s1->insert(i);
              vs.erase(s3);
            }
            else if(s1!=vs.end()&&s3==vs.end()){
              s1->insert(i);
            }
            else if(s3!=vs.end()&&s1==vs.end()){
              s3->insert(i);
            }
            else{
              set<int> s;
              s.insert(i);
              vs.push_back(s);
            }
          }
        }
        int res=0;
        for(auto s:vs){
          if(s.size()>res)
            res=s.size();
        }
        return res;
    }
};

int main()
{
   int a[]={1,2,3,6,7,8,9};
   vector<int> v(a,a+7);
    cout << (new Solution())->longestConsecutive(v)<< endl;
    return 0;
}
