#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        vector<int> res;
        for(auto n:nums){
          if(!s.count(n)){
            s.insert(n);
            res.push_back(n);
          }
        }
        nums.swap(res);
        return nums.size();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
