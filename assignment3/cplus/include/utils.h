/*
 * utils.h
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 *
 *	Used for assignment 3 in CS776 by Niki Silveria Sept 22, 2017
 *  https://www.cse.unr.edu/~sushil/class/gas/code/cplus/
 */

#ifndef UTILS_H_
#define UTILS_H_

void swap(int *x, int a, int b);
void shuffle(int *x, int size);

void printIntArray(int *x, int size);

void writeBufToFile(std::string buf, std::string filename);
void chromToString(int *x, int len, char *s);
void stringToChrom(char *chromChar, int len, int *chromInt);
float decode (int *chrom, int start, int end, float min, float max);
float decode(const char* chrom, int start, int end, float min, float max);

#endif /* UTILS_H_ */
