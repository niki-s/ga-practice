#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int MAXITER = 10000;

double eval(int *pj);

int main(int argc, char const *argv[])
{
  ofstream saveFile;
  if (argc != 2)
  {
    cout << "please include a save file name, " << argv[0] << " <filename>" << endl;
    return 1;
  }
  else
  {
    saveFile.open(argv[1]);
  }
  if (!saveFile.is_open())
  {
    cout << "could not open file" << endl;
    return 1;
  }
  // ofstream saveFile;
  // saveFile.open("save.txt");
  int bestVec[150];
  int nextVec[150];
  int bestFitness = 0;
  int fitness = 0;

  srand (time(NULL));
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
	if (i % 1000 == 0){
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
