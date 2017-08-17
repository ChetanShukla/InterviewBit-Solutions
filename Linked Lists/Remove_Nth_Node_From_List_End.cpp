/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int k) 
{
    ListNode* temp = head;
    
    if(head == NULL)
                    return head;
    int n=0;
    
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    temp = head;
    //cout<<n<<endl;
    if(k>=n)
    {
        head = temp->next;
        free(temp);
        //cout<<"ghuss ke aaya kya!\n";
        return head;
    }
    
    ListNode* fst = head;
    
    int ctr = 0;
    while(ctr<k && fst!=NULL)
    {
        ctr++;
        fst = fst->next;
    }
    
    ListNode* prev = NULL;
    temp = head;
    
    while(fst!=NULL)
    {
        prev = temp;
        temp = temp->next;
        fst = fst->next;
    }
    
    prev->next = temp->next;
    free(temp);
    
    return head;
    
}
