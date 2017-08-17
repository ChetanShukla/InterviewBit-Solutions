/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int k) 
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode *cur, *nxt, *prev;
    
    cur = head;
    prev = NULL;    nxt = NULL;
    
    int ctr = 0;

    while(cur != NULL && ctr<k)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
        ctr++;
    }
    
    if(nxt != NULL)
                head->next = reverseList(nxt,k);
    
    head = prev;
    
    return head;
}
