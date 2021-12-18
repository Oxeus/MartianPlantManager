#include <iostream>
#include "plant.h"
#include <cstring>

using namespace std;

plant::plant()
{
	G = 0;
	N = 0;
	W = 0;
}

plant::plant(const char newID[], int newG, int newN, int newW)
{	
	strcpy(id, newID);
	G = newG;
	N = newN;
	W = newW;
}

plant::~plant()
{

}

char* plant::getID()
{
	return id;
}

int plant::getGrowth()
{
	return G;
}

int plant::getNutrition()
{
	return N;
}

int plant::getWater()
{
	return W;
}

ostream& operator<< (ostream& os, const plant& outPlant)
{
os << "Plant ID: " << outPlant.id << " " << "(G: " << outPlant.G << " N: " << outPlant.N << " W: " << outPlant.W << ")";
	return os;
}
