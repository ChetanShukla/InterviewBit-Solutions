/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
                    return head;
    
    ListNode *fast_ptr, *slow_ptr;
    
    fast_ptr = head;
    slow_ptr = head;
    
    while(fast_ptr != NULL)
    {
        fast_ptr = fast_ptr->next;
        if(fast_ptr != NULL && fast_ptr->next != NULL) 
                                fast_ptr = fast_ptr->next;
        
        slow_ptr = slow_ptr -> next;
        
        if(slow_ptr == fast_ptr)
                                break;
        //cout<<slow_ptr->val<<" "<<fast_ptr->val<<endl;
        
    }
    
    if(fast_ptr == NULL)
    {
        //cout<<"NULL ho gya\n";
        return NULL;
    }                    
    fast_ptr = head;
    
    while(slow_ptr != fast_ptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
}
