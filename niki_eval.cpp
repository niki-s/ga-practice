double eval(int* pj){
	// determine value of input bit string based on locations of ones and zeros
	//  min value == 0, max value == 100
	// if all of the odd numbered bit locations == 1, then give maximum value

	int sumOdds = 0;

	for (int i = 0; i < 100; i++) {
		if (i % 2 == 1) {
			sumOdds += pj[i];
		}
	}

	if (sumOdds == 50){
		return 100.;
	}
	else if (sumOdds >= 45 && sumOdds < 50){
		return 75
	}
	else if (sumOdds < 45 && sumOdds >=25){
		return 50.;
	}
	if (sumOdds < 25){
		return 10.;
	}
}