//============================================================================
// Name        : ga.cpp
// Author      : Sushil J Louis
// Version     :
// Copyright   : Copyright University of Nevada, Reno
// Description : GA in C++, Ansi-style
//============================================================================
/*
 *	Used and edited for assignment 3 in CS776 by Niki Silveria Sept 22, 2017
 *  https://www.cse.unr.edu/~sushil/class/gas/code/cplus/
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utils.h>
#include <population.h>
#include <ga.h>
#include <random.h>

using namespace std;
using namespace ga;

int main(int argc, char *argv[]) {

	GA ga = GA(argc, argv);

	ga.init();
	ga.run();
	ga.report();

	return 0;
}

GA::GA(int argc, char *argv[]){

	setupOptions(argc, argv);
	srandom(options.randomSeed);
	ofstream ofs(options.outfile, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	ofstream pofs(options.phenotypeFile, std::ofstream::out | std::ofstream::trunc);
	pofs.close();
	maxFitGen = 0;
	this->bestIndividualSoFar = new Individual(options.chromLength);
	bestFitnessSoFar = -1;


}


void GA::init(){
	parent = new Population(options);
	child  = new Population(options);
	parent->initialize(); // evaluates, stats, and reports on initial population
	updateProgress(0, parent);
//	cout << "initialized" << endl;
}



//
//void GA::CHC(Population *p, Population *c){
//}

void GA::run(){//chc

	Population *tmp;
	for (unsigned int i = 1; i < options.maxgens; i++){
	  //		parent->chc(child);
	        parent->generation(child);
		child->statistics();
		child->report(i);

		updateProgress(i, child);

		tmp = parent;
		parent = child;
		child = tmp;
		//cout << "Generation: " << i << endl;
	}

}

/**
 * Update and save the best ever individual
 */
void GA::updateProgress(unsigned int gen, Population *p){

  if (p->max > bestFitnessSoFar){
    bestFitnessSoFar = p->max;
    maxFitGen = gen;
    bestIndividualSoFar->copy(p->pop[p->maxi]);
    
    char printbuf[1024];
    char chromString[MAX_CHROM_LENGTH+1];
    chromToString(bestIndividualSoFar->chrom, bestIndividualSoFar->length, chromString);
    sprintf(printbuf, "%4i \t %f \t %s\n", maxFitGen, bestFitnessSoFar, chromString);
    writeBufToFile(printbuf, options.phenotypeFile);
  }
  
}


void GA::report(){
	int startLen = 0;
	int chromSectionLen = 5;
	float val = 0.0;
	//parent->report(options.maxgens);
	cout << *(parent->pop[parent->maxi]) << endl;
	// for (int i = 0; i < 30; i++) {
	// 	//val = decode(ent->chrom, i, i+1, -65.536, 65.536);
	// 	val = decode(parent->pop[parent->maxi]->chrom, startLen, startLen+chromSectionLen, -1.28, 1.28);
	// 	cout << val << " ";
	// 	startLen += chromSectionLen;
	// }
	// cout << endl;
	//float x1 = decode(parent->pop[parent->maxi]->chrom, 0, 5, -2.048, 2.048);
	//float x2 = decode(parent->pop[parent->maxi]->chrom, 5, 10, -2.048, 2.048);
	// float x3 = decode(parent->pop[parent->maxi]->chrom, 10, 15, -5.12, 5.12);
	// float x4 = decode(parent->pop[parent->maxi]->chrom, 15, 20, -5.12, 5.12);
	// float x5 = decode(parent->pop[parent->maxi]->chrom, 20, 25, -5.12, 5.12);

	//cout << x1 << ", " << x2 << ", " << x3 << endl;
	//cout << x1 << ", " << x2 << endl;//", " << x3 << ", " << x4 << ", " << x5 << endl;
}

void GA::configure(){
	ifstream ifs(options.infile);
	if(ifs.good()){
		ifs >> options.popSize;
		ifs >> options.chromLength;
		ifs >> options.maxgens;
		ifs >> options.px;
		ifs >> options.pm;
		ifs >> options.scaler;
		ifs >> options.lambda;
	}
	ifs.close();
}

void GA::setupOptions(int argc, char *argv[]){

	options.randomSeed = 177;
	options.infile = string("infile");
	options.outfile = string("outfile_177");// append randomseed to output file names

	options.popSize = 60;
	//15 for #1
	//10 for #2
	//25 for #3
	//150 for #4
	options.chromLength = 150;
	options.maxgens = 80;
	options.px = 0.7f;
	options.pm = 0.001f;
	options.scaler = 1.05;
	options.lambda = 2;
	options.nCriteria   = 1;

	options.mutator = Mutator::Flip;
	options.xover = Xover::UX;
	options.selector = Selector::Proportionate;

	if(argc == 4){
		options.infile = string(argv[1]);
		options.outfile = string(argv[2]);
		options.randomSeed = atoi(argv[3]);
		configure();
	}
	//derived values go after configure() above
	options.phenotypeFile   = string(options.outfile + ".pheno"); //derived from options.outfile
	//options.maxgens = options.popSize * 1.5;


}


