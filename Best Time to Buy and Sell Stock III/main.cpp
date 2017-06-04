#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
          return 0;
        }
        int notbuy=0;
        int buy1=-prices[0];
        int sell1=-12345;
        int buy2=-12345;
        int sell2=-12345;
        for(int i=1;i<prices.size();i++){
          sell2=max(sell2,buy2+prices[i]);
          buy2=max(buy2,sell1-prices[i]);
          sell1=max(sell1,buy1+prices[i]);
          buy1=max(buy1,notbuy-prices[i]);
        }
        int res=max(sell2,sell1);
        res=max(res,0);
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
