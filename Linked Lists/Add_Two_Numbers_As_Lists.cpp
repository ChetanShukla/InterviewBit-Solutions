/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* h1, ListNode* h2) 
{
    ListNode *head, *tail;
    
    if(h1 == NULL && h2 == NULL)
                                return NULL;
    
    if(h1 == NULL)
                    return h2;
                    
    if(h2 == NULL)
                    return h1;
                    
    int dig,carry = 0;
    
    head = tail = NULL;
    
    while(h1 != NULL && h2 != NULL)
    {
        //cout<<h1->val<<" "<<h2->val<<endl;
        dig = h1->val + h2->val + carry;
        
        carry = dig/10;
        dig = dig%10;
        
        if(head==NULL)
        {
            head = new ListNode(dig);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(dig);
            tail = tail->next;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if(h1 != NULL)
    {
        while(h1 != NULL)
        {
            dig = h1->val + carry;
            //cout<<h1->val<<endl;
            
            carry = dig/10;
            dig = dig%10;
            
            tail->next = new ListNode(dig);
            tail = tail->next;
            h1 = h1->next;
        }
    }
    if(h2 != NULL)
    {
        while(h2 != NULL)
        {
            dig = h2->val + carry;
            //cout<<h2->val<<endl;
            
            carry = dig/10;
            dig = dig%10;
            
            tail->next = new ListNode(dig);
            tail = tail->next;
            h2 = h2->next;
        }
    }
    if(carry)
    {
        tail->next = new ListNode(carry);
        tail = tail->next;
    }
    return head;
}
