#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct State{
	State* previous;
	int missionaries;
	int cannibals;
	int boat;
};

queue <State*> stateSpace;

State* search(int actionsList[][3]);
bool isValidState(State state);

// create action list and starting state
// been coding in python for so long c++ feels awkwardly foreign
int main(int argc, char const *argv[])
{
	//this is just here to make the compiler happy, actionsList is declared in all instances
	int actionsList[8][3];
	if (atoi(argv[1]) == 2){
		int actionsList[8][3] = {{-2, 0, -1}, {0, -2, -1}, {-1, -1, -1}, {1, 1, 1}, {1, 0, 1}, {0, 1, 1}, {2, 0, 1}, {0, 2, 1}};
	}
	else if (atoi(argv[1]) == 3){
		int actionsList[15][3] = {{-3, 0, -1}, {-2, -1, -1}, {-2, 0, -1}, {-1, -1, -1}, {0, -2, -1}, {-1, -2, -1}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}, {2, 0, 1}, {0, 2, 1}, {2, 1, 1}, {1, 2, 1}, {3,0,1}, {0,3,1}};
	}
	else{
		cout << "Please input how many can fit on a boat: 2 or 3" << endl;
		return 0;
	}
	State* initState = new State;
	initState->previous = NULL;
	initState->missionaries = 3;
	initState->cannibals = 3;
	initState->boat = 1;
	State* lastState;

	stateSpace.push(initState);

	lastState = search(actionsList);


	while (lastState->previous != NULL){
		cout << "<" << lastState->missionaries << "," << lastState->cannibals << "," << lastState->boat << ">" << endl;
		lastState = lastState->previous;
	}
	cout << "<" << initState->missionaries << "," << initState->cannibals << "," << initState->boat << ">" << endl;


	return 0;
}

State* search(int actionsList[][3]){
	State* state = stateSpace.front();
	stateSpace.pop();

	if (state->missionaries == 0 && state->cannibals == 0){
		//cout << "<" << state->missionaries << "," << state->cannibals << "," << state->boat << ">" << endl;
		cout << "solution reached" << endl;
		return state;
	}
	else{
		for (int i = 0; i < 8; i++){
			State* next = new State;
			next->missionaries = state->missionaries + actionsList[i][0];
			next->cannibals = state->cannibals + actionsList[i][1];
			next->boat = state->boat + actionsList[i][2];
			next->previous = state;

			if (isValidState(*next)){
				stateSpace.push(next);
			}
		}
		//cout << "<" << state.missionaries << "," << state.cannibals << "," << state.boat << ">" << endl;
		return search(actionsList);
	}
}

bool isValidState(State state){
	// first check if state can exist or not
	// valid number of missionaries, cannibals, and boat
	if (state.missionaries > 3 || state.missionaries < 0 || state.cannibals > 3 || state.cannibals < 0 || state.boat > 1 || state.boat < 0){
		return false;
	}
	// check that there are more missionaries than cannibals on either side and return true
	if (state.missionaries == 3 || state.missionaries == 0){
		return true;
	}
	if (state.missionaries >= state.cannibals){
		return true;
	}
	// if (state.boat == 1 && state.missionaries >= state.cannibals){
	// 	return false;
	// }
	// otherwise the game is in a losing state
	else {
		return false;
	}
}