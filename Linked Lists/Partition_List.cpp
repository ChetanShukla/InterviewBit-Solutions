/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* head, int x) 
{
    if(head == NULL || head->next == NULL)
                                            return head;
    
    ListNode *h1, *h2, *t1, *t2, *itr;
    
    h1 = NULL;  h2 = NULL;  t1 = NULL;  t2 = NULL;
    itr = head;
    
    while(itr != NULL)
    {
        if(itr->val < x)
        {
            if(h1 == NULL)
            {
                h1 = itr;
                t1 = itr;
            }
            else
            {
                t1->next = itr;
                t1 = itr;
            }
        }
        else
        {
            if(h2 == NULL)
            {
                h2 = itr;
                t2 = itr;
            }
            else
            {
                t2->next = itr;
                t2 = itr;
            }
        }
        itr = itr->next;
    }
    if(h1 == NULL)
                    return h2;
                    
    if(h2 == NULL)
                    return h1;
    
    t1->next = h2;
    t2->next = NULL;
    
    return h1;
}
