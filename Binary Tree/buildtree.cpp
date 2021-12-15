#include<iostream>
#include<conio.h>
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
  treeNode *root;
  tree(){
    this->root=nullptr;
  }

 void inorder(treeNode* root){
     if(!root)
     return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
     
 }
};

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++)
    if(inorder[i]==curr)
    return i;
 return -1;
}

treeNode* buildTree(int preorder[], int inorder[], int start, int end,int size) {

static int idx = 0*size;
if(start>end)
return nullptr;

int curr = preorder[idx];
idx++;
treeNode* temp = new treeNode(curr);

if(start == end) 
return temp;

int pos = search(inorder, start, end, curr);
temp->left = buildTree(preorder, inorder, start, pos-1,size);
temp->right = buildTree(preorder, inorder, pos+1, end,size);

return temp;
}

int main(){
    int size;
    cin>>size;
    int pre[size],in[size];
    for(int i=0;i<size;i++)
    cin>>pre[i];
    for(int i=0;i<size;i++)
    cin>>in[i];
    tree low;
    low.root=buildTree(pre,in,0,size-1,size);
    low.inorder(low.root);
    getchar();
    return 0;
}