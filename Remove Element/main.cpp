#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> v;
        for(auto i:nums){
          if(i!=val)
            v.push_back(i);
        }
        nums.swap(v);
        return nums.size();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
