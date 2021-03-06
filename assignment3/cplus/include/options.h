/*
 * options.h
 *
 *  Created on: Feb 3, 2016
 *      Author: sushil
 *
 *	Used for assignment 3 in CS776 by Niki Silveria Sept 22, 2017
 *  https://www.cse.unr.edu/~sushil/class/gas/code/cplus/
 */

#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <string>
#include <const.h>
namespace ga {

	typedef struct {
		std::string infile;
		std::string outfile;
		std::string paretoFrontFile;
		std::string phenotypeFile;

		long int randomSeed;
		int popSize;
		int chromLength;
		unsigned int maxgens;
		float px;
		float pm;
		float scaler;
		int lambda;
        Xover xover;
        Mutator mutator;
        Selector selector;

        int nCriteria;
        bool maximize;
        bool nsga;

	}Options;

}



#endif /* OPTIONS_H_ */
