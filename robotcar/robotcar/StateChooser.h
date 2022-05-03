#ifndef STATECHOOSER_H_
#define STATECHOOSER_H_

class StateChooser {
	public:
		State choose(State currentState, int inchesClearAhead);
		State choose(State currentState, int inchesClearAhead, int inchesClearLeft, int inchesClearRight);
	private:
		const int obstacleSafeDistanceInches = 8;
		const int startSignalDistanceInches = 2;
};

#endif
