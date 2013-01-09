#include "arm-level.hpp"

#include <mbed.h>
#include "low-level.hpp"

#define PULL_UP 0
#define REPEATER 1
#define TRISTATE 2
#define PULL_DOWN 3

#define HIGH 1
#define LOW 0

void resistor(const unsigned char& port, const unsigned char& pin, const unsigned char& mode)
{
	switch (mode) {
	case PULL_UP:
		if (pin <= 15) {
			*get_pinmode(port, pin) &= ~((1 << ((pin * 2) + 1)) | (1 << (pin * 2)));
		} else {
			*get_pinmode(port, pin) &= ~((1 << ((pin * 2) + 1)) | (1 << (pin * 2)));
		}
		break;
	case REPEATER:
		if (pin <= 15) {
			*get_pinmode(port, pin) &= ~(1 << ((pin * 2) + 1));
			*get_pinmode(port, pin) |= (1 << (pin * 2));
		} else {
			*get_pinmode(port, pin) &= ~(1 << ((pin * 2) + 1));
			*get_pinmode(port, pin) |= (1 << (pin * 2));
		}
		break;
	case TRISTATE:
		if (pin <= 15) {
			*get_pinmode(port, pin) |= (1 << ((pin * 2) + 1));
			*get_pinmode(port, pin) &= ~(1 << (pin * 2));
		} else {
			*get_pinmode(port, pin) |= (1 << ((pin * 2) + 1));
			*get_pinmode(port, pin) &= ~(1 << (pin * 2));
		}
		break;
	case PULL_DOWN:
		if (pin <= 15) {
			*get_pinmode(port, pin) |= ((1 << ((pin * 2) + 1)) | (1 << (pin * 2)));
		} else {
			*get_pinmode(port, pin) |= ((1 << ((pin * 2) + 1)) | (1 << (pin * 2)));
		}
		break;
	}
	return;
}

void pin_mode(const unsigned char& port, const unsigned char& pin, const bool& mode)
{
	gpio(port, pin);
	io(port, pin, mode);
	return;
}

void digital_write(const unsigned char& port, const unsigned char& pin, const bool& mode)
{
	switch (mode) {
	case LOW:
		*get_fioclr(port) |= (1 << pin);
		break;
	case HIGH:
		*get_fioset(port) |= (1 << pin);
		break;
	}
	return;
}

bool digital_read(const unsigned char& port, const unsigned char& pin)
{
	bool value;
	if (pin <= 15) {
		value = ((*get_fiopin(port)) & (1 << pin)) >> pin;
	} else {
		value = ((*get_fiopin(port)) & (1 << (pin - 15))) >> (pin - 15);
	}
	return value;
}

void pwm(const unsigned char& port, const unsigned char& pin)
{
	*get_pinsel(port, pin) &= ~(1 << ((pin * 2) + 1));
	*get_pinsel(port, pin) |= (1 << (pin * 2));
	resistor(port, pin, TRISTATE);
	return;
}