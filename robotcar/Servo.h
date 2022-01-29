/*
 * Servo.h
 *
 *  Created on: Jan 28, 2022
 *      Author: steve
 */

#ifndef SERVO_H_
#define SERVO_H_

class Servo {
	public:
		void attach(unsigned int pin);
		void write(unsigned int angle);
};

#endif /* SERVO_H_ */
