#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(auto c:s){
          if(c=='('||c=='['||c=='{')
              sc.push(c);
          else{
            if(!sc.empty()&&(c==')'&&sc.top()=='('||c==']'&&sc.top()=='['||c=='}'&&sc.top()=='{')){
              sc.pop();
            }
            else{
              return false;
            }
          }
        }
        return sc.size()==0;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
