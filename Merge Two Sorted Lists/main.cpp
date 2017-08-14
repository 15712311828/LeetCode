#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode ** pl=&head;
        while(l1!=NULL||l2!=NULL){
          if(l1==NULL){
            *pl=l2;
            pl=&(*pl)->next;
            l2=l2->next;
          }
          else if(l2==NULL){
            *pl=l1;
            pl=&(*pl)->next;
            l1=l1->next;
          }
          else if(l1->val<l2->val){
            *pl=l1;
            pl=&(*pl)->next;
            l1=l1->next;
          }
          else{
            *pl=l2;
            pl=&(*pl)->next;
            l2=l2->next;
          }
        }
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
