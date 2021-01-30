/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Approach Used: 
To solve Tower of hanoi problem without recursion i used Traingle method 
i.e. intially place all stacks in form of a traingle
so intially starting stack will contain all the disks 

so if no of disks is even then:
        smallest disk moves clockwise i.e. from stack 1 to stack 2,stack2 to stack3 and from stack3 to stack 1
        after moving smallest disk there is only one valid move between other stacks ,do that valid move
        repeat this procedure 2^n-1 times 
        and  problem 
        
if no of Disks is odd then :
        smallest disk moves anti-clockwise i.e. from stack 1 to stack 3,stack2 to stack1 and from stack3 to stack2
        after moving smallest disk there is only one valid move between other stacks ,do that valid move
        repeat this procedure 2^n-1 times 
        and  problem solved

Functions and classes implemented :

Stackclass : to do stack related operations

displaytower : to display current stack

makemoves : to move a valid disk move from one stack to another

mainfunction : to do all these operations
      

*/


#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000


class Stackclass
{
    public :
        int stackdata[MAXSIZE];
    
        int currentpos=-1; //Sets the Top Location to -1 indicating an empty stack

        // push a element  into stack
        void push(int a){
                stackdata[++currentpos] = a;
                //cout<<"\n cp = "<<currentpos;
            }  
        //pop a element from a stack
        int pop(){
            return(stackdata[currentpos--]);
        }  

        //function to check if stack is empty or not 
        int empty()
        {
            if(currentpos==-1){
                return 1;
            }
            return 0;
        }
        int size_of_stack()
        {
            return (currentpos+1);
        }
};

void displaytower(Stackclass p,int i)
{   Stackclass ms;  // making a temporary stck
    int element;
    cout<<"\n\nTower  "<<i<<"   ==>  ";
    while(!p.empty()){
        ms.push(p.pop());      //pushing all elements to temporary stack
    }
    while(!ms.empty()){
        element=ms.pop();
        cout<<element<<"   ";//poping elements one by one and printing them and storing them back in original stack
        p.push(element);
    }

}

void makemoves(Stackclass &s1,Stackclass &s2,int i,int j)
{   int element,element1,element2;
    if(s1.empty()){              //condition to checck if first stack is empty and 2nd stack coantins some elements
                if(!s2.empty())   //if so then move disk from secons stack to first stack
                {
                    element=s2.pop();
                    s1.push(element);
                    cout<<"\n\n move disk "<<element<<" from stack"<<j<<" to stack "<<i;
                }
            }
            else if(s2.empty()){   //condition to checck if first stack contains some element and 2nd stack empty
                if(!s1.empty())     ////if so then move disk from first stack to second stack
                {
                    element=s1.pop();
                    s2.push(element);
                    cout<<"\n\n move disk "<<element<<" from stack"<<i<<" to stack "<<j;
                }
            }
            else if(!s1.empty() && !s2.empty())  //if both stack contains some disk then move smaller disk at top among them
            {
                element1=s1.pop();
                element2=s2.pop();
                if(element1>element2)
                {   
                    s2.push(element2);
                    s2.push(element1);
                     cout<<"\n\n move disk "<<element1<<" from stack"<<i<<" to stack "<<j;
                }
                else{

                    s1.push(element1);
                    s1.push(element2);
                     cout<<"\n\n move disk "<<element2<<" from stack"<<j<<" to stack "<<i;
                }
            }
}


int main()
{   long long i,maxi,size_of_stack,element1,element2,element;
    cout<<"\n Enter No of Discs  ";  //taking stack size as input
    cin>>size_of_stack;

    Stackclass A,B,C;

    //initiallly pushing n disks into first stack 
    for(i=1;i<=size_of_stack;i++){
        A.push(i);
    }

    //for maximum no of operations in stack
    maxi = pow(2,size_of_stack);

    
    int smalldiskpos=1;

    cout<<"\n initally tower looks like this ";
    displaytower(A,1);
    displaytower(B,2);
    displaytower(C,3);

    for(i=0;i<maxi;i+=2)
    {        
        if(size_of_stack%2==0)
        {
            if(smalldiskpos==1){
                makemoves(A,B,1,2);  //for anticlockwise  movement of smallest disk
                makemoves(A,C,1,3);
                smalldiskpos=2;
            }
            else if(smalldiskpos==2)
            {
                makemoves(B,C,2,3);  //for anticlockwise  movement of smallest disk
                makemoves(A,B,1,2);
                smalldiskpos=3;
            }
            else
            {
                makemoves(C,A,3,1);  //for anticlockwise  movement of smallest disk
                makemoves(B,C,2,3);
                smalldiskpos=1;
            }
            
        }
        
        // for odd disk size
        else   
            {
            if(smalldiskpos==1){
                makemoves(A,C,1,3);      //for anticlockwise  movement of smallest disk
                makemoves(A,B,1,2);
                smalldiskpos=3;
            }
            else if(smalldiskpos==2)
            {
                makemoves(B,A,2,1);     //for anticlockwise  movement of smallest disk
                makemoves(C,B,3,1);
                smalldiskpos=1;
            }
            else
            {
                makemoves(C,B,3,2);     //for anticlockwise  movement of smallest disk
                makemoves(A,C,1,3);
                smalldiskpos=2;
            }
        }


        //for displaying current status of tower
        displaytower(A,1);
        displaytower(B,2);
        displaytower(C,3);

    }

    cin.get();
    return 0;
}

