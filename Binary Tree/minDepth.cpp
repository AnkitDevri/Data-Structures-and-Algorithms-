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

   int minDepth1(treeNode* root){
         if(!root) return INT_MAX;
         if(!root->left && !root->right) return 1;
         int left =  minDepth1(root->left);
         int right = minDepth1(root->right);
        
         int Min = min(left,right);
         
      return 1 + Min;
    }
    int minDepth(treeNode* root) {
        if(!root) return 0;
        else return minDepth1(root);
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