class Solution {
public:
    ListNode *reverse(ListNode *head){
        ListNode *prev =NULL;
        ListNode *curr = head, *nextnode = head;
        while(curr!=NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = head; 
        stack<int>s;
        if(head ==NULL || head->next==NULL) return head;
        s.push(temp->val); temp = temp->next;
        while(!s.empty() && temp!=NULL){
            if(s.top() >= temp->val){
                s.push(temp->val); temp = temp->next;
            }
            else{
                while(!s.empty() && s.top() < temp->val){
                    s.pop();
                }
                s.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *nodes = new ListNode(0);
        temp = nodes;
        while(!s.empty()){
            ListNode *newnode = new ListNode(s.top());
            temp->next = newnode; 
            temp = newnode;
            s.pop();
        }
        
        head = nodes->next;
        head = reverse(head);
        return head;
    }
};
