#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        bool eflag=false;
        for(;i<s.length();i++){
          if(s[i]>='0'&&s[i]<='9'){
            if(i==s.length()-1)
              return true;
          }
          else if(s[i]=='.'){
            static bool flag=false;
            if(flag||(i!=0&&s[i-1]=='e')||eflag)
              return false;
            flag=true;
          }
          else if(s[i]=='e'){
            static bool flag=false;
            if(flag||i==0||s[i-1]=='-'||s[i-1]=='.'||i==s.length()-1)
              return false;
            eflag=flag=true;
          }
          else if(s[i]=='-'){
            if(i==0||s[i-1]=='e');
            else
              return false;
          }
          else if(s[i]==' '){
            if(i==0){
              while(s[i]==' '){
                i++;
                if(i==s.length())
                  return false;
              }
              i--;
            }
            else{
              if(s[i-1]>='0'&&s[i-1]<='9'){
                while(s[i]==' '){
                  i++;
                  if(i==s.length())
                  return true;
                }
                return false;
              }
              return false;
            }
          }
          else{
            return false;
          }
        }
        return false;
    }
};
int main()
{
    if((new Solution())->isNumber(".1")){
      cout<<"Y";
    }
    else{
      cout<<"n";
    }
    return 0;
}
