#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int z1=0;
        int z2=nums.size();
        for(int i=0;i<nums.size();i++){
          if(z1==0&&nums[i]>=0)
            z1=i;
          if(z2==nums.size()&&nums[i]>0)
            z2=i;
        }
        for(int i=0;i<z2;i++){
          while(i>0&&nums[i]==nums[i-1]){
            i++;
            if(i==nums.size())
              break;
          }
          if(i==nums.size())
              break;
          for(int j=i+1;j<nums.size();j++){
            while(j>i+1&&nums[j]==nums[j-1]){
              j++;
              if(j==nums.size())
                break;
            }
            if(j==nums.size())
                break;
            for(int k=max(j+1,z1);k<nums.size();k++){
              while(k>j+1&&nums[k]==nums[k-1]){
                k++;
                if(k==nums.size())
                  break;
              }
              if(k==nums.size())
                  break;
              if(nums[i]+nums[j]+nums[k]==0){
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                res.push_back(v);
              }
            }
          }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
