#ifndef DOUBLELINK_H
#define DOUBLELINK_H

#include<string>
using namespace std;

struct Node
{
	Node* last;
	string str;
	Node* next;
};

class doubleLink
{
private:
	Node* tail;
	Node* currentNode;
public:
	doubleLink();
	void addNode(string _str);
	void lastNode();
	void nextNode();
	void resetCur(){currentNode=tail;}
	string getCurrentString(){return currentNode->str;}
	void show();
};

#endif
