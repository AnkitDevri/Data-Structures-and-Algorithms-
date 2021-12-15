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
    treeNode* insert(treeNode* root,int data){
        if(!root)
         return new treeNode(data);

        if(root->data>data){
         root->left=insert(root->left,data);
         
        }
         else{
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
    void preorder(treeNode* root){
        if(!root)
        return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(treeNode* root){
      if(!root){
        return;
      }
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
    }
    void levelorder(treeNode* root){
        queue<treeNode*>line;
        line.push(root);
        treeNode* temp;
        while(!line.empty()){
            temp=line.front();
            line.pop();
            if(temp)
              cout<<temp->data<<" ";
            if(temp->left)
              line.push(temp->left);
            if(temp->right)
              line.push(temp->right);
        }
    }
     int getHeight(treeNode *root){
       if(!root)
       return 0;
       int left=getHeight(root->left);
       int right=getHeight(root->right);
       return max(left,right)+1;
     }
     int getNodes(treeNode *root){
       if(!root)
       return 0;
       int left=getNodes(root->left);
       int right=getNodes(root->right);

       return left+right+1;
     }
     int getSum(treeNode* root){
       if(!root)
       return 0;
       return getSum(root->left)+getSum(root->right)+root->data;
     }

     int getDiameter(treeNode* root,int* height){
       if(!root){
         *height=0;
          return 0;
       }
       int lh=0,rh=0;
       int left=getDiameter(root->left,&lh);
       int right=getDiameter(root->right,&rh);
       int diameter=lh+rh+1;
       *height=max(lh,rh)+1;
       return max(diameter,max(left,right));
     }
      void sumreplacement1(treeNode *root){
       if(!root)
       return;
       sumreplacement1(root->left);
       sumreplacement1(root->right);
       if(root->left)
       root->data=root->data+root->left->data;
       if(root->right)
       root->data+=root->right->data;

     }
     int sumreplacement(treeNode *root){
       if(!root)
        return 0;
       int left=sumreplacement(root->left);
       int right=sumreplacement(root->right);
       root->data=left+right+root->data;
       return root->data;

     }
};
int main(){
    tree hey;
    int total,element;
    cin>>total;
    for(int i=0;i<total;i++){
        cin>>element;
        hey.root=hey.insert(hey.root,element);
    }
    cout<<"Inorder: ";
    hey.inorder(hey.root);
    cout<<endl<<"Preorder: ";
    hey.preorder(hey.root);
    cout<<endl<<"Postorder: ";
    hey.postorder(hey.root);
    cout<<endl<<"Level order: ";
    hey.levelorder(hey.root);
    cout<<endl<<"Height: ";
    cout<<hey.getHeight(hey.root);
    cout<<endl<<"Total Nodes: ";
    cout<<hey.getNodes(hey.root);
    cout<<endl<<"Total Sum of Nodes: ";
    cout<<hey.getSum(hey.root);
    int answer=hey.sumreplacement(hey.root);
   //hey.sumreplacement1(hey.root);
    cout<<endl<<"Inorder: ";
    hey.inorder(hey.root);
    cout<<endl<<"Preorder: ";
    hey.preorder(hey.root);
    cout<<endl<<"Postorder: ";
    hey.postorder(hey.root);
    cout<<endl<<"Level order: ";
    hey.levelorder(hey.root);
    
   
    getchar();
    return 0;
}