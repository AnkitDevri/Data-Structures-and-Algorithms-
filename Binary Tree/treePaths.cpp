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

   void calculatePaths(vector<string>& paths, string& path, treeNode* root){  
        if(!root) {
            return;
        }
        string temp = path;
        if(path.empty()) 
            path.append(to_string(root->data));
        else{
            string str1("->");
            str1.append(to_string(root->data));
            path.append(str1);
        }
            
        if(!root->left && !root->right) {
            paths.push_back(path);
            path = temp;
            return;
        }
        calculatePaths(paths,path,root->left);
        calculatePaths(paths,path,root->right);
        
        path = temp;
        
    }
    vector<string> binaryTreePaths(treeNode* root) {
        vector<string> paths;
        string path;
        calculatePaths(paths,path,root);
        return paths;
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