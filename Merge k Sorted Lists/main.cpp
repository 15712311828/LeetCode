#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class ListNode {
public:
 int val;
 ListNode *next;
 ListNode(int x,ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator() ( ListNode * a, ListNode * b ){
        return a->val>b->val;
        }
};

class Solution {
public:

    ListNode * mergeKLists(vector<ListNode*> & lists) {

        priority_queue<ListNode *,vector<ListNode *>,cmp> q;
        for(auto listNode:lists){
          if(listNode)
            q.push(listNode);
        }
        if(q.empty())
          return NULL;
        ListNode * first=NULL;
        ListNode * last=NULL;
        first=last=q.top();
        q.pop();
        if(last->next!=NULL){
          q.push(last->next);
        }
        while(!q.empty()){
          last->next=q.top();
          last=q.top();
          q.pop();
          if(last->next!=NULL){
            q.push(last->next);
          }
        }
        return first;

    }
};

int main(){
  vector<ListNode*> lists;
  auto l1=new ListNode(5,NULL);auto l2=new ListNode(3,l1);
  auto l3=new ListNode(4,NULL);
  lists.push_back(l2);
  lists.push_back(l3);
  auto s=new Solution();
  ListNode * ans=s->mergeKLists(lists);
  while(ans!=NULL){
    cout<<ans->val<<" ";
    ans=ans->next;
  }
  return 0;
}
