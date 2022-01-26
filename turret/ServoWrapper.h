/*
 * ServoWrapper.h
 *
 *  Created on: Jan 20, 2022
 *      Author: steve
 */
#ifndef SERVOWRAPPER_H_
#define SERVOWRAPPER_H_

class ServoWrapper {
	public:
		ServoWrapper(unsigned int pwmPin);
		void write(unsigned int targetAngle);
};



#endif /* SERVOWRAPPER_H_ */
