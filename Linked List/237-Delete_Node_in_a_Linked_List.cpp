void deleteNode(ListNode* node) {
    int temp1 = 0;
    int temp2 = 0;
    ListNode* temp3 = node;
    int count = 0;
    while(node->next != NULL){
    temp1 = node->val;
    temp2 = node->next->val;
    node->next->val = temp1;
    node->val = temp2;
    node = node->next;
    if(count>=1){
        temp3 = temp3->next;
    }
    count++;
    }
    temp3->next = NULL;
}

//In this question these is no head pointer given so just swap the values at each node and then make the last but one node's pointer as NULL
//Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
