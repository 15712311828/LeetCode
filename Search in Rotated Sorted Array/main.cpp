#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
          return -1;
        }
        int i=0;
        int j=nums.size()-1;
        while(1){
          if(j-i<=1){
            if(target==nums[i])
              return i;
            else if(target==nums[j])
              return j;
            else
              return -1;
          }
          if(nums[i]<nums[j]){
            int mid=(i+j)>>1;
            if(target<nums[mid]){
              j=mid-1;
            }
            else{
              i=mid;
            }
          }
          else{
            int mid=(i+j)>>1;
            if(nums[mid]<nums[i]){
              if(target<=nums[j]&&target>=nums[mid]){
                i=mid;
              }
              else{
                j=mid;
              }
            }
            else if(nums[mid]>nums[j]){
              if(target<=nums[mid]&&target>=nums[i]){
                j=mid;
              }
              else{
                i=mid;
              }
            }
          }
        }
    }
};

int main()
{
    int a[]={2,4,1};
    vector<int> v(a,a+3);
    cout << (new Solution())->search(v,4) << endl;
    return 0;
}
