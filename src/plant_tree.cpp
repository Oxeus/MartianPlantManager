#include "plant_tree.h"
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

planttree::planttree()
{
	node * root = nullptr;
}

planttree::~planttree()
{
	//destroy(root);
}

void planttree::destroy(node * curr)
{
	/*if(curr != nullptr)
	{
		destroy(curr->left);
		curr->left = nullptr;
		destroy(curr->right);
		curr->right = nullptr;
		delete curr;
		delete curr->plantptr;
	}*/
}

void planttree::setRoot(plant pla)
{
		root = new node;
		root->plantptr = new plant;
		*root->plantptr = pla;
		root->left = nullptr;
		root->right = nullptr;
}

void planttree::addChildren(plant pla1, plant pla2, plant pla3)
{
	node * curr = root;
	node * newNode = search(curr, pla1);
	newNode->left = new node;
	newNode->left->plantptr = new plant;
	*newNode->left->plantptr = pla2;
	newNode->left->left = nullptr;
	newNode->left->right = nullptr;
	newNode->right = new node;
	newNode->right->plantptr = new plant;
	*newNode->right->plantptr = pla3;
	newNode->right->left = nullptr;
	newNode->right->right = nullptr;
}

planttree::node * planttree::search(node * curr, plant pla1)
{
	if (curr == nullptr) return nullptr;
	if (curr != nullptr && strcmp(curr->plantptr->getID(), pla1.getID()) == 0)
	{
		return curr;
	}
	else
	{
		node * found = search(curr->left, pla1);
		if (found != nullptr) return found;
		found = search(curr->right, pla1);
		if (found != nullptr) return found;
	}
	return nullptr;
}

plant * planttree::findBestGrowth()
{
	return(findMaxG(root)->plantptr);
}

planttree::node * planttree::findMaxG(node * curr)
{
	if (curr == nullptr)
	{
		return nullptr;
	}
	node * res = curr;
	node * lres = findMaxG(curr->left);
	node * rres = findMaxG(curr->right);
	if (lres != nullptr)
	{
		if (lres->plantptr->getGrowth() > res->plantptr->getGrowth())
		{
			res = lres;
		}
	}
	if (rres != nullptr)
	{
		if (rres->plantptr->getGrowth() > res->plantptr->getGrowth())
		{
			res = rres;
		}
	}
	
	return res;
} 

plant * planttree::findBestNutrition()
{
	return(findMaxN(root)->plantptr);
}

planttree::node * planttree::findMaxN(node * curr)
{
	if (curr == nullptr)
	{
		return nullptr;
	}
	node * res = curr;
	node * lres = findMaxN(curr->left);
	node * rres = findMaxN(curr->right);
	if (lres != nullptr)
	{
		if (lres->plantptr->getNutrition() > res->plantptr->getNutrition())
		{
			res = lres;
		}
	}
	if (rres != nullptr)
	{
		if (rres->plantptr->getNutrition() > res->plantptr->getNutrition())
		{
			res = rres;
		}
	}

	return res;
}

plant * planttree::findBestWater()
{
	return(findMaxW(root)->plantptr);
}

planttree::node * planttree::findMaxW(node * curr)
{
	if (curr == nullptr)
	{
		return nullptr;
	}
	node * res = curr;
	node * lres = findMaxW(curr->left);
	node * rres = findMaxW(curr->right);
	if (lres != nullptr)
	{
		if (lres->plantptr->getWater() > res->plantptr->getWater())
		{
			res = lres;
		}
	}
	if (rres != nullptr)
	{
		if (rres->plantptr->getWater() > res->plantptr->getWater())
		{
			res = rres;
		}
	}

	return res;
}

void planttree::display()
{
	inOrder(root, 0);
}

void planttree::inOrder(node * curr , int level)
{
	if (curr != NULL)
	{
		if (level) {
			cout << setw(level) << ' ';
		}
		cout << *curr->plantptr << endl;
		if (curr->left) inOrder(curr->left, level + 2);
		if (curr->right) inOrder(curr->right, level + 2);
	}
}

