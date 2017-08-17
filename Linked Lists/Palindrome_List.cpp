int Solution::lPalin(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
                                        return true;
    
    ListNode* fst = head;
    ListNode* slow = head;
    ListNode* temp = head;
    ListNode* prev = head;
    
    
    while(fst && fst->next)
    {
        prev = slow;
        slow = slow->next;
        fst = fst->next;
        fst = fst->next;
    }
    prev->next = NULL;
    
    if(fst)
    {
        prev = slow;
    }
    temp = slow;
    while(temp)
    {
        ListNode* Nxt = temp->next;
        
        temp->next = prev;
        prev = temp;
        temp = Nxt;
    }
    temp = prev;
    slow = head;
    while(slow && temp)
    {
        //cout<<slow-> val<<" "<<temp->val<<endl;
        if(slow-> val != temp->val)
                                    return false;
    
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}
