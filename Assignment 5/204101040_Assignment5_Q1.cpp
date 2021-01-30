/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Functions and classes Implemented :

swap : this function is used to swap two values

max_heap = this is maxheapify function this method rearranges the elements of an array 
           where the left and right sub-tree of ith element obeys the  maxheap property.

build_maxheap : this function is used to build a max heap from a given array


min_heapify = this is minheapify function this method rearranges the elements of an array 
           where the left and right sub-tree of ith element obeys the  minheap property.

build_minheap : this function is used to build a mix heap from a given array

partitionFunction :  this function is used to take a key and put this key to its exact position in array 
                     such that all element left to key is lesser than key
                     and all element to right of key is greater than key
                     and returns position of key

extractmin: this function is used to extract the minimum element from a MIN heap 
            and again call heapify operation 
            and returns the minimum element

extractmax: this function os used to extract the maximum element from a MAX heap 
            and again call heapify operation 
            and returns the minimum element  
*/
#include<iostream>
#include <vector>
#define ld long double
using namespace std; 

void swap(ld* a, ld* b){   // swap function for swapping two elements 
    ld temp = *a;
    *a = *b;
    *b = temp;
}
void max_heap(vector<ld> &arr, int n, int nl) {   // this is maxheapify function 
    ld maxIndex = nl;        // here nl is the index on which this fuction is callled and n is the size of heap
    ld leftIndex = 2*nl + 1;
    ld rightIndex = 2*nl + 2;

    if(leftIndex < n && arr[leftIndex] > arr[maxIndex]) maxIndex = leftIndex;
    if(rightIndex < n && arr[rightIndex] > arr[maxIndex]) maxIndex = rightIndex;

    if(maxIndex == nl) return;

    swap(&arr[maxIndex], &arr[nl]);
    max_heap(arr, n, maxIndex);
}

vector<ld> build_maxheap(vector<ld> arrayelements,ld start,ld end) {   // build maxheap function to create a maxheap 
   ld k;
   int n = end-start+1;
   vector<ld> a;    // it cretes a balnk vector names as a

   for(int i=start;i<=end;i++)
   {
      a.push_back(arrayelements[i]);    // storing all those values from which we build max heap
   }
   for(k = (n/2)-1; k >= 0; k--) {
      max_heap(a,n,k);
   }
   return a;
}
void min_heapify(vector<ld> &arr, int n, int nl)   // min heapify function 
{
   ld minIndex = nl;        // here nl is the index on which this fuction is callled and n is the size of heap
   ld leftIndex = 2*nl + 1;
   ld rightIndex = 2*nl + 2;

   if(leftIndex < n && arr[leftIndex] < arr[minIndex]) minIndex = leftIndex;
   if(rightIndex < n && arr[rightIndex] < arr[minIndex]) minIndex = rightIndex;

   if(minIndex == nl) return;

   swap(&arr[minIndex], &arr[nl]);
   max_heap(arr, n, minIndex);
}

vector<ld> build_minheap(vector<ld> arrayelements,ld start,ld end) {   // build minheap function to create a minheap
   ld k;
   int n = end-start+1;
   vector<ld> a;                 // it cretes a balnk vector names as a
      for(int i=start;i<=end;i++)
      {  
         a.push_back(arrayelements[i]);    // storing all those values from which we build max heap
      }
      for(k = (n/2)-1; k >= 0; k--) {
         min_heapify(a,end,k);
      }
  return a;
}
ld partitionFunction(vector<ld> &myArr, ld start_point, int end_point,int position)   // partition method
{
   ld pivotelement = myArr[position];   //pivot element from where partion is done
   ld temp = myArr[position];
   myArr[position] = myArr[end_point];    // swapping position element to end point elements so as to easily do partition procedure
   myArr[end_point] = temp;

   ld i = start_point;     
   for(ld j = start_point; j <= end_point-1; j++)
      {
         if(myArr[j] <= pivotelement)  //checking if element less than or not if presnent then move it to left side
         {
               ld temp = myArr[j];
               myArr[j] = myArr[i];
               myArr[i] = temp;
               i++;
         }
      }
      temp = myArr[i];          // swapping end point position element and i position element
      myArr[i] = myArr[end_point];
      myArr[end_point] = temp;
   return i;
}
ld extractmin(vector<ld> &right)   // this function is used to extract minimum element from a min heap 
{
   ld s=right.size();
   ld minimum=right[0];    // taking the minimum element from the minheap 
   right[0]=right[s-1];   // moving last element to root position
   right.pop_back();     // removing last element 
   if(right.size()>1)
   { min_heapify(right,right.size(),0);}   // heapifying minheap so as to maintain heap property 
   return minimum;     // returning minimum element 
}

ld extractmax(vector<ld> &left)  // this function is used to extract minimum element from a min heap 
{
   ld s=left.size();
   ld maxi=left[0];   // taking the minimum element from the minheap 

   left[0]=left[s-1];   // moving last element to root position

   left.pop_back();    // removing last element 
   if(left.size()>1)
   { max_heap(left,left.size(),0); }   // heapifying maxheap so as to maintain heap property 
   return maxi;   // returning maximum element 
}
int main()
{   
   vector<ld> array_elements;   // vector to store user input array 
   ld ele,key,no_of_elements,k;

   ld abc;
   vector<ld> left;     // vector to maxheap  
   vector<ld> right;    // vector to store minheap

   cout<<" \nEnter No of elements : ";   //taking no of elements as input
   cin>>no_of_elements;
   cout<<" \nEnter values of elements\n ";  // taking all elements as input
   for(int i=0;i<no_of_elements;i++)
      {  cout<<"\nEnter value of element "<<i+1<<" : ";
         cin>>ele;
         array_elements.push_back(ele);  
      }
   cout<<" \nEnter value of key : ";   // taking key as input
   cin>>key;
   cout<<" \nEnter value of k : ";  // taking value of k as input
   cin>>k;

   int position=-1;   
   for(int i=0;i<no_of_elements;i++)   // this loop is to find the position of key in userinput array
   {
      if(array_elements[i]==key)
      {
         position=i;
         break;
      }
      if(i==no_of_elements-1)
         {cout<<"\n Given key value not present in element list ";}
   }
   //ld val = partition(array_elements,no_of_elements,key);
   ld val = partitionFunction(array_elements,0,no_of_elements-1,position);   //calling partition  method

   left = build_maxheap(array_elements,0,val-1);   // building maxheap from all left side elements from pivot
   right = build_minheap(array_elements,val+1,no_of_elements-1);  // building minheap from all right side elements from pivot
   
   cout<<"\n\n K closest elements are as follows : ";


   while(k>0)    //taking k closest elements from key 
   { 
          
      if( left.size() != 0 && right.size()!=0)
         { 
            if(right[0]-key < key-left[0])
            {
               abc=extractmin(right);
               cout<<abc<<"  ";
               k--;
               continue;
            }
            else
            {
               abc=extractmax(left);
               cout<<abc<<"  ";
               k--;
               continue;
            }
         }
      else if( left.size() != 0 && right.size()==0)
         {
            abc=extractmax(left);
            cout<<abc<<"  ";
            k--;
         }
      else if( left.size() == 0 && right.size()!=0)
         {
            abc=extractmin(right);
            cout<<abc<<"  ";
               k--;
         }
      else if( left.size() == 0 && right.size()==0)
         {
            cout<<"\n all elements of given array comes under k closest elemnts ";
            break;
         }
   }
   cout<<endl;
   return 0;
}