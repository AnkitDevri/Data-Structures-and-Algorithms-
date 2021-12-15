#include<iostream>
#include<queue>
using namespace std;
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
    treeNode* root;
    treeNode* last;
    tree(){
        this->root=nullptr;
    }
    treeNode* insert (treeNode* root,int data){
        if(!root){
          root=new treeNode(data);
          return root;
        }
     std::queue<treeNode*> line;
        line.push(root);
        while(!line.empty()){
            treeNode* temp= line.front();
            line.pop();
            if(temp->left)
            line.push(temp->left);
            else{
                temp->left=new treeNode(data);
                return root;
            }
            if(temp->right){
             line.push(temp->right);
            }
            else{
                temp->right=new treeNode(data);
                return root;
            }
        }
        return root;
    }
    void deleteLastNode(treeNode* root,treeNode* lastNode){
       queue<treeNode*> line;
       line.push(root);
       treeNode* temp;
       while(!line.empty()){
           temp=line.front();
           line.pop();
           if(temp==lastNode){
               temp=nullptr;
               delete lastNode;
           }
           if(temp->right)
              line.push(temp->right);
               
           
          if(temp->left)
               line.push(temp->right);
          }
       }
    
    void remove(treeNode* root,int data){
     if(!root)
     cout<<"empty tree"<<endl;
     treeNode *keyNode,*lastNode;
     queue<treeNode*>line;
     line.push(root);
     if(root->data==data){
         keyNode=root;
     }
     while(!line.empty()){
         treeNode *temp=line.front();
         line.pop();
         if(temp->left)
          line.push(temp->left);
         
         if(temp->right)
            line.push(temp->right);
         
         if(temp->data==data)
         keyNode=temp; 
         if(line.empty())
         lastNode=temp;
     }
       keyNode->data=lastNode->data;
       deleteLastNode(root,lastNode);
    }
    void inorder(treeNode* root){
        if(!root)
         return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(treeNode* root){
        if(!root)
        return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(treeNode* root){
        if(!root)
        return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};
int main(){
  tree host;
  int total,element;
  cin>> total;
  for(int i=0;i<total;i++){
     cin>>element;
     host.root=host.insert(host.root,element);
  }
  host.inorder(host.root);
  cin>>element;
  host.remove(host.root,element);
  host.inorder(host.root);
  cout<<endl;
  host.preorder(host.root);
  host.postorder(host.root);
  
return 0;
}