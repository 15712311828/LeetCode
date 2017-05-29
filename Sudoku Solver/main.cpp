#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
  vector<vector<set<char> > > possibleChar;
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
          vector<set<char> > v;
          for(int j=0;j<9;j++){
            set<char> s;
            for(char c='1';c<='9';c++){
              s.insert(c);
            }
            v.push_back(s);
          }
          possibleChar.push_back(v);
        }
        int count=0;
        for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
            if(board[i][j]=='.')
              count++;
            else{
              for(int k=0;k<9;k++){
                possibleChar[k][j].erase(board[i][j]);
              }
              for(int k=0;k<9;k++){
                possibleChar[i][k].erase(board[i][j]);
              }
            }
          }
        }
        while(count){
          for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
              if(board[i][j]=='.'&&possibleChar[i][j].size()==1){
                board[i][j]=*possibleChar[i][j].begin();
                for(int k=0;k<9;k++){
                  possibleChar[k][j].erase(board[i][j]);
                }
                for(int k=0;k<9;k++){
                  possibleChar[i][k].erase(board[i][j]);
                }
                count--;
              }
            }
          }
        }

    }
};

int main(){
  vector<vector<char>> board;
  string s[]={"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
  for(int i=0;i<9;i++){
    vector<char> v(s[i].c_str(),s[i].c_str()+9);
    board.push_back(v);
  }
  (new Solution())->solveSudoku(board);
  return 0;
}
