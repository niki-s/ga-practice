/*
 * evaluate.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 */

#include <evaluate.h>
#include <utils.h>
#include <const.h>

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <assert.h>

#include <random>

using namespace std;

void evaluate(ga::Individual *ent){
//	cout << *ent << endl;
	double sum = 0;
	for(int i = 0; i < ent->length; i++){
		sum += ent->chrom[i];
	}
	ent->fit = sum;
	for(int i = 0; i < ga::MAX_CRITERIA; i++){
		ent->fitness[i] = sum;
	}

//	cout << "----------------------------------------" << endl;

}

double decode(int * chrom, int start, int end){
  double prod = 0;
  for (int i = start; i < end; i++){
    prod += (chrom[i] == 0 ? 0 : pow(2.0, (double) i));
  }
  //cout << prod << endl;
  return prod;
}

void xSquared(ga::Individual *ent) {
  int value = decode(ent->chrom, 0, ent->length);
  ent->fit = value * value;
  return;

}

void firstDeJong(ga::Individual *ent) {
	double totalFit = 0;
	float x1 = decode(ent->chrom, 0, 5, -5.12, 5.12);
	float x2 = decode(ent->chrom, 5, 10, -5.12, 5.12);
	float x3 = decode(ent->chrom, 10, ent->length, -5.12, 5.12);

	totalFit = x1*x1 + x2*x2 + x3*x3;
	ent->fit = 1.0/totalFit;
}

void secondDeJong(ga::Individual *ent) {
	double totalFit = 0;
	float x1 = decode(ent->chrom, 0, 5, -2.048, 2.048);
	float x2 = decode(ent->chrom, 5, 10, -2.048, 2.048);
	
	totalFit = 100.0*pow((pow(x1, 2.0) - x2),2.0) + pow(1-x1, 2.0);
	ent->fit = 1.0/totalFit;
}

void thirdDeJong(ga::Individual *ent) {
	double totalFit = 0.0;
	float x1 = decode(ent->chrom, 0, 5, -5.12, 5.12);
	float x2 = decode(ent->chrom, 5, 10, -5.12, 5.12);
	float x3 = decode(ent->chrom, 10, 15, -5.12, 5.12);
	float x4 = decode(ent->chrom, 15, 20, -5.12, 5.12);
	float x5 = decode(ent->chrom, 20, ent->length, -5.12, 5.12);

	//totalFit = (int)x1 + (int)x2 + (int)x3 + (int)x4 + (int)x5;
	totalFit = ceil(x1) + ceil(x2) + ceil(x3) + ceil(x4) + ceil(x5);
	cout << (int)x1 << " " << ceil(x1) << " " << totalFit << endl;
	ent->fit = 1.0/(double)totalFit;
}

void fourthDeJong(ga::Individual *ent) {
	float totalFit = 0;
	float value = decode(ent->chrom, 0, ent->length, -5.12, 5.12);
	for (int i = 0; i < 3; i++) {
		totalFit += value * value;
	}
	ent->fit = totalFit;
}

void fifthDeJong(ga::Individual *ent) {
	float totalFit = 0;
	float value = decode(ent->chrom, 0, ent->length, -5.12, 5.12);
	for (int i = 0; i < 3; i++) {
		totalFit += value * value;
	}
	ent->fit = totalFit;
}