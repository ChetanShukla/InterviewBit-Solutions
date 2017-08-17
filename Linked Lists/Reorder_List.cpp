/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* head) 
{
    ListNode *slow_ptr, *fast_ptr,*prev;
    
    if(head == NULL || head->next == NULL || head->next->next == NULL)
                                                                    return head;
    
    slow_ptr = head;
    fast_ptr = head;
    prev = NULL;
    
    while(fast_ptr != NULL)
    {
        fast_ptr = fast_ptr->next;
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        
        if(fast_ptr != NULL)
                            fast_ptr = fast_ptr->next;
    }
    prev->next = NULL;
    ListNode *nxt, *h2;
    h2 = slow_ptr;
    
    prev = NULL;
    while(slow_ptr != NULL)
    {
        nxt = slow_ptr->next;
        slow_ptr->next = prev;
        prev = slow_ptr;
        slow_ptr = nxt;
    }
    h2 = prev;
    ListNode *h;
    
    h = NULL;
    slow_ptr = head;
    
    h = slow_ptr;
    
    while(slow_ptr != NULL && h2 != NULL)
    {
        slow_ptr = slow_ptr->next;
        h->next = h2;
        h = h2;
        h2 = h2->next;
        h->next = slow_ptr;
        h = slow_ptr;
    }
    
    return head;
}
