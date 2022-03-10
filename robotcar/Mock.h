#ifndef MOCK_H_
#define MOCK_H_

#ifdef FAKE
#define LED_BUILTIN 0
#define HIGH 1
#define LOW 0
void delay(unsigned int milliseconds) {}
void digitalWrite(unsigned int pin, unsigned int level) {}
#endif

#endif
