#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int ans[2];
        for(int i=0;i<nums.size();i++){
          for(int j=i+1;j<nums.size();j++){
            if(nums.at(i)+nums.at(j)==target){
              ans[0]=i;
              ans[1]=j;
              return vector<int>(ans,ans+2);
            }
          }
        }
    }
};

int main(){
    auto s=new Solution();
    vector<int> v;
    v.push_back(-1);
    v.push_back(4);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    vector<int> ans=s->twoSum(v,0);
    for(auto i:ans){
      cout<<i<<" ";
    }
    return 0;
}


