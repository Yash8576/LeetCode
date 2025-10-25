ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    ListNode* prev = new ListNode();
    int first = 1;
    while(l1 != nullptr && l2 != nullptr){
        ListNode* curr = new ListNode();
        int current_value = l1->val + l2->val;
        curr->val = current_value;
        if(first == 1){
            ans = curr;
            prev = curr;
        }
        else{
            prev->next = curr;
            prev = prev->next;
        }
        l1 = l1->next;
        l2 = l2->next;
        first++;
    }
    while(l1 != nullptr){
        ListNode* curr = new ListNode();
        curr->val = l1->val;
        first++;
        prev->next = curr;
        prev = prev->next;
        l1 = l1->next;
    }
    while(l2!=nullptr){
        ListNode* curr = new ListNode();
        curr->val = l2->val;
        first++;
        prev->next = curr;
        prev = prev->next;
        l2 = l2->next;
    }
    ListNode* temp = ans;
    while(temp!=nullptr){
        if(temp->val>=10){
            temp->val = temp->val-10;
            if(temp->next == nullptr){
                ListNode* temp1 = new ListNode();
                temp1->val = 1;
                temp->next = temp1;
            }
            else {
                temp->next->val++;
            }
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
    return ans;
}
