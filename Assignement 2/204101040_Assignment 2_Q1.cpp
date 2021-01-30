/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

StepWise Program flow:

step 1 : Ask for datatype of queue
step2 : make a queue object according to its datatype
        for this i used templates so only i have to define class only on
step 3 : after creating queue object inside settype function  ask user about type of queue to be inplemented
step 4 : based on user input select queue type
step 5 :Take size of queue as user input
step 6 : display queue operatoions menu
step 8 : select one option
step 9 : perform that operations 
step 10 : repeat step 6 until exit is pressed
step 11 : end


To implement Queue using 2 stacks i had class queue and class stack and both are implemented
with templates so they can vary according to datatype . inside queue class two stacks object 
are created . stack 1 is used for insertion into queue and stack 2 is used for deletion .so a 
new element is inserted into stack 1 and whenever deletion is required all elements of stack1
 and pushed into stack 2 and topmost element is taken out .this is done so as to maintain queue 
 property i.e. FIFO(first in first out).

 functions in queue class: Enqueue - for insertion
                           Dequeue  - for deletion

functions ins stack calss: Push - for pushing into stack
                           pop - for poping out from stack
                           empty - to check if stack is empty or not
                           top - to get topmost element position

settype function - to set datatype of Queue according to user and for further implementation of queue

*/

#include <bits/stdc++.h> 
using namespace std; 
#define  MAXSIZE 1000

/*
here i used Used Template so that any type of data can be
stored in Stack without multiple defination of class
*/
template<typename T>
class Stackclass
{
    public :
        T stackdata[MAXSIZE];
    
        int currentpos=-1; //Sets the Top Location to -1 indicating an empty stack

        // push a element  into stack
        void push(T a){
                stackdata[++currentpos] = a;
                //cout<<"\n cp = "<<currentpos;
            }

        
        //pop a element from a stack
        T pop(){
           // cout<<" deleted will be "<<stackdata[currentpos];
          // cout<<"\nDeletion  cp = "<<currentpos;
            return(stackdata[currentpos--]);
        }   

        T empty()
        {
            if(currentpos==-1){
                return 1;
            }
            return 0;
        }
        T top()
        {
            return currentpos;
        }
};

/*
here i used Used Template so that any type of data can be
stored in Stack without multiple defination of class
*/
template<class X>
class Queue { 
    private:
      Stackclass <X> s1,s2;     //creating twos stacks inside queue class
    public:  
    void enQueue(X x)   //function for inserting element into queue
        {  
            s1.push(x); 
        } 
    // Delete an item from the queue 
    int deQueue()    //function for deleting element from queue
        { 
            X deleted;
            // if first stack is empty 
            if (s1.empty()) { 
                cout << "Queue is Empty"; 
                return -1; 
            } 
            while (!s1.empty()) { 
                s2.push(s1.pop()); 
            }

            deleted=s2.pop();

            while (!s2.empty()) { 
                s1.push(s2.pop()); 
            } 
            return(deleted);
        } 
    void showqueue()   //function for Displaying Queue
        {
            if (s1.empty()) { 
                cout << "Queue is Empty"; 
            } 
            while (!s1.empty()) { 
                s2.push(s1.pop()); 
            }
            while(!s2.empty())
            {
                X p;
                p=s2.pop();
                cout<<"  "<<p;
                s1.push(p);
            }
        }    
}; 


template<typename Q>
void settype()
{
    Queue <Q> q;
    int choice;
    cout<<"\n Type of Queue you wanted to implement ";
    cout<<" \n1. Linear Queue ";
    cout<<"\n2. Circular Queue ";
    cout<<"\nEnter your choice : ";
    cin>>choice;
   
    long int queuesize,x=0;
    Q element;
    if(choice==1)
        cout<<"\nImplementing Linear Queue ";
    else if(choice==2)
        cout<<"\n Implementing Circular Queue";
    else
    {
        cout<<"\nWrong chocie ";
        cout<<"\nImplementing Circular Queue by default";
    }
    
    
    cout<<" \n Enter Queue Size ";
    cin>>queuesize;

    do{
    cout<<"\n\nSelect one of the following options";
    cout<<"\n1. Insert element (enque) ";
    cout<<"\n2. Delete element (DeQue) ";
    cout<<"\n3. Show current Queue  ";
    cout<<"\n4. Exit ";
    cout<<"\n Enter your Choice : ";
    cin>>x;

    if(x==1)
        {   if(queuesize>0)
                {
                cout<<" \nEnter element to be Inserted : ";
                cin>>element;
                q.enQueue(element);
                cout<<"\nElement Successfuly inserted ";
                queuesize--;
                }
            else
                {
                    cout<<"\n Insertion blocked ";
                    cout<<"\n Data can not be added further ";  
                }
        }
    if(x==2)
        {   Q deleted;
            deleted=q.deQueue();
            if(deleted!=-1)
            {   cout<<" \n "<<deleted<<" is deleted from Queue ";
                if(choice==2){queuesize++;}   
                }
        }
    if(x==3)
    {
        cout<<" \n Current Queue is :  ";
        q.showqueue();
    }


    }while(x==1 || x==2 ||x==3); 
}

int main() 
{  
    int ds;
    cout<<"\nData type of queue you wanted to Implement : ";
    cout<<"\n 1. Character ";
    cout<<"\n 2. Integer  ";
    cout<<"\n 3. float  ";
    cout<<"\n 4. Double ";
    cout<<"\n Enter your Choice : ";
    cin>>ds;
    if(ds == 1) 
        settype<char>();
    else if(ds == 2) 
        settype<int>();
    else if(ds == 3) 
        settype<float>();
    else if(ds == 4) 
        settype<double>();
    else 
        printf("\nChoice not matched"); 
  
    cout<<"\n Code terminated  ";   
    cout<<"\n Thanks for your Time "; 
    cin.get();
    return 0; 
} 