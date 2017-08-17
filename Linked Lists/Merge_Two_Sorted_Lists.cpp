/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* head1, ListNode* head2) 
{
    if(head1 == NULL && head2 == NULL)
                                    return NULL;
    if(head1 == NULL)
                        return head2;
    if(head2 == NULL)
                        return head1;
                        
    ListNode *t1, *t2, *head, *tail;
    
    t1 = head1;  t2 = head2;
    
    if(head1->val < head2->val)
    {
        head = head1;
        t1 = head1->next;
    }
    else
    {
        head = head2;
        t2 = head2->next;
    }
    tail = head;
    
    while(t1!=NULL && t2!=NULL)
    {
        ListNode *temp;
        //cout<<t1->val<<" "<<t2->val<<endl;
        if(t1->val < t2->val)
        {
            tail->next = t1;
            tail = t1;
            t1 = t1->next;
        }
        else
        {
            tail->next = t2;
            tail = t2;
            t2 = t2->next;
        }
    }
    while(t1 != NULL)
    {
        tail->next = t1;
        tail = t1;
        t1 = t1->next;
    }
    while(t2 != NULL)
    {
        tail->next = t2;
        tail = t2;
        t2 = t2->next;
    }
    return head;
}
