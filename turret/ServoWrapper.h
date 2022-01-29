/*
 * ServoWrapper.h
 *
 *  Created on: Jan 20, 2022
 *      Author: steve
 */

#ifndef SERVOWRAPPER_H_
#define SERVOWRAPPER_H_

#ifdef FAKE
#include "Servo.h"
#else
#include <Servo.h>
#endif

class ServoWrapper {
	public:
		ServoWrapper(unsigned int pwmPin);
		void write(unsigned int targetAngle);
   private:
     Servo* servo;
};



#endif /* SERVOWRAPPER_H_ */
