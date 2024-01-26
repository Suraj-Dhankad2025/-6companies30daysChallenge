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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode* newHead = NULL;
        ListNode* tail = NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
        
        for(auto i:lists){
            if(i!=NULL)
            pq.push({i->val,i});
        }
        while(!pq.empty()){
            ListNode* temp = pq.top().second;
            pq.pop();
            ListNode* node = NULL;
            if(temp!=NULL){
                node = new ListNode(temp->val);
                temp = temp->next;
                if(temp!=NULL)pq.push({temp->val, temp});
            }
            if(newHead==NULL && node!=NULL){
                newHead = node;
                tail = node;
            }
            else{
                if(node!=NULL){
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
        return newHead;
    }
};