#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class plant { 
public:
	plant();
	plant(const char newID[], int newG, int newN, int newW);
	~plant();
	
	char* getID();
	int getGrowth();
	int getNutrition();
	int getWater();

	friend ostream& operator<< (ostream& os, const plant& outPlant);
private:
	char id[30];
	int G;
	int N;
	int W;
};

#endif
