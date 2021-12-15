using namespace std;
#include<bits/stdc++.h>

class treeNode{
    public:
    int data;
    treeNode *left,*right;
    treeNode(int Nodedata){
        this->data=Nodedata;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class tree{
 public:
 treeNode* root;
 tree(){
     this->root=nullptr;
 }

 treeNode* insert(treeNode* root,int data){
     if(!root)
      return new treeNode(data);

    else{
        if(root->data>data)
        root->left=insert(root->left,data);

        else
        root->right=insert(root->right,data);
    }
    return root;
 }

int totalNodes(treeNode* root){
    if(!root)
    return 0;

    return totalNodes(root->left)+totalNodes(root->right)+1;
} 

int totalSum(treeNode* root){
    if(!root)
    return 0;
 return totalSum(root->left)+totalSum(root->right)+root->data;
}

 void Inorder(treeNode* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

   pair<treeNode*,treeNode*> convertDoublyLinkedList1(treeNode* root){
       if(!root) return make_pair(nullptr,nullptr);
       treeNode* head = root;
       treeNode* tail = root;

       if(root->left) {
           pair<treeNode*,treeNode*> leftSubTree = convertDoublyLinkedList1(root->left);
           root->left = leftSubTree.second;
           leftSubTree.second->right = root;
           head = leftSubTree.first;
       }
       if(root->right){
           pair<treeNode*,treeNode*> rightSubTree = convertDoublyLinkedList1(root->right);
           root->right = rightSubTree.first;
           rightSubTree.first->left = root;
           tail = rightSubTree.second;
       }

       return make_pair(head,tail);

   }

   treeNode* convertDoublyLinkedList(treeNode* root){
       pair<treeNode*,treeNode*> answer = convertDoublyLinkedList1(root);
       return answer.first;
   }
   
};
int main(){
    tree binary;
    int total,element;
    cin>>total;
    for(int i=0;i<total;i++){
        cin>>element;
        binary.root=binary.insert(binary.root,element);
    }
    binary.Inorder(binary.root);
    cout<<endl<<"Total Nodes: "<<binary.totalNodes(binary.root);
    cout<<endl<<"Total sum of Nodes: "<<binary.totalSum(binary.root);
    getchar();
    return 0;
}