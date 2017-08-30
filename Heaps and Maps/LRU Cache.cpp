map<int, int> Hash;
int current = 0;
int lim = 0;

struct DLLnode
{
    int val;
    DLLnode *prev, *next;
    
    DLLnode(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

DLLnode *first, *LRU;

LRUCache::LRUCache(int capacity) 
{
    Hash.clear();
    current = 0;
    lim = capacity;
    first = NULL;
    LRU = NULL;
}

int LRUCache::get(int key) 
{
    if(current > 0)
    {
        auto it = Hash.find(key);
        
        if(it != Hash.end())
        {
            int value = it->first;
            int temp = it->second;
            
            DLLnode *curr, *prv, *nxt;
            curr = first;
            
            while(curr->val != value)
            {
                curr = curr->next;
            }
            prv = curr->prev;
            nxt = curr->next;
            if(prv != NULL)
            {
                prv->next = nxt;
                
                if(nxt != NULL)
                                nxt->prev = prv;
                else
                        LRU = prv;
                        
                curr->next = first;
                curr->prev = NULL;
                first->prev = curr;
                first = curr;
            }
            return temp;
        }
    }
    return -1;
}

void LRUCache::set(int key, int value) 
{
    if(Hash.find(key) == Hash.end())            // {key,value} not present
    {
        DLLnode *temp;
        temp = new DLLnode(key);
        Hash[key] = value;
        
        if(current != lim)                  // if capacity hasn't been reached
        {
            current++;
            
            if(current == 1)
            {
                LRU = temp;
                first = LRU;
            }
            else
            {
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
        }
        else                            // capacity reached
        {
            int del_val = LRU->val;
            
            auto it = Hash.find(del_val);
            Hash.erase(it);
        
            if(LRU->prev != NULL)
            {
                LRU = LRU->prev;
                LRU->next = NULL;
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
            else                // capacity ek ki hi hai!
            {
                LRU = temp;
                first = LRU;
            }
        }
    }
    else            // map mei hai already 
    {
        Hash[key] = value;
        DLLnode *curr, *prv, *nxt;
        curr = first;
        
        while(curr->val != key)
        {
            curr = curr->next;
        }
        prv = curr->prev;
        nxt = curr->next;
        
        if(prv != NULL)
        {
            prv->next = nxt;
            
            if(nxt != NULL)
                            nxt->prev = prv;
            else
                    LRU = prv;
                        
            curr->next = first;
            curr->prev = NULL;
            first->prev = curr;
            first = curr;
        }
    }
}
