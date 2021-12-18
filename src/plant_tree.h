#include "plant.h"

class planttree {
public:
	
	planttree();
	~planttree();
	void setRoot(plant pla);
	void addChildren(plant pla1, plant pla2, plant pla3);
	void display();
	plant * findBestGrowth();
	plant * findBestNutrition();
	plant * findBestWater();
	
private:
	struct node {
		plant * plantptr;
		node * left;
		node * right;
	};
	node * root;
	void destroy(node * curr);
	void inOrder(node * curr, int level);
	node * findMaxG(node * curr);
	node * findMaxN(node * curr);
	node * findMaxW(node * curr);
	node * search(node * curr, plant pla);
};
