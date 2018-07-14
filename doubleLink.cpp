#include "doubleLink.h"

#include<string>
#include<iostream>
using namespace std;

doubleLink::doubleLink()
{
	tail=new Node;
	tail->str="";
	tail->last=NULL;
	tail->next=NULL;
	currentNode=tail;
}

void doubleLink::addNode(string _str)
{
	Node* newNode=new Node;
	Node* last=tail->last;
	newNode->str=_str;
	if(last!=NULL)
    {
        last->next=newNode;
        newNode->next=tail;
        tail->last=newNode;
        newNode->last=last;
    }
    else
    {
        newNode->next=tail;
        tail->last=newNode;
        newNode->last=NULL;
    }
}

void doubleLink::lastNode()
{
    if(currentNode->last!=NULL)
    currentNode=currentNode->last;
}

void doubleLink::nextNode()
{
    if(currentNode->next!=NULL)
    currentNode=currentNode->next;
}

void doubleLink::show()
{
    Node* x=tail;
    cout<<endl;
    while(x!=NULL)
    {
        std::cout<<x->str<<"   ";
        x=x->last;
    }
    cout<<endl;
}
