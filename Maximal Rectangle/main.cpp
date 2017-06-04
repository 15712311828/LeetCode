#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int currentMax;
public:
    int divideFind(vector<vector<char>>& matrix,int starti,int startj,int endi,int endj){
      if((endi-starti)*(endj-startj)<=currentMax)
        return 0;
      for(int i=starti;i<endi;i++){
        for(int j=startj;j<endj;j++){
          if(matrix[i][j]=='0'){
            int res=0;
            res=max(res,divideFind(matrix,starti,startj,i,endj));
            res=max(res,divideFind(matrix,starti,startj,endi,j));
            res=max(res,divideFind(matrix,i+1,startj,endi,endj));
            res=max(res,divideFind(matrix,starti,j+1,endi,endj));
            return res;
          }
        }
      }
      currentMax=(endi-starti)*(endj-startj);
      return (endi-starti)*(endj-startj);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      currentMax=0;
      if(matrix.empty()){
        return 0;
      }
        return divideFind(matrix,0,0,matrix.size(),matrix[0].size());
    }
};

int main()
{
    vector<vector<char>> matrix;
    vector<char> v(1,'1');
    matrix.push_back(v);
    cout <<(new Solution())->maximalRectangle(matrix)<< endl;
    return 0;
}
