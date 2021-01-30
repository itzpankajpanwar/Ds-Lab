/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

working expalnation :
first we defined node class and circularlinked list.now we create a circualr link list with n nodes
where n is given by user and along with n we also take k as input which is step size
so  we start from start node and march forward to stepsize and kill kth person froms start node
and that kth person can be start node as well 
now next node to the killed person becomes our start node 
and we keep on repeating this procedure until only one person remains
and during all this procedure we keep track no of link traversed 
and at last print its value

*/

#include<iostream>
#include<conio.h>
#include<vector>
#define ld long double 
#define lld long long double
#define loop(x,n) for(int x = 1; x <= n; ++x)

using namespace std;


class Node {    //creating a node class
public:
    int data;
    Node* next;
};

class Circular_Linked_List{    //circualr linked list class 
    private:
        Node* head;

    public:
        Circular_Linked_List() {    // Constructor
            head = NULL;
        }
        ~Circular_Linked_List() {};  // Destructor

        void add_Node(int val);
        void add_last_Node(int val);
        void display();
        int element_count();
        int Josephus(Circular_Linked_List* list,int n,int k);
};


// function to add node to a list
void Circular_Linked_List::add_Node(int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
            head = newnode;
        }
    else {
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        }
        temp->next = newnode; 
    }
}

//adding last node
//function for linking last node with starting node so as to make a circualr linked list
void Circular_Linked_List::add_last_Node(int val) {
    Node* temp = head; 
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = head;
    while (temp->next != NULL) { 
        temp = temp->next; // go to end of list
        }
    temp->next = newnode; 
}

// function for display current linked list
void Circular_Linked_List::display() {
    if (head == NULL) {           //when there is no head element means empty list
        cout << "List is empty!" << endl;
    }
    else {
        Node* temp = head;
       
        while (temp->next != head) {      // itrating through all nodes until we reach head/start node again
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";       //printing last node data as this node points to starting node again
    }
}

int Circular_Linked_List::element_count() {
    Node * temp = head;
    ld count_no_of_nodes=0;
    while (temp->next != head) {
            count_no_of_nodes+=1;
        }
    count_no_of_nodes+=1;
    return count_no_of_nodes;
}

int Circular_Linked_List::Josephus(Circular_Linked_List* list,int n,int k) {
    Node* temp = head;
    Node * killer = head;
    ld link_treversed=0;
    while(n>1){  
        ld var=0;                //traversing next k-1 nodes so to kill Kth node
        loop(i,k-1){
            var+=1;              //incrementing link traversed values
            temp=temp->next; 
            if(temp==killer){    //this condition when we are travesing for kth node but reaches intial node again before kth turn  i.e. when elements are  less than K 
                var=0;
            }
        }
        link_treversed+=(var+1);
        cout<<"\n\n"<<killer->data<<" kills "<<(temp->next)->data;
        if((temp->next)==killer){   //this condition when a node kills itself so no link traversed as mentioned by sir
             link_treversed-=(var+1);
        }

        if(temp->next==head){   //when head node is deleted so we make next node(from head node ) as head node
            head=(temp->next)->next;
        }

        link_treversed+=1;                  // increment for passing sword to next killer

        temp->next=(temp->next)->next;      // upadating links so as to remove killed node
        killer=temp->next;                  // updating to new killer 
        temp=killer;                        // upating current killer
        n-=1;
       
        cout<<" \nCurrent  Link traversed status = "<<link_treversed;
        cout << "\nCurrent remaining peoples : ";
        list->display();
        cout<<"\nNew killer is : "<<temp->data;
    }
    return link_treversed;
}


int main() {
    ld k,n;
    cout<<"\n Program  for Implementation of JOSEPHUS PROBLEM  ";
    cout<<"\n\n Enter value of N : ";
    cin>>n;
    cout<<"\n Enter value of K : ";
    cin>>k;   
    
    Circular_Linked_List* list = new Circular_Linked_List();

    loop(i,n-1){             //for loop to create a linked lsit consisting of all these elemnts 
        list->add_Node(i);
    }
    list->add_last_Node(n);  //to add last element as it points to first element of list 


    cout << "\nLinked List data : ";  //Dislaying initial link list
    list->display();

    ld result = list->Josephus(list,n,k);    //calling josephus algorithm for solving josephus problem 

    cout<<"\n\n Total number of link traversed is "<<result;   // Printing number of link traversed while solving problem
     
    delete list;      // after all our work deleting list
    cout<<"\n Press any key  to exit : ";
    getch();
    return 0;
}
