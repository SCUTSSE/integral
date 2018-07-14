#ifndef RBTREE_H
#define RBTREE_H

#include<iostream>
#include<stack>
using namespace std;

enum RBTColor{RED,BLACK};

class RBTNode{
	public:
		RBTColor color;
		double key;
		double coefficient;
		RBTNode *left;
		RBTNode *right;
		RBTNode *parent;

		RBTNode(double value,double _coefficient,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r):
			key(value),coefficient(_coefficient),color(c),parent(p),left(l),right(r){}
        double getCoefficient(){return coefficient;}
        void setCoefficient(double _coefficient){coefficient=_coefficient;}
};

class RBTree{
	private:
		RBTNode *mRoot;
	public:
		RBTree():mRoot(NULL){}
		~RBTree(){};

		stack<double> inOrder();

		RBTNode* search(double key);
		double minimum();
		double maximum();

		RBTNode* successor(RBTNode* x);
		RBTNode* predecessor(RBTNode* x);
		void insert(double key,double _coefficient);
		void remove(double key);
		void setNodeCoeff(double key,double NewCoeff);
	private:
		void inOrder(RBTNode* tree,stack<double>& result) const;

		RBTNode* search(RBTNode* x,double key) const;
		RBTNode* minimum(RBTNode* tree);
		RBTNode* maximum(RBTNode* tree);

		void leftRotate(RBTNode* &root,RBTNode* x);
		void rightRotate(RBTNode* &root,RBTNode* x);
		void insert(RBTNode* &root,RBTNode* node);
		void insertFixUp(RBTNode* &root,RBTNode* node);
		void remove(RBTNode* &root, RBTNode *node);
        void removeFixUp(RBTNode* &root, RBTNode *node, RBTNode *parent);
};

#endif
