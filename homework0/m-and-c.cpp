#include <iostream>

bool crossRiver(int actionsList[][3], int state[3]);
bool isValidState(int state[3]);

int main() {
	// actions list is all of the actions that can be applied to the state
	// actions that go nowhere (such as returning both passengers to a side that just left) are excluded
	int actionsList[6][3] = {{-2, 0, -1}, {-1, -1, -1}, {0, -2, -1}, {1, 0, 1}, {0, 1, 1}};
	// the state is a representation of the number of missionaries and cannibals on the left side
	// of the river, and wiether the boat is on the left or the right side
	// [#missionaries, #cannibals, bool->boat on left side = 1, right = 0]
	int startingState[3] = {3, 3, 1};

	crossRiver(actionsList, startingState);

	return 0;
}

bool crossRiver(int actionsList[][3], int state[3]) {
	// check if state is a "losing" state, or one that is impossible
	if (isValidState(state)){
		// std::cout << "state is valid!" << std::endl;
		// std::cout << "<" << state[0] << "," << state[1] << "," << state[2] << ">" << std::endl;
		// check if end condition reached
		if (state[0] == 0 && state[1] == 0 && state[2] == 0) {
			std::cout << "<" << state[0] << "," << state[1] << "," << state[2] << ">" << std::endl;
			return true;
		}
		// if not take actions on the state and call again
		else{
			int nextState[3];
			// apply each action in a depth first search fashion
			for (int i = 0; i < 6; i++){
				nextState[0] = state[0] + actionsList[i][0];
				nextState[1] = state[1] + actionsList[i][1];
				nextState[2] = state[2] + actionsList[i][2];
				if (crossRiver(actionsList, nextState) == true){
					std::cout << "action:" << "<" << actionsList[i][0] << "," << actionsList[i][1] << "," << actionsList[i][2] << ">" << std::endl;
					std::cout << "<" << state[0] << "," << state[1] << "," << state[2] << ">" << std::endl;
					return true;
					// otherwise continue with the loop
				}
			}
		}
	}

	else {
		return false;
	}
}

bool isValidState(int state[3]){
	// first check if state is possible
	// actions are applied indescriminately so impossible states will happen
	if (state[0] >= 0 && state[1] >= 0 && state[2] >= 0 && state[0] <= 3 && state[1] <= 3 && state[2] <= 1) {
		// then check if state is a losing state
		// if there are too many cannibals on the left
		if (state[0] != 0) {
			if (state[2] == 0 && (state[1] > state[0])) {
			//if ((state[0] < state[1])) {
				return false;
			}
		}
		// or if there are too many cannibals on the right
		if (state[2] == 1 && state[1] != 0) {
		//if (state[1] != 0) { 
			if (state[0] > state[1]){
				return false;
			}
		}
		// if neither of these conditions are true, the state is valid! 
		else {
			return true;
		}
	}
	else{
		return false;
	}
}