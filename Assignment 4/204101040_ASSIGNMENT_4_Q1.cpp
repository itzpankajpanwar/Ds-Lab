/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Functions and classes implemented :

TreeNode Class : this class store information of a node

takeinput fnction  : this function creates a binary tree at runtime  from a rootnode
                    to take a binary tree as input depth first technique is used i.e. depth wise building of tree  
                    by recursive calling it makes a tree
InputBinaryTree function : this function creates a root node and calls takeinput function 
                            which returns a user input  binary tree
                            and then after this this function returns root node

Get_Preorder_Traversal function :  this function returns preorder traversal of a  binary tree
                                Without using recursion
                                it takes a tree(i.e root node of tree ) as input
                                and it returns a vectors which contains preorder traversal of the given binary tree


Get_Postorder_Traversal function :  this function returns  postorder traversal of a  binary tree
                                Without using recursion
                                it takes a tree(i.e root node of tree ) as input
                                and it returns a vectors which contains postorder traversal of the given binary tree

*/

#include<iostream>
#include<conio.h>
#include<vector>
#include<vector>
#include<stack>
#include<queue>
#include<map>

#define ld long double 

using namespace std;


class TreeNode  // this is a TreeNode class which holds value of a node 
{               // data holds value of data of node, leftchild denotes the leftpointer of node, rightchild denotes the rightpointer
  public:
    ld data;
    ld hd;
    TreeNode* leftchild;
    TreeNode* rightchild;
};

//this function creates a binary tree at runtime  from a rootnode
//here this function is recursilvely called to make a tree 
TreeNode* takeInput(TreeNode* nodemain) {
    
    ld left, right;    // these two variables to store value of left and child childs of current node 

    cout<<"\n enter value of left child of "<<nodemain->data<<"  (press -1 for NULL) : ";
    cin >> left;
    if(left != -1)   // if -1 means left child of current  node is null and we do not process in that direction
        {   TreeNode* node = new TreeNode;    //creating leftchild of current node 
            node->data=left;      // assigning value to leftchild to currentndoe
            nodemain->leftchild=node;
            takeInput(node);       // taking input for left subtree
                                //by calling this function we create subtree of leftchild of currentnode
        }
    else { nodemain->leftchild=NULL; }

    cout<<"\n enter value of right child of "<<nodemain->data<<"  (press -1 for NULL) : ";
    cin>>right;
    if(right != -1)  // if -1 means right child of current  node is null and we do not process in that direction
       {    TreeNode* node = new TreeNode;  //creating rightchild of current node 
            node->data=right;               //// assigning value to rightchild to currentndoe
            nodemain->rightchild=node;
            takeInput(node);     // taking input for right subtree
                                //by calling this function we create subtree of rightchild of currentnode
       }
    else { nodemain->rightchild=NULL; }

    return nodemain;    //returning current node
}
 
//this function returns preorder traversal of a  binary tree
// it takes a tree as input
// and returns a vecctor which contains preorder traversal of the tree
vector<ld> Get_Preorder_Traversal(TreeNode* mytree) {

    vector<ld> finalresult;   // this vector contians the preorder traversal o the tree

    stack<TreeNode*> stack;   // stack creation 
    if (!mytree)
        return finalresult;
    stack.push(mytree);     // pushing value into stack
    
    while (!stack.empty())      // loop runs till stack is not empty 
    {
        TreeNode* node = stack.top();   // taking a element from stack
        finalresult.emplace_back(node->data);   // storing that element as into reslt 
        stack.pop();                    // removing top element 
        if (node->rightchild)           // pushing rightnode into stack 
            stack.push(node->rightchild);
        if (node->leftchild)           // pushing leftnode into stack 
            stack.push(node->leftchild);
    }
    return finalresult;  // returning final results
}

//this function returns postrder traversal of a  binary tree
// it takes a tree as input
// and returns a vecctor which contains postorder traversal of the tree
vector<ld> Get_Postorder_Traversal(TreeNode* mytree) {

    vector<ld> finalresult;  // this vector contians the preorder traversal o the tree

    stack<TreeNode*> stack;   //stack creation
    if (!mytree)
        return finalresult;
    stack.push(mytree);   // pushing value into stack  
    
    while (!stack.empty())    // loop runs till stack is not empty 
    {
        TreeNode* node = stack.top();    // taking a element from stack
        finalresult.emplace_back(node->data);
        stack.pop();   // storing that element as into reslt
        if (node->leftchild)
            stack.push(node->leftchild);    // pushing leftnode into stack
        if (node->rightchild)
            stack.push(node->rightchild);       // pushing rightnode into stack 
    }
    return finalresult;
}


//this function creates a root node and calls takeinput function 
//which returns a user input  binary tree                  
TreeNode* InputBinaryTree() 
{

    TreeNode* root = new TreeNode;   //creating root node 
    cout<<"\nenter value  of root node ";
    ld dataval;
    cin >> dataval;             // taking root node data
    root->data=dataval;        // storing root ndoe data 
    root->leftchild=NULL;
    root->rightchild=NULL;
    root = takeInput(root);    // creating tree from that root node
    return root;
}


int main()
{
    vector<ld> preorder;
    vector<ld> postorder;
    cout<<"\n ------------------------- CREATING TREE ----------------------------------- ";
    cout<<"\n\n input order is depth wise   \n";
    
    TreeNode* head = InputBinaryTree();  // function to create a binary tree

    preorder = Get_Preorder_Traversal(head);    
    cout<<"\n\n preorder traversal of tree is  : ";    // printing preorder traversal of tree
    for(ld i=0;i<preorder.size();i++)
    {
        cout<<" "<<preorder[i];
    }

    postorder = Get_Postorder_Traversal(head);   // printing postorder traversal of tree
    cout<<"\n\n postorder traversal of tree is  : ";
    for(ld i=(postorder.size()-1);i>=0;i--)
    {
        cout<<" "<<postorder[i];
    }
    
    cin.get();
    return 0;
}
