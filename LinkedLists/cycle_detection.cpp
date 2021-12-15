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

        ListNode* detectCycle (ListNode* head){
            ListNode *fastPointer = head;
            ListNode *slowPointer = head;
            ListNode *temp = head;
        
            while(fastPointer != NULL && slowPointer != NULL && fastPointer->next != NULL){
                fastPointer = fastPointer->next->next;
                slowPointer = slowPointer->next;
                if(slowPointer == fastPointer) break;
            }
             if (fastPointer == NULL || slowPointer == NULL || fastPointer->next == NULL) return NULL;
        
            ListNode *pointOfCollision = slowPointer;
            
            while (temp != pointOfCollision){
                temp = temp->next;
                pointOfCollision = pointOfCollision->next;
            }
            return pointOfCollision;
        }
  };
  
int main () {
    linkedList l1(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.removeFromEnd(5);
    l1.removeFromEnd(3);
    l1.displayList();
    return 0;
}