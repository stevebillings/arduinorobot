#ifndef STATECHOOSER_H_
#define STATECHOOSER_H_

class StateChooser {
	public:
		const State choose(const State currentState, const int inchesClearAhead) const;
		const State choose(const State currentState, const int inchesClearAhead, const int inchesClearLeft, const int inchesClearRight) const;
	private:
		static const int obstacleSafeDistanceInches = 8;
		static const int startSignalDistanceInches = 2;
};

#endif
