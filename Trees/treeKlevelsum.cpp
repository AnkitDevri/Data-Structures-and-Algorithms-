using namespace std;
#include<iostream>
#include<queue>
#include<vector>
#include<numeric>
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
 treeNode* insert(treeNode* root,int data){
     if(!root)
      return new treeNode(data);
     else
     {
         if(root->data>=data)
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
 int levelcount(treeNode* root,int got,int size){
     queue<treeNode*> line;
     line.push(root);
     line.push(nullptr);

     treeNode* temp;
     vector<int>count(size,0);
     int i=0;

     while(!line.empty()){
         temp=line.front();
         line.pop();

         if(!temp)
          i++;

         if(temp){

         if(temp->left)
          line.push(temp->left);
         if(temp->right)
          line.push(temp->right);

         count[i]=count[i]+temp->data;
         }
         
         else if(!line.empty())
         line.push(nullptr);
         
        
     }
     cout<<endl<<count[got-1];
    return accumulate(count.begin(),count.end(),0);
 }
};
int main(){
    tree yo;
    int total,element;
    cin>>total;
    for(int i=0;i<total;i++){
    cin>>element;
    yo.root=yo.insert(yo.root,element);
    }
    yo.inorder(yo.root);
    int level,answer;
    cin>>level>>answer;
    answer=yo.levelcount(yo.root,level,answer);
    cout<<endl<<answer;
    
    return 0;
}