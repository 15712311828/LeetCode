#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        for(int i=0;i<heights.size();i++){
          if(i==heights.size()-1||heights[i]>heights[i+1]){
            int h=heights[i];
            for(int j=i;j>=0;j--){
              if(heights[j]>=h&&j!=0);
              else if(heights[j]>=h&&j==0){
                res=max(res,h*(i-j+1));
              }
              else if(j==0){
                res=max(res,h*(i-j));
                h=heights[0];
                res=max(res,h*(i-j+1));
              }
              else {
                res=max(res,h*(i-j));
                h=heights[j];
                if(i!=heights.size()-1&&h<=heights[i+1])
                  break;
              }
            }
          }
        }
        return res;
    }
};

int main()
{
    int a[]={2,3};
    vector<int> v(a,a+2);
    cout << (new Solution())->largestRectangleArea(v) << endl;
    return 0;
}
