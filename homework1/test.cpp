#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int MAXITER = 1000;

double eval(int *pj);

int main()
{
  ofstream saveFile;
  saveFile.open("save.txt");
  int bestVec[150];
  int nextVec[150];
  int bestFitness = 0;
  int fitness = 0;

  int randIndex1 = 0;
  int randIndex2 = 0;

  int i;

  for(i = 0; i < 150; i++){
    bestVec[i] = rand() % 2;
    nextVec[i] = bestVec[i];
  }

  bestFitness = eval(bestVec);

  for (i = 0; i < MAXITER; i++){
  	//modify the current best vector
  	randIndex1 = rand() % 150;
	nextVec[randIndex1] = 1- nextVec[randIndex1];

	fitness = eval(nextVec);

	if (fitness >= bestFitness){
		bestVec[randIndex1] = nextVec[randIndex1];
		bestFitness = fitness;
	}
	else{
		//turn next vec back into the current best
		// not great but the other way is segfaulting so eh...
		nextVec[randIndex1] = bestVec[randIndex1];
	}
	if (i % 100 == 0){
		cout << i << " " << bestFitness << endl;
		saveFile << i << "," << bestFitness << endl;
	}
  }
  cout << bestFitness << " with ";
  saveFile << MAXITER << "," << bestFitness << endl;

  for(i = 0; i < 150; i++){
		cout << bestVec[i];
	}
	cout << endl;
  //printf("Fitness = %lf\n", eval(vec));
}
