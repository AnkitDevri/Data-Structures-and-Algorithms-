using namespace std;
#include<iostream>

class queueNode{
public: 
int data;
queueNode* next;

queueNode(int nodeData){
  this->data=nodeData;
  this->next=nullptr;
}
};
class queue
{
public:
queueNode *front,*rear;
queue(){
 this->front=this->rear=nullptr;
}
void push(int data){
 if(!this->front)
  this->front=this->rear=new queueNode(data);

else{
  this->rear->next=new queueNode(data);
  this->rear=this->rear->next;

}

}
void pop(){
 if(!this->front)
 cout<<endl<<"Underflow"<<endl;
 else{
   queueNode *temp=this->front;
   this->front=front->next;
   delete temp;
 }
}
void display(){
  if(!this->front)
 cout<<endl<<"Underflow"<<endl;
 else{
   queueNode* temp=this->front;
    while(temp){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
}
}
};

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
  treeNode* insert (treeNode* root,int data){
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

  void inorder(treeNode* root){
   if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }

  queue levelorder(treeNode* root){
    queue line;
    if(root)
     line.push(root->data);
    if(root->left){
     line.push(root->left->data); 
     levelorder(root->left);
    }
    if(root->right){
     line.push(root->right->data);
     levelorder(root->right);

    }
     return line;
  }

  void levelorderDisplay(queue a){
   a.display();
  }
};

int main(){
  tree b;
  int total,element;
  cin>>total;
  for(int i=0;i<total;i++){
  cin>>element;
  b.root=b.insert(b.root,element);
  }
  b.inorder(b.root);
  b.levelorderDisplay(b.levelorder(b.root));
   getchar();
  return 0;
}