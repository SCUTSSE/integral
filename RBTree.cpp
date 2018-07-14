#include<iostream>
#include "RBTree.h"
using namespace std;

stack<double> RBTree::inOrder()
{
	stack<double> result;
	inOrder(mRoot,result);
	return result;
}

void RBTree::inOrder(RBTNode* tree,stack<double>& result) const
{
	if(tree!=NULL)
	{
		inOrder(tree->left,result);
		result.push(tree->coefficient);
		result.push(tree->key);
		inOrder(tree->right,result);
	}
}

RBTNode* RBTree::search(double key)
{
	return search(mRoot,key);
}

RBTNode* RBTree::search(RBTNode* x,double key) const
{
	while((x!=NULL)&&(x->key!=key))
	{
		if(key<x->key)
		x=x->left;
		else
		x=x->right;
	}
	return x;
}

RBTNode* RBTree::minimum(RBTNode* tree)
{
	if(tree==NULL)
	{
		return NULL;
	}
	while(tree->left!=NULL)
	{
		tree=tree->left;
	}
	return tree;
}

double RBTree::minimum()
{
	RBTNode* p=minimum(mRoot);
	if(p!=NULL)
	return p->key;
	return (double)NULL;
}

RBTNode* RBTree::maximum(RBTNode* tree)
{
	if(tree==NULL)
	return NULL;
	while(tree->right!=NULL)
	{
		tree=tree->right;
	}
	return tree;
}

double RBTree::maximum()
{
	RBTNode *p=maximum(mRoot);
	if(p!=NULL)
	return p->key;
	return (double)NULL;
}

RBTNode* RBTree::successor(RBTNode* x)
{
	if(x->right!=NULL)
	return minimum(x->right);
	RBTNode* y=x->parent;
	while((y!=NULL)&&(x==y->right))
	{
		x=y;
		y=y->parent;
	}
	return y;
}

RBTNode* RBTree::predecessor(RBTNode* x)
{
	if(x->left!=NULL)
	{
		return maximum(x->left);
	}
	RBTNode* y=x->parent;
	while((y!=NULL)&&(x==y->left))
	{
		x=y;
		y=y->parent;
	}
	return y;
}

void RBTree::leftRotate(RBTNode* &root,RBTNode* x)
{
	RBTNode *y=x->right;

	x->right=y->left;
	if(y->left!=NULL)
	y->left->parent=x;

	y->parent=x->parent;
	if(x->parent==NULL)
	{
		root=y;
	}
	else
	{
		if(x->parent->left==x)
		x->parent->left=y;
		else
		x->parent->right=y;
	}

	y->left=x;
	x->parent=y;
}

void RBTree::rightRotate(RBTNode* &root,RBTNode* x)
{
	RBTNode *y=x->left;
	x->left=y->right;
	if(y->right!=NULL)
	y->right->parent=x;
	x->parent=y->parent;
	if(x->parent==NULL)
	{
		root=y;
	}
	else
	{
		if(x->parent->left==x)
		x->parent->left=y;
		else
		x->parent->right=y;
	}

	y->right=x;
	x->parent=y;
}

void RBTree::insert(double key,double _coefficient)
{
	RBTNode* z=new RBTNode(key,_coefficient,RED,NULL,NULL,NULL);
	insert(mRoot,z);
}

void RBTree::insert(RBTNode* &root,RBTNode* node)
{
	RBTNode* y=NULL;
	RBTNode* x=root;
	while(x!=NULL)
	{
		y=x;
		if(node->key<x->key)
		x=x->left;
		else
		x=x->right;
	}
	node->parent=y;
	if(y!=NULL)
	{
		if(node->key<y->key)
		y->left=node;
		else
		y->right=node;
	}
	else
	root=node;
	insertFixUp(root,node);
}

void RBTree::insertFixUp(RBTNode* &root,RBTNode* node)
{
	RBTNode *parent,*gparent;
	while((parent=node->parent)&&(parent->color==RED))
	{
		gparent=parent->parent;
		if(parent==gparent->left)
		{
			{
				RBTNode *uncle=gparent->right;
				if(uncle&&(uncle->color==RED))
				{
					uncle->color=BLACK;
					parent->color=BLACK;
					gparent->color=RED;
					node=gparent;
					continue;
				}
			}
			if(parent->right==node)
			{
				RBTNode* tmp;
				leftRotate(root,parent);
				tmp=parent;
				parent=node;
				node=tmp;
			}
			parent->color=BLACK;
			gparent->color=RED;
			rightRotate(root,gparent);
		}
		else
		{
			{
				RBTNode* uncle=gparent->left;
				if(uncle&&uncle->color==RED)
				{
					uncle->color=BLACK;
					parent->color=BLACK;
					gparent->color=RED;
					node=gparent;
					continue;
				}
			}
				if(parent->left==node)
				{
					RBTNode *tmp;
					rightRotate(root,parent);
					tmp=parent;
					parent=node;
					node=tmp;
				}
				parent->color=BLACK;
				gparent->color=RED;
				leftRotate(root,gparent);
		}
	}
	root->color=BLACK;
}

void RBTree::setNodeCoeff(double key,double NewCoeff)
{
    RBTNode* x=mRoot;
    while((x!=NULL)&&(x->key!=key))
	{
		if(key<x->key)
		x=x->left;
		else
		x=x->right;
	}
	x->setCoefficient(NewCoeff);
}

void RBTree::removeFixUp(RBTNode* &root, RBTNode *node, RBTNode *parent)
{
    RBTNode *other;

    while ((!node || node->color==BLACK) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (other->color==RED)
            {

                other->color=BLACK;
                parent->color=RED;
                leftRotate(root, parent);
                other = parent->right;
            }
            if ((!other->left || other->left->color==BLACK) &&
                (!other->right || other->right->color==BLACK))
            {

                other->color=RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->right || other->right->color==BLACK)
                {

                    other->left->color=BLACK;
                    other->color=RED;
                    rightRotate(root, other);
                    other = parent->right;
                }

                other->color=parent->color;
                parent->color=BLACK;
                other->right->color=BLACK;
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (other->color==RED)
            {

                other->color=BLACK;
                parent->color=RED;
                rightRotate(root, parent);
                other = parent->left;
            }
            if ((!other->left || other->left->color==BLACK) &&
                (!other->right || other->right->color==BLACK))
            {

                other->color=RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!other->left || other->left->color==BLACK)
                {

                    other->right->color=BLACK;
                    other->color=RED;
                    leftRotate(root, other);
                    other = parent->left;
                }
				other->color=parent->color;
                parent->color=BLACK;
                other->left->color=BLACK;
                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        node->color=BLACK;
}

void RBTree::remove(RBTNode* &root, RBTNode *node)
{
    RBTNode *child, *parent;
    RBTColor color;

    if ( (node->left!=NULL) && (node->right!=NULL) )
    {
        RBTNode *replace = node;

        replace = replace->right;
        while (replace->left != NULL)
            replace = replace->left;

        if (node->parent)
        {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        else
            root = replace;

        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            if (child)
                child->parent= parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent=replace;
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == BLACK)
            removeFixUp(root, child, parent);

        delete node;
        return ;
    }

    if (node->left !=NULL)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;

    if (child)
        child->parent = parent;

    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;
}

void RBTree::remove(double key)
{
    RBTNode *node;
    if ((node = search(mRoot, key)) != NULL)
        remove(mRoot, node);
}
