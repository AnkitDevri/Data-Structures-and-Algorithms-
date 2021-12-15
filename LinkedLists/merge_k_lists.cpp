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

        ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
            if( l1 && !l2) return l1;
            else if (l2 && !l1) return l2;
            else if (!l1 && !l2) return nullptr;

            ListNode *head;
            ListNode *tail;
            ListNode *h1 = l1;
            ListNode *h2 = l2;

            if( h1->val <= h2->val ){
                head = l1; tail = l1; 
                h1 = h1->next;
            }
            else{
                head = l2; tail =l2;
                h2 = h2->next;
            }

            while ( h1 && h2){
                if( h1->val <= h2->val){
                    tail->next = h1;
                    h1 = h1->next;
                }
                else {
                    tail->next = h2;
                    h2 = h2->next;
                }
                tail = tail->next;
            }

            if(h1) tail->next = h1;
            else tail->next = h2;

            return head;
        }
        
        ListNode* mergeTwoListsRecursive(ListNode *l1, ListNode *l2){
            if( l1 && !l2) return l1;
            else if (l2 && !l1) return l2;
            else if (!l1 && !l2) return nullptr;

            ListNode *detached;
            if( l1->val <= l2->val) {
                detached = l1;
                ListNode *temp = l1->next;
                l1->next = nullptr;
                l1 = temp;
            }
            else{
                detached = l2;
                ListNode *temp = l2->next;
                l2->next = nullptr;
                l2 = temp;
            }
            ListNode *toAttach = mergeTwoListsRecursive(l1,l2);
            detached->next = toAttach;
            return detached;
            
        }
         ListNode* mergeK(vector <ListNode*>& lists, int start ,int end){
             if(start == end ) return lists[start];
             int mid = (start + end)/2;
             ListNode *head1 = mergeK(lists, start, mid);
             ListNode *head2 = mergeK(lists, mid+1, end);

             return mergeTwoListsRecursive(head1,head2);
         }
         ListNode* mergeKLists(vector<ListNode*>& lists) {
             if(lists.empty()) return nullptr;
             return mergeK(lists,0,lists.size()-1);
        
        }
        ListNode* gethead(){
            return this->head;
        }

        void sethead(ListNode *head){
            this->head = head;
        }
  };
  
int main () {
    linkedList l1(1);
    linkedList l2(2);
    ListNode* temp = l1.mergeTwoLists(l2.gethead(),l1.gethead());
    l1.sethead(temp);
    l1.displayList();
    return 0;
}