/*

Name : PANKAJ PANWAR
MTech CSE 1st year
ROLL NO : 204101040

Compiler Used : LINUX G++
IDE: Visual Studio Code

*/



#include<bits/stdc++.h>
#include<iostream>
using namespace std;



class Polynomial{

    private:
       
        /*  vector of pairs. In this information about polynomial is stored 
            in form of pairs of (exponent,cofficient)
            for example  : polynomial  5x^2+6x^6-3x^5+6
            is stored as : [(2,5),(6,6),(5,-3),(0,6)
        */
        
        vector<pair<double,double>> poly;

    public:

        //Constructor for creating a polynomial 
        //It takes cofficnet array,exponent array and no of terms from user and create a object of class polynomial
        Polynomial(int a[], int b[],int length){
            for(int i=0;i<length;i++){
                poly.push_back(std::make_pair(b[i],a[i]));

                /* here i made pair (b[i],a[i]) which means pair in
                form of (exponent,cofficient) so that i can directly 
                sort vector usig inbulit function in decreasing order 
                of exponennt*/
            }
            }    
        
        // Function  For addition of two Polynomail
        // It takes two polynomial as argument (i.e. Object of class Polynomial) and returns a Polynomial
       
        Polynomial add_two_polynomial(Polynomial p,Polynomial q){
            int l1= p.poly.size();          //Getting no of terms in both Polynomials
            int l2=q.poly.size();

            int added=0;

            /*Approach  : take a term from second polynomial and check if any of the exponent in first polynomial
                        equals to its exponent if it equals then add their cofficient otherwise make a separate pair 
                        for this term in first polynomial 
                        Also used a variable added so as to check it match found or not 
                        time complexity O(m*n)  m,n=no of terms in polynomials  
            */
            for(int j=0;j<l2;j++){
                added=0;
                for(int i=0;i<l1;i++){     
                    if(p.poly[i].first==q.poly[j].first){
                        p.poly[i].second+=q.poly[j].second;
                        added=1;
                        break;
                    }
                }
                if(added==0){
                   p.poly.push_back(std::make_pair(q.poly[j].first,q.poly[j].second)); 
                }
            }
            // finally after all addition sort Polynomial
            sort(p.poly.rbegin(), p.poly.rend());
            return p;
        }


        // Function  For Subtraction of two Polynomail
        // It takes two polynomial as argument (i.e. Object of class Polynomial) and returns a Polynomial
        Polynomial subtract_two_polynomial(Polynomial p,Polynomial q){
             int l1= p.poly.size();
             int l2=q.poly.size();

            int added=0;
            // Approach: same approach as used in addition of two polynoamial function
            for(int j=0;j<l2;j++){
                added=0;
                for(int i=0;i<l1;i++){     
                    if(p.poly[i].first==q.poly[j].first){
                        p.poly[i].second-=q.poly[j].second;
                        added=1;
                    }
                }
                if(added==0){
                    int neg=0-q.poly[j].second;
                   p.poly.push_back(std::make_pair(q.poly[j].first,neg)); 
                }
            }
            sort(p.poly.rbegin(), p.poly.rend());
            return p;
        }

        /*Function for Display of Polynomail
          any object of class Polynomial can be displayed using this function
          working : first get the size of Polynomial and iterate over all pairs to diplay them 
          A variable printed is used so as to check if anything is displayed or not 
          if nothing is dislayed then simply print 0 as it is blank polynomial */
        void display_polynomial(){
            int length= poly.size();
            int printed=0;
            for(int i=0;i<length;i++){
                if(poly[i].second!=0){            //this condition to ensure that no 0 cofficient term is displayed
                    if(poly[i].second<0 || i==0){
                        cout<<" "<<poly[i].second<<"x^"<<poly[i].first; 
                        printed=1;
                    }
                    else{
                        cout<<" +"<<poly[i].second<<"x^"<<poly[i].first; //to add a positive sign before positive cofficient term as + is not displayed by default
                        printed=1;
                        } 
                } 
            }
            if(printed ==0){
                cout<<"0";
            }
        }  


        /*function used for multiplying with a polyomial with a scaler
        it takes a number as argument as
        working : find no of terms in vector and iterate over all pairs and multiply cofficient with m 
        */
       
        void multiply_scaler(double m){
            int length= poly.size();
            for(int i=0;i<length;i++){
              poly[i].second*=m;  
            }

        }  


        /*function used for calculating value of polynomial at a no 
        it takes a number as argument as
        working : find no of terms in vector and iterate over all pairs and calculate                
                     value for that pair and add into a result and after all iterations return result
        */
       
        double value_at(double pos){
            double result=0;
            int length= poly.size();
            for(int i=0;i<length;i++){
                result+=(poly[i].second*(pow(pos,poly[i].first)));
            }
            return result;
        }
        
};



/* this is a function to build a polynomial 
in this function no of terms in polynomial is taken as a input and a for loop iterates no of terms times 
and in each iteration cofficient and exponent of that term is taken as input and feeded into cofficient 
and exponent array respectively .
after this Object class Polynomail is build using cofficient array and exponent array 
and in last Object is returned
*/
Polynomial build_Polynomial(){

    cout<<"\nEnter no of terms in  polynomial : ";
    int terms1;
    cin>>terms1;
    int cofficient1[terms1],exponent1[terms1];
    for(int i =0;i<terms1;i++){
        cout<<" Enter coefficient of term "<<i+1<<"  : "; cin>>cofficient1[i];
        cout<<" Enter exponent  of term    "<<i+1<<" : "; cin>>exponent1[i];      
    }

    Polynomial X(cofficient1,exponent1,terms1);
    return X;
}




int main(){


    int i=1,choice=1,terms;
    double x,y;

    //intiallly a polynomial is taken as a input
    cout<<" Create a ploynomial  \n Enter No. of terms in your polynomial  ";
    cin>>terms;
    int cofficient[terms],exponent[terms];
     for(int i =0;i<terms;i++){
        cout<<" enter coefficient of term "<<i+1<<"  : "; cin>>cofficient[i];
        cout<<" enter exponent  of term    "<<i+1<<" : "; cin>>exponent[i];      
     }

  
    Polynomial A(cofficient,exponent,terms);
    cout<<"  Polynomial entered by user is  : ";
    A.display_polynomial();  
    

    //Blank polynomial will be used later .. so at that time values can be  inserted into them 
    int coffi[]={0},expo[]={0},term=1;
    Polynomial B(cofficient,exponent,terms);
    Polynomial C(cofficient,exponent,terms);
  
   while(choice<=7){
        //choice menu 
        
        cout<<"\n\n*****************************************************************************************";
        cout<<" \n 1. Display Current Polynomial";
        cout<<" \n 2. Add another polynomial (overload += operator) i.e. poly(a)+=poly(b)   ";
        cout<<" \n 3. Add two polynomial i.e poly(a)=poly(b)+ploy(c)";
        cout<<" \n 4. Subract another polynomial (overload -= operator) i.e. poly(a)-=poly(b)";
        cout<<" \n 5. subtract two other polynomial i.e poly(a)=poly(b)+poly(c)";
        cout<<" \n 6. Multiply with a scaler (overlaod *= operator)  i.e.  poly(a)*=t";
        cout<<" \n 7. Evaluate current Polynomial at a value ";
        cout<<" \n 8. exit";
        cout<<"\n\n******************************************************************************************";
        cout<<" \n\n Enter your Choice  :  ";
        cin>>choice;
        
       
       switch(choice){
            case 1 : //Case for Displaying Polynomial
                    A.display_polynomial();
                    break;

            case 2 :// Case for addition of two Polynomails
                    cout<<"\n Enter details of second Polynomial";
                    B=build_Polynomial();      //as we have only one Polynomial so we build another Polynomial
                    cout<<" \n first polynomial is          : "; 
                    A.display_polynomial();
                    cout<<" \n second  polynomial is        : "; 
                    B.display_polynomial();
                    cout<<" \n Polynomial after addition is : ";
                    A=A.add_two_polynomial(A,B);
                    A.display_polynomial();
                    break;

            case 3 : cout<<"\n Enter First Polynomial  ";
                    B=build_Polynomial();
                    cout<<"\n Enter Second Polynomial  ";
                    C=build_Polynomial();
                    A=B.add_two_polynomial(B,C);
                    cout<<" \n first polynomial is          : "; 
                    B.display_polynomial();
                    cout<<" \n second  polynomial is        : "; 
                    C.display_polynomial();
                    cout<<" \n Polynomial after addition is : ";
                     A.display_polynomial();
                    break;

             case 4 ://Case for Polynomial subtraction
                    B=build_Polynomial();
                    cout<<" \n first polynomial is          : "; 
                    A.display_polynomial();
                    cout<<" \n second  polynomial is        : "; 
                    B.display_polynomial();
                    cout<<" \nPolynomial after subtraction is : ";
                    A=A.subtract_two_polynomial(A,B);
                    A.display_polynomial();
                    break;

            case 5 : cout<<"\n Enter First Polynomial  ";
                    B=build_Polynomial();
                    cout<<"\n Enter Second Polynomial  ";
                    C=build_Polynomial();
                    A=B.subtract_two_polynomial(B,C);
                    cout<<" \n first polynomial is          : "; 
                    B.display_polynomial();
                    cout<<" \n second  polynomial is        : "; 
                    C.display_polynomial();
                    cout<<" \nPolynomial after subtraction is : ";
                    A.display_polynomial();
                    break;

            case 6 :// Case for multiplication by scaler 
                    double multi;
                    cout<<"\n enter no to which current polynomial is multiplied  : ";
                    cin>>multi;
                   
                    cout<<" \n Polynomial Before multiplication is      : ";
                    A.display_polynomial();  

                    A.multiply_scaler(multi);


                    cout<<" \n Polynomial after multiplication is        : ";
                    A.display_polynomial();  
                    break;    
           
            case 7 ://case for calculating value at
                    double value;
                    cout<<" \n enter value at which result need to be calculated : ";
                    cin>>value;
                     int res = A.value_at(value);
                    cout<<" \n value of Polynomial  ";
                    A.display_polynomial();
                    cout<<" at x = "<<value<<" is  "<<res;
                    break;          
       }

    }
return 0;
}
