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
        ListNode* revHead;
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

        void insertAtPostion( int pos, int val){
            ListNode *temp = this-> head;
            int i = 1;
            while(i < pos - 1) {
                temp = temp -> next;
                i++;
            }
            ListNode *tmp = new ListNode(val);
            tmp->next = temp->next;
            temp->next = tmp;

            this->length++;
        }
        void primitiveRemoveFromEnd ( int pos ){
            ListNode *temp = this->head;   
            int i = 1;
            ListNode *tmp = head;
            int Size = 0;
            while (tmp){
                tmp = tmp ->next;
                Size++;
            }
            
            if ( pos == Size){
                ListNode *toDelete = temp;
                this->head = temp->next;
                delete toDelete;
            }
            else{
                while ( i < Size - pos ){
                    temp = temp -> next;
                    i++;
                }
                ListNode *toDelete = temp->next;
                temp -> next = toDelete->next;

                delete toDelete;
                }
             

        }
        
        void removeFromEnd ( int pos ){
            ListNode *temp = this->head;
            int i = 1;
            if ( pos == this->length){
                ListNode *toDelete = temp;
                this->head = temp->next;
                delete toDelete;
            }
            else{
                while ( i < this->length - pos ){
                    temp = temp -> next;
                    i++;
                }
                ListNode *toDelete = temp->next;
                temp -> next = toDelete->next;

                delete toDelete;
                }
             this->length--;
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

        void reverseList (){
            ListNode *currNode = head;
            ListNode *prevNode = nullptr;
            ListNode *tmp;
            while (currNode){
                  tmp = currNode->next;
                  currNode->next = prevNode;
                  prevNode = currNode;
                  currNode = tmp;                              
                }
            head = prevNode;
        }

       

        ListNode* reverseListRecursive( ListNode* head){
           if(!head || !head->next) return head;
           ListNode* tmpNode = head->next;
           head->next = nullptr;
           revHead = reverseListRecursive(tmpNode);
           tmpNode->next = head;
           return revHead;
        }
  };
  
int main () {
    linkedList l1(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);
    l1.reverseList();
    l1.displayList();
    return 0;
}