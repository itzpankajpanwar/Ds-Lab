/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Functions and classes implemented :

TreeNode Class : this class store information of a node

Make_Threaded_BinaryTree fnction  : this function creates a threaded binary tree at runtime 

Preorder_traversal()  function :  this function prints preorder traversal of a threaded binary tree

*/


#include<iostream>
#include<conio.h>
#include<string>
#include<vector>

#define ld long double 

using namespace std;

class TreeNode     // this is a TreeNode class which holds value of a node 
{                  // data holds value of data of node, leftchild denotes the leftpointer of node, rightchild denotes the rightpointer
  public:
    ld data;
    TreeNode* leftchild;
    TreeNode* rightchild;
    ld isthread;

    //constructor  of class TreeNode
    TreeNode()       // automatically called whenever object of TreeNode is created and initialie value to the node
    {                // default value of node is as follows data =0, leftpointer = NULL , rightpointer = NULL
        data=0;
        leftchild=NULL;
        rightchild=NULL;
        isthread=0;
	}
};

// this is Make_Threaded_BinaryTree function 
// it creates a tree and returns roots node as output
TreeNode* Make_Threaded_BinaryTree()
{   
    ld value;  
    int current_index=0;    // this variable is used to denote the currentindex in queue 
    int max_index=0;        // this vaiable is used to keep track of last element location in queue 
    ld value2;

    // to create tree four pointers are maintained 
    TreeNode *Head= NULL;           // head pointer to denote the rootnode
	TreeNode *currentnode= NULL;    // currentnode pointer to hold current node 
	TreeNode *leftnode = NULL;      // leftnode pointer to hold the leftchild of currentnode
	TreeNode *rightnode = NULL;     // rightnode pointer to hold the rightchild of currentnode

	TreeNode *upcoming_elements[1000];   // array of 1000 elements to keep track of all nodes in levelwise order 

    cout<<"\nEnter the value of root node (press -1 for NULL) = ";
	cin>>value;    // this variable holds data of root node 
	if(value!=-1)       // if -1 means root pointer is null and out tree is empty 
	{
		Head = new TreeNode();
		Head->data=value;
		upcoming_elements[max_index++]=Head;    //pushing current node into queue so 

		while(current_index < max_index)
        {
            currentnode = upcoming_elements[current_index++];   // picking front node from queue 
            value = currentnode->data;                          // value of current node 

            cout<<"\nEnter the value of left child "<<value<< " (press -1 for NULL) =  ";
            cin>>value2;        // this variable holds data of left child of current node

            if(value2!=-1)      // if -1 means left child of current  node is null and we do not process in that direction
            {
                leftnode = new TreeNode();   // creating a newnode i.e creating leftchild of current node
                leftnode->data = value2;     // creating a newnode i.e creating leftchild of current node
                currentnode->leftchild = leftnode;   
                upcoming_elements[max_index++]= leftnode;    // assigning pointer accordingly
                leftnode->rightchild = currentnode->rightchild;  
            }   

            cout<<"\nEnter the value of right child "<<value<< " (press -1 for NULL) =  ";
            cin>>value2;         // here this variable holds data of rigth child of current node
            if(value2!=-1)     // if -1 means right child of current  node is null and we do not process in that direction
                {		  
                    rightnode= new TreeNode();   // creating a newnode i.e creating leftchild of current node
                    rightnode->data = value2;    // creating a newnode i.e creating leftchild of current node
                    rightnode->rightchild = currentnode->rightchild;
                    currentnode->rightchild = rightnode;   // assigning pointer accordingly
                    upcoming_elements[max_index++]=rightnode;
                    
                    if(leftnode != NULL)             // if leftchild of current node exists then point it to rightchild of currentnode
                        {  leftnode->rightchild = rightnode; }
                }
            
            if(leftnode==NULL && rightnode==NULL)   // if current node is a leaf node then assign  thread value true 
               { currentnode->isthread = 1; }
            
            leftnode=NULL;     // make both pointer NULL so can be used in furhter iteration without any issue 
            rightnode=NULL;
	    }
    }	
return Head;   // returning root node 
}

// this function is used to print preorder traversal of a binary threaded tree
// it takes tree as input and prints its preorder traversal 
void Preorder_traversal(TreeNode* head_node)
{   TreeNode* current_node;
    current_node = head_node;    // assigning current node to root node 
    while(current_node != NULL)
	{                                 
	  	cout<<current_node->data<<" ";
	  	if(current_node->leftchild != NULL)
		  { 
            current_node = current_node->leftchild;
          }
	  	else
	     	{
              current_node = current_node->rightchild;
            }
	}	
    cout<<endl;
}

// main function 
int main()
{
    cout<<"\n  CREATING TREE  \n\n";
    cout<<"\n Input Method : level wise input of tree \n";

    TreeNode* root = Make_Threaded_BinaryTree();   // making threaded binary tree at runtime

    cout<<"\n Preoder Traversal of the tree : ";

    Preorder_traversal(root);    // function to print preorder traversal of threaded tree

    cin.get();
    return 0;
}
