//leetcode problem number 328 oddEven Linked List
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL)
    {
        return NULL;
    }
    struct ListNode *odd=head;
    struct ListNode *even=head->next;
    struct ListNode *evenhead=even;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;

    }
    odd->next=evenhead;
    return head;
}
//leetcode problem number 23 Merge K Sorted List
struct ListNode* merge(struct ListNode* a,struct ListNode* b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->val<b->val)
    {
        a->next=merge(a->next,b);
        return a;
    }
    else
    {
        b->next=merge(a,b->next);
        return b;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0)
    {
        return NULL;
    }
    struct ListNode *ans=lists[0];
    for(int i=1;i<listsSize;i++)
    {
        ans=merge(ans,lists[i]);
    }
    return ans;
}
//leetcode problem number 873 middle of Linked List
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}