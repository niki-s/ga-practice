#include <iostream>
#include <stdlib.h>

//using namespace std;

double eval(int* pj);
int* modifyVec(int* previousVec);
int* createRandomVec();
void hillclimber();

int main(){

	for (int i = 0; i < 20; i++){
		hillclimber();
	}
	// int* bestVec = new int[100];
	// //int bestVec[100];
	// int* vec;
	// int* randomVec;
	// double bestFitness = 0;
	// int fill;
	// int i = 0;

	// double fitness;

	// for(fill = 0; fill < 100; fill++){
	// 	bestVec[fill] = rand() % 2;
	// }

	// bestFitness = eval(bestVec);

	// //while(bestFitness < 100){
	// for (i = 0; i < 100000; i++){
	// 	vec = modifyVec(bestVec);
	// 	fitness = eval(vec);

	// 	if (fitness > bestFitness){
	// 		bestVec = vec;
	// 		bestFitness = fitness;
	// 	}
	// 	i++;
	// }

	//while(bestFitness < 100){
	// for (i = 0; i < 100000; i++){
	// 	vec = modifyVec(bestVec);
	// 	randomVec = createRandomVec();

	// 	fitness = eval(vec);
	// 	if (fitness > bestFitness){
	// 		bestVec = vec;
	// 		bestFitness = fitness;
	// 	}
	// 	fitness = eval(randomVec);
	// 	if (fitness > bestFitness){
	// 		bestVec = randomVec;
	// 		bestFitness = fitness;
	// 	}
	// }

	// std::cout << "best fitness = " << bestFitness << std::endl;
	// std::cout << "in total iterations: " << i << std::endl;
	// std::cout << "with vector: " << std::endl;
	// for(i = 0; i < 100; i++){
	// 	std::cout << bestVec[i];
	// }
	// std::cout << std::endl;

	//delete vec;
	//delete bestVec;
	}

int* modifyVec(int* previousVec){
 	int* newVec = new int[100];
 	int randIndex, randIndex1, randIndex2 = 0;
 	//fill the new victor with the same values as the previous one
 	for (int i = 0; i < 100; ++i){
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
	int* random = new int[100];
	for(int i = 0; i < 100; i++){
		random[i] = rand() % 2;
	}

	return random;
}

void hillclimber(){
	int* bestVec = new int[100];
	//int bestVec[100];
	int* vec;
	int* randomVec;
	double bestFitness = 0;
	int fill;
	int i = 0;

	double fitness;

	for(fill = 0; fill < 100; fill++){
		bestVec[fill] = rand() % 2;
	}

	bestFitness = eval(bestVec);

	////while(bestFitness < 100){
	// for (i = 0; i < 100000; i++){
	// 	vec = modifyVec(bestVec);
	// 	fitness = eval(vec);

	// 	if (fitness > bestFitness){
	// 		bestVec = vec;
	// 		bestFitness = fitness;
	// 	}
	// 	i++;
	// }

	//attempt 2

	//while(bestFitness < 100){
	for (i = 0; i < 1000000; i++){
		vec = modifyVec(bestVec);
		randomVec = createRandomVec();

		fitness = eval(vec);
		if (fitness >= bestFitness){
			bestVec = vec;
			bestFitness = fitness;
		}
		fitness = eval(randomVec);
		if (fitness >= bestFitness){
			bestVec = randomVec;
			bestFitness = fitness;
		}
	}

	if (bestFitness == 70){
		std::cout << "It's 70 again :/" << std::endl;
	}
	else{
		std::cout << "best fitness = " << bestFitness << std::endl;
	}
	std::cout << "in total iterations: " << i << std::endl;
	std::cout << "with vector: " << std::endl;
	for(i = 0; i < 100; i++){
		std::cout << bestVec[i];
	}
	std::cout << std::endl;


	delete bestVec;
}