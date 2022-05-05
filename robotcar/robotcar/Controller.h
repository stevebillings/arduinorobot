/*
 * Controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum Direction {left, straight, right, none};

class Controller {
	public:
    		Controller(const Turret& turret, const Drive& drive, const Pinger& pinger) :turret{turret}, drive{drive}, pinger{pinger} {}
		const State setup() const;
		const State loop(State state) const;
	private:
		const Turret& turret;
		const Drive& drive;
		const Pinger& pinger;
};

#endif /* CONTROLLER_H_ */
