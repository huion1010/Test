#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
	public:
		LedToggle(int pin);
		LedToggle(int pin, unsigned long delayTime);
		void toggle();
		unsigned long delayTime;

	private:
		int _pin;
		bool _state;
};

#endif
