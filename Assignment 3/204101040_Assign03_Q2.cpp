/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Time Complexity : Nlog(N)

Space Complexity : O(N)

where N is no of elements in unsorted list

StepWise Program flow:

step 1 : Enter elements from user( unsorted  )
step2 : print list 
step 3 : call merge sort on list
step 4 : divide list into two halfs (distribute list function is used for this )
step 5 : call merge sort on both halfs 
            i.e. recursilvely calling merge sort
step 6 : combines both parts (merge_procedure)
step 8 : finally we get sorted list
step 9 : print sorted list
step10 : end

this is a divide and conquer approach

*/

#include<iostream>
#include<conio.h>
#include<vector>
#define ld long double 
#define lld long long double

#define loop(x,n) for(int x = 1; x <= n; ++x)

using namespace std;

class node {   // defining a node
   public:
   int data;
   node *next;
};

// function for display current linked list
void display_link_list(class node *head) {
    if (head == NULL) {                   //when there is no head element means empty list
        cout << "List is empty!" << endl;
    }
    else {

        node* temp = head; 
        while (temp->next != NULL) {      // itrating through all nodes until we reach last node
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";       //printing last node data n
    }
}

node* make_new_Node(int d) {
   node* temp = new node;
   temp -> data = d;
   temp -> next = NULL;
   return temp;
}

/*in this function we need to find middle element of link list
to do so we can aintain two variable fast and slow
so we increment fast two times and slow onlt one times
so whenver fast reaches at end slow will be at middle 
in this way we find middle element of list in O(n) time   */
void Distribute_List(node* start, node** leftside,node** rightside) {
   node* slow = start;
   node* fast = start -> next;
   while(fast!= NULL) {
      fast = fast -> next;
      if(fast!= NULL) {
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   *leftside = start;
   *rightside = slow -> next;
   slow -> next = NULL;
}


node* Merge_procedure(node* leftside, node* rightside) {  //function for merging two sorted list
   node* newhead = NULL;
   if(leftside == NULL)           //if left side is null then no need of furthe implementation rightside is sorted 
      return rightside;
   if(rightside == NULL)         // if right side is null then no need of furthe implementation rightside is sorted
      return leftside;
   if(leftside -> data <= rightside -> data) {
      newhead = leftside;
      newhead -> next = Merge_procedure(leftside->next,rightside);
   } else {
      newhead = rightside;
      newhead -> next = Merge_procedure(leftside,rightside->next);
      //cout<<newhead->data<<"   newhead value inside merge procedure ";
   }
    //cout<<newhead->data<<"   newhead value before returning";
   return newhead;
}


void mergeSort(node** start) {
   node* head = *start;
   node* leftside;
   node* rightside;
   if(head == NULL || head->next == NULL) {
      return;
   }
   Distribute_List(head,&leftside,&rightside); //split the list in two halves


   mergeSort(&leftside);   //calling mergsort on both half's 
   mergeSort(&rightside);

   *start =  Merge_procedure(leftside,rightside);  //here we have to combine both sorted list
   return;
}

int main() {
    ld n;
    cout << "\n        MERGE SORT IMPLEMENTATION WITHOUT USING EXTRA SPACE        ";
   cout <<"\n\nEnter any number of integers (press 0 to stop entering elements )" << endl;
   int input_no;
   node* current_elemnt,*temp;
   cin >>input_no;
   node* head = make_new_Node(input_no);   
   cin >> input_no;
   temp = head;
   while(input_no) {
      current_elemnt = make_new_Node(input_no);
      temp -> next = current_elemnt;//appending each node
      temp = temp -> next;
      cin >> input_no;
   }

   cout<<"Initial array look like this : ";
   display_link_list(head); // displaying the list

   mergeSort(&head);


   cout<<"\n Sorted array look like this : ";  //displaying final sorted link list
   display_link_list(head);

   cout<<"\n press any key to exit : ";
   getch();
   return 0;
}