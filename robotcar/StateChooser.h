#ifndef STATECHOOSER_H_
#define STATECHOOSER_H_

class StateChooser {
	public:
		State choose(State currentState, int inchesClearAhead);
		State choose(State currentState, int inchesClearAhead, int inchesClearLeft, int inchesClearRight);
};

#endif
