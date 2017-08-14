#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> v;
        ListNode* l=head;
        while(l){
          v.push_back(l);
          l=l->next;
        }
        int t=v.size()-n-1;
        if(t<0){
          head=head->next;
        }
        else{
          v[t]->next=v[t]->next->next;
        }
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
