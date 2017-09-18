#include <iostream>

bool isValidState(int state[3]);

int main(int argc, char const *argv[]) {
	int check[3] = {0,1,0};
	isValidState(check);
	return 0;
}

bool isValidState(int state[3]){
	// first check if state is possible
	// actions are applied indescriminately so impossible states will happen
	if (state[0] >= 0 && state[1] >= 0 && state[2] >= 0 && state[0] < 4 && state[1] < 4 && state[2] <= 1) {
		// then check if state is a losing state
		// if there are too many cannibals on the left
		if (state[0] != 0) {
			if (state[2] == 0 && (state[1] > state[0])) {
				std::cout << "nope1" << std::endl;
			}
		}
		// or if there are too many cannibals on the right
		// else if (state[2] == 1 && state[0] > state[1]){
		// 	return false;
		// }
		// if neither of these conditions are true, the state is valid! 
		else {
			std::cout << "its good" << std::endl;
		}
	}
	else{
		std::cout << "nope2" << std::endl;
	}
}