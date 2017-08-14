#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0&&nums[i]>=nums[i+1]){
          i--;
        }
        if(i<0){
          vector<int>(nums.rbegin(),nums.rend()).swap(nums);
        }
        else{
          int j=i+1;
          while(j<nums.size()&&nums[j]>nums[i])
            j++;
          swap(nums[i],nums[j-1]);
          sort(nums.begin()+i+1,nums.end());
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
