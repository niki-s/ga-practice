#include <iostream>
#include <stdlib.h>

//using namespace std;

double eval(int* pj);
int* modifyVec(int* previousVec);
int* createRandomVec();
void hillclimber();

int main(){

	for (int i = 0; i < 1; i++){
		std::cout << "uh" << std::endl;
		hillclimber();
	}
}

int* modifyVec(int* previousVec){
	std::cout << "modify?" << std::endl;

 	int newVec[150];
 	int randIndex, randIndex1, randIndex2 = 0;
 	//fill the new victor with the same values as the previous one
 	for (int i = 0; i < 150; ++i){
 		newVec[i] = previousVec[i];
 	}
	// generate a second random number that will determine if one or two bits are changed
	int changeTwo = rand() % 200;

	if (changeTwo % 10 == 0){
		// generate TWO random indexes from between 0 and 99
		randIndex1 = rand() % 100;
		randIndex2 = rand() % 100;
		//reference this index of the vector and flip the bit, return new value
		newVec[randIndex1] = 1 - newVec[randIndex1];
		newVec[randIndex2] = 1 - newVec[randIndex2];

	}
	else{
		// generate a random index from between 0 and 99
		randIndex = rand() % 100;
		//reference this index of the vector and flip the bit, return new value
		newVec[randIndex] = 1 - newVec[randIndex];
	}

	//reference this index of the vector and flip the bit, return new value
	newVec[randIndex] = 1 - newVec[randIndex];
	return newVec;
}

int* createRandomVec(){
	int* random = new int[150];
	for(int i = 0; i < 150; i++){
		random[i] = rand() % 2;
	}

	return random;
}

void hillclimber(){
	int* bestVec = new int[150];
	//int bestVec[100];
	int* vec;
	//int* randomVec;
	double bestFitness = 0;
	int fill;
	int i = 0;

	double fitness;

	for(fill = 0; fill < 150; fill++){
		bestVec[fill] = rand() % 2;
	}

	bestFitness = eval(bestVec);
	std::cout << bestFitness << std::endl;

	for (i = 0; i < 1; i++){
		vec = modifyVec(bestVec);
		//randomVec = createRandomVec();

		fitness = eval(vec);
		std::cout << "after check?" << std::endl;
		if (fitness >= bestFitness){
			bestVec = vec;
			bestFitness = fitness;
		}
		std::cout << "after check?" << std::endl;

		// fitness = eval(randomVec);
		// if (fitness >= bestFitness){
		// 	bestVec = randomVec;
		// 	bestFitness = fitness;
		// }
	}


	std::cout << "best fitness = " << bestFitness << std::endl;
	std::cout << "in total iterations: " << i << std::endl;
	std::cout << "with vector: " << std::endl;
	for(i = 0; i < 150; i++){
		std::cout << bestVec[i];
	}
	std::cout << std::endl;


	delete bestVec;
}