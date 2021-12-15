using namespace std;
#include<iostream>

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

 bool symmetry(treeNode* r1, treeNode* r2){
        if( !r1 && !r2) return true;
        if( !r1 || !r2) return false;
        return r1->data == r2->data && symmetry(r1->left,r2->right) && symmetry(r1->right,r2->left);
    }
    bool isSymmetric(treeNode* root) {
        if(!root) return true;
        else return symmetry(root->left,root->right);
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