#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> r(height.size(),0);
        vector<int> l(height.size(),0);
        for(int i=0;i<height.size();i++){
          for(int j=0;j<=i;j++){
            if(l[j]<height[i])
              l[j]=height[i];
          }
          for(int j=i;j<height.size();j++){
            if(r[j]<height[i])
              r[j]=height[i];
          }
        }
        int res=0;
        for(int i=0;i<height.size();i++){
          res+=min(l[i],r[i])-height[i];
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
