/* 
Name : Pankaj Panwar
MTech Cse 1st year
Roll NO : 204101040

Compiler Used : g++

Aprroach Used : 
initiallly i take  number of vertex and nunber of edges as input
now i take all edges as input 
now based on those edges i created a dependency graph
i.e. let say if there is a directed edge from 1->2 it means that vertex 2 depend on vertex 1
so i put 1 in dependency list of 2   means 2 is dependent on 1
after this i take a topological order as input from user ( for testing )
now we iterate through all the vertex in given topological order and for each vertex we check that if all those vertex 
on which this vertex depends is already visited or not ( i maintained a  vector visited for this )
if current vertex is possible then add it to visited
if not then simply print not possible 

*/

#include <iostream> 
#include <bits/stdc++.h> 
#include<vector>
using namespace std; 
int main() 
{ 	
	int v_no,e_no,flag=1,a,b,val;          // declaring all the varibles
	vector<int> topoorder;                // vector to store user input topologial order
	vector<int> visited;                  //  vector to store all visited vertex initally blank

	cout<<" \n Enter No of vertices : "; cin>>v_no;     // taking no of vertex as input
	cout<<" \n Enter No of edges : "; cin>>e_no;      // taking no of edges as input
	
	vector<vector<int>> vct(v_no+1);        // declaring a vector to store dependecny graph

	for(int i=0;i<e_no;i++)        // taking all edges input from user
		{
			cout<<"\nEnter both vertices of  edge No (space separated values) "<<i+1<<" : ";
			cin>>a>>b;
			vct[b].push_back(a);      // storing dependency value in dependency graph
		}
	cout<<"\n Enter topological order that we need to check (space separated values)  :  ";
	for(int i=0;i<v_no;i++)      // taking topological order as input from user
	{
		cin>>val;
		topoorder.push_back(val);
	}
	int first=topoorder[0];    // first element is topological order
	if(vct[first].size() != 0)    //checking if first element is possible or not
		{cout<<" FALSE as this topological ordering not possible for this grpah ";
		cout<<" here is it ";
		}
	else
	{
		visited.push_back(first);   // making first element as visited 
		for(int i=1;i<v_no;i++)
		{
			int element=topoorder[i];
			for(int j=0;j<vct[element].size();) // checking for each element if all elements on which it depends is already visited or not
			{	
				int value=vct[element][j];
				if (find(visited.begin(), visited.end(),value)!=visited.end())
					j++;
				else                  //if vertex on which current vertex depends are not visited then print False
				{
					cout<<" FALSE as this topological ordering not possible for this grpah ";
					flag=0;
					break;
				}	
			}
			//falg to check if topological order is possible or not before  current vertex
			if(flag != 0)
				{ visited.push_back(element);  }
			else
				break;
		}
		//it means given topological order is possible 
		if(flag==1) cout<<"\n TRUE this topological ordering possible for this grpah";
	}

	return 0; 
} 
