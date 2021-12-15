using namespace std;
#include <bits/stdc++.h>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class linkedList {
        ListNode* head;
        int length;
        public:
        linkedList( int val){
            this-> head = new ListNode(val);
            this-> length = 1;
        } 
        void insertAtEnd( int val ){
            ListNode *temp = this-> head;
            while ( temp->next ){
                temp = temp->next;
            }
            ListNode *tmp = new ListNode(val);
            temp-> next = tmp;

            this->length++;
        }


        void displayList (){
            ListNode *temp = this->head;
            while (temp){
                cout<< temp->val<<" ";
                temp = temp->next;
            }
        }

        int size () {
            return this->length;
        }
        int calculateSize(ListNode *head){
            ListNode *tmp = head;
            int Size = 0;
            while (tmp){
                tmp = tmp ->next;
                Size++;
            }
            return Size;
        }
        ListNode* getHead(){
            return this->head;
        }
        vector<ListNode*> reverseListChunks (ListNode* head, int k){
            ListNode *currNode = head;
            ListNode *prevNode = nullptr;
            ListNode *tmp;
            int i = 0;
            while ( i < k){
                  tmp = currNode->next;
                  currNode->next = prevNode;
                  prevNode = currNode;
                  currNode = tmp;  
                  i++;;                            
                }
            return {prevNode,currNode};
        }

        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* sizeChecker = head;
            int size = 0;
            while(sizeChecker && size < k){
                sizeChecker = sizeChecker->next;
                size++;
            }
            if(size < k) return head;
            vector<ListNode*> headNtail = reverseListChunks(head,k);
            head->next = reverseKGroup(headNtail[1],k);
            return headNtail[0];

        }
  };
  
int main () {
    linkedList l1(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.displayList();
    return 0;
}