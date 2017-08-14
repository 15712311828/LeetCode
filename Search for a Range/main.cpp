#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(i==nums.size()||nums[i]!=target){
          return vector<int>(2,-1);
        }
        vector<int> v;
        int j=i-1;
        while(j>=0&&nums[j]==target)j--;
        int k=i+1;
        while(k<nums.size()&&nums[k]==target)k++;
        v.push_back(j+1);
        v.push_back(k-1);
        return v;
    }
};

int main()
{
  int a[]={1,4,4,6,6};
  vector<int> t(a,a+5);
  auto v=(new Solution())->searchRange(t,4);
    cout << "Hello world!" << endl;
    return 0;
}
