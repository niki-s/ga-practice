#include <iostream>
#include <stdlib.h>

using namespace std;


const int POPSIZE = 100;
const int VECLEN = 150;
const int TOTAL_GENERATIONS = 10;

struct pop
{
	int member[VECLEN];
	double fitness;
};

double eval(int *pj);
void fillPool(pop pool[POPSIZE]);
double evalPool(pop pool[POPSIZE]);
void roulette(pop pool[POPSIZE], double totalFitness);
void combine(pop parent1, pop parent2);

int main(int argc, char const *argv[])
{
	//do stuff with argv later to determine pop size and things?
	pop pool[POPSIZE];
	double totalFitness = 0.0;

	fillPool(pool);
	totalFitness = evalPool(pool);
	cout << totalFitness << endl;

	// for (int gen = 0; gen < TOTAL_GENERATIONS; gen++)
	// {
	// 	//do roulette
	// 	//recombine new population
	// 	//eval new pop
	// }

	//cout << pool[5].fitness << endl;

	return 0;
}

void fillPool(pop pool[POPSIZE])
{
	for (int i = 0; i < POPSIZE; i++)
	{
		for (int j = 0; j < VECLEN; j++)
		{
			pool[i].member[j] = rand() % 2;
		}
	}
}

double evalPool(pop pool[POPSIZE])
{
	double totalFitness = 0;
	for (int i = 0; i < POPSIZE; i++)
	{
		pool[i].fitness = eval(pool[i].member);
		totalFitness += pool[i].fitness;
	}
	return totalFitness;
}

void combine(pop parent1, pop, parent2)
{
	int crosspoint = rand() % 150;
	
}
	//print vector from pop
	// for (int i = 0; i < VECLEN; ++i)
	// {
	// 	cout << pool[0].member[i];
	// }
	// cout << endl;