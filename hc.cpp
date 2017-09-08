#include <iostream>
#include <stdlib.h>

//using namespace std;

double eval(int* pj);
int* modifyVec(int* previousVec);

int main(){
	int* bestVec = new int[100];
	//int bestVec[100];
	int* vec;
	double bestFitness = 0;
	int fill;
	int i = 0;

	double fitness;

	for(fill = 0; fill < 100; fill++){
		bestVec[fill] = 0;
	}

	bestFitness = eval(bestVec);

	while(bestFitness < 100){
		vec = modifyVec(bestVec);
		fitness = eval(vec);

		if (fitness > bestFitness){
			bestVec = vec;
			bestFitness = fitness;
		}
		i++;
	}

	// for (int i = 0; i < 1000; ++i){
	// 	vec = modifyVec(bestVec);
	// 	fitness = eval(vec);

	// 	if (fitness > bestFitness){
	// 		bestVec = vec;
	// 		bestFitness = fitness;
	// 	}
	// }

	std::cout << "best fitness = " << bestFitness << std::endl;
	std::cout << "in total iterations: " << i << std::endl;

	//delete vec;
	delete bestVec;
	}

int* modifyVec(int* previousVec){
 	int* newVec = new int[100];
 	//fill the new victor with the same values as the previous one
 	for (int i = 0; i < 100; ++i){
 		newVec[i] = previousVec[i];
 	}
	//generate a random index from between 0 and 99
	int randIndex = rand() % 100;

	//reference this index of the vector and flip the bit, return new value
	newVec[randIndex] = 1 - newVec[randIndex];
	return newVec;
}