#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        for(auto n:nums){
          if(n==i){
            i++;
          }
        }
        return i;
    }
};

int main(){
  int i[]={2,-5,4,1};
  vector<int> v(i,i+4);
  cout<<(new Solution())->firstMissingPositive(v);
  return 0;
}
