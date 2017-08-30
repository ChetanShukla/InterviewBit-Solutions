stack<int> MinSt;
stack<int> St;
MinStack::MinStack() 
{
    while(!St.empty())
                            St.pop();
    while(!MinSt.empty())
                            MinSt.pop();
}
void MinStack::push(int x) 
{
    St.push(x);
    if(MinSt.empty())
                    MinSt.push(x);
    else if(x < MinSt.top())
                    MinSt.push(x);
}
void MinStack::pop() 
{
    if(St.empty())
                return;
    if(St.top() == MinSt.top())
                            MinSt.pop();
    St.pop();
}
int MinStack::top() 
{
    if(St.empty())
                    return -1;
    return St.top();
}
int MinStack::getMin() 
{
    if(MinSt.empty())
                    return -1;
    return MinSt.top();
}

