

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0&&l1->next==NULL)
            return l2;
        else if(l2->val==0&&l2->next==NULL)
            return l1;
        ListNode * first;
        ListNode ** pL=&first;
        int jw=0;
        while(l1!=NULL&&l2!=NULL){
            int res=l1->val+l2->val+jw;
            if(res>=10){
                jw=1;
                res-=10;
            }
            else{
                jw=0;
            }
            *pL=new ListNode(res);
            pL=&((*pL)->next);
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL){
            l1=l2;
        }
        while(l1!=NULL){
            int res=l1->val+jw;
            if(res>=10){
                jw=1;
                res-=10;
            }
            else{
                jw=0;
            }
            *pL=new ListNode(res);
            pL=&((*pL)->next);
            l1=l1->next;
        }
        if(jw){
            *pL=new ListNode(1);
        }
        return first;
    }
};
