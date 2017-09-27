/*
 * evaluate.h
 *
 *  Created on: Mar 15, 2016
 *      Author: sushil
 *
 *	Used for assignment 3 in CS776 by Niki Silveria Sept 22, 2017
 *  https://www.cse.unr.edu/~sushil/class/gas/code/cplus/
 */

#ifndef EVALUATE_H_
#define EVALUATE_H_

#include <individual.h>
#include <cstring>

void evaluate(ga::Individual *ent);
void xSquared(ga::Individual *ent);
void firstDeJong(ga::Individual *ent);
void secondDeJong(ga::Individual *ent);
void thirdDeJong(ga::Individual *ent);
void fourthDeJong(ga::Individual *ent);
void convertToString(int *vec, int size, char *chrom);
#endif /* EVALUATE_H_ */
