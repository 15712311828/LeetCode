#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto pl=&head;
        while((*pl)&&(*pl)->next){
          ListNode* temp=(*pl)->next;
          (*pl)->next=(*pl)->next->next;
          temp->next=(*pl);
          (*pl)=temp;
          pl=&(temp->next->next);
        }
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
