using namespace std;
#include<iostream>
#include<queue>
class treeNode{
    public:
    int data;
    treeNode *left,*right;
    treeNode(int nodeData){
        this->data=nodeData;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class tree{
public:
 treeNode *root;
  tree(){
      this->root=nullptr;
  }
 
 treeNode* insert(treeNode *root,int data){
     if(!root){
      root=new treeNode(data);
      return root;
     }

     queue<treeNode*> line;
     line.push(root);
     while(!line.empty()){
     treeNode* temp=line.front();
     line.pop();

     if(temp->left)
      line.push(temp->left);
     else{
      temp->left=new treeNode(data);
      return root;
      }
    
     if(temp->right)
      line.push(temp->right);
     else{
      temp->right=new treeNode(data);
      return root;
     }
     }
     return root;
 }

 void inorder(treeNode* root){
     treeNode* temp=root;
    if(!temp)
      return;
     inorder(temp->left);
     cout<<temp->data<<" ";
     inorder(temp->right);
 }
};
int main(){
    tree t;
    int total,element;
    cin>>total;
    for(int i=0;i<total;i++){
    cin>>element;
    t.root=t.insert(t.root,element);
    }
    t.inorder(t.root);
    getchar();
    return 0;
}