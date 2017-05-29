#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x,ListNode * next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse1Group(ListNode* head){
      ListNode * pl=head;
      ListNode * next=head->next;
      head->next=NULL;
      while(next!=NULL){
        ListNode * temp=next->next;
        next->next=pl;
        pl=next;
        next=temp;
      }
      return pl;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c=0;
        ListNode * pl=head;
        ListNode * p=head;
        ListNode ** last=&head;
        while(p){
          c++;
          if(c==k){
            ListNode* temp=pl;
            pl=p->next;
            p->next=NULL;
            p=pl;
            *last=reverse1Group(temp);
            last=&temp->next;
            *last=pl;
            c=0;
          }
          else
            p=p->next;
        }
        return head;
    }
};

int main(){
  auto l1=new ListNode(1);
  auto l2=new ListNode(2,l1);
  auto l3=new ListNode(3,l2);
  auto l4=new ListNode(4,l3);
  auto l5=new ListNode(5,l4);
  auto head=(new Solution())->reverseKGroup(l5,3);
  //auto head=(new Solution())->reverse1Group(l5);
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }
  return 0;
}
