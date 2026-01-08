ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    int count = 0;
    while(temp!=nullptr){
        temp = temp->next;
        count++;
    }
    temp = head;
    if(count==n) return head->next;
    n = count-n;
    while(temp!=nullptr && count>=2){
        if(n<=1 && temp->next!=nullptr){
            ListNode* next = temp->next->next;
            temp->next = next;
            return head;
        }
        temp = temp->next;
        n--;
    }
    return head;
}