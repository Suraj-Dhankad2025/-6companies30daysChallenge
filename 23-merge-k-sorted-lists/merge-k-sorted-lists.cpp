/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Compare
{
public:
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode *head = new ListNode();
        ListNode* temp = head;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(int i=0;i<lists.size();i++) {
            if(lists[i]!=NULL) {
                pq.push(lists[i]);
            }
        } 

        while(!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();

            temp->next = top;
            temp = temp->next;

            if(top->next!=NULL) {
                pq.push(top->next);
            }
        }

        return head->next;
    }
};