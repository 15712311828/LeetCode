#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int res=0;
        while(i<j){
          int minh=min(height[i],height[j]);
          res=max(res,minh*(j-i));
          while(height[i]<=minh)i++;
          while(height[j]<=minh)j--;
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
