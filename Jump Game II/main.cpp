#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int m=0,n=0;
        int far;
        if(nums.size()==1){
          return 0;
        }
        while(1){
          step++;
          far=0;
          for(int i=m;i<=n;i++){
            far=max(far,i+nums[i]);
          }
          m=n+1;
          n=far;
          if(n>=nums.size()-1){
            return step;
          }
        }

    }
};

int main()
{
  int a[5]={2,2,1,1,4};
  vector<int> v(a,a+5);
    cout << (new Solution())->jump(v) << endl;
    return 0;
}
