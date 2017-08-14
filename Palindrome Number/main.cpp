#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
          return false;
        if(x==0){
          return true;
        }
        int rx=0;
        int tempx=x;
        while(tempx>0){
          rx=rx*10+tempx%10;
          tempx/=10;
        }
        return rx==x;
    }
};

int main()
{
    cout << (new Solution)->isPalindrome(121)<< endl;
    return 0;
}
