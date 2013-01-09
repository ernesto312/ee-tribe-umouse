#include "mbed-level.hpp"

#include <mbed.h>
#include "arm-level.hpp"

unsigned char get_port(const unsigned char& mbed_pin)
{
	unsigned char port;
	switch (mbed_pin) {
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		port = 0;
		break;
	case 19:
	case 20:
		port = 1;
		break;
	case 21:
	case 22:
	case 23:
	case 24:
	case 25:
	case 26:
		port = 2;
		break;
	case 27:
	case 28:
	case 29:
	case 30:
		port = 0;
		break;
	}
	return port;
}

unsigned char get_pin(const unsigned char& mbed_pin)
{
	unsigned char pin;
	switch (mbed_pin) {
	case 5:
		pin = 9;
		break;
	case 6:
		pin = 8;
		break;
	case 7:
		pin = 7;
		break;
	case 8:
		pin = 6;
		break;
	case 9:
		pin = 0;
		break;
	case 10:
		pin = 1;
		break;
	case 11:
		pin = 18;
		break;
	case 12:
		pin = 17;
		break;
	case 13:
		pin = 15;
		break;
	case 14:
		pin = 16;
		break;
	case 15:
		pin = 23;
		break;
	case 16:
		pin = 24;
		break;
	case 17:
		pin = 25;
		break;
	case 18:
		pin = 26;
		break;
	case 19:
		pin = 30;
		break;
	case 20:
		pin = 31;
		break;
	case 21:
		pin = 5;
		break;
	case 22:
		pin = 4;
		break;
	case 23:
		pin = 3;
		break;
	case 24:
		pin = 2;
		break;
	case 25:
		pin = 1;
		break;
	case 26:
		pin = 0;
		break;
	case 27:
		pin = 11;
		break;
	case 28:
		pin = 10;
		break;
	case 29:
		pin = 5;
		break;
	case 30:
		pin = 4;
		break;
	}
	return pin;
}

void resistor(const unsigned char& mbed_pin, const unsigned char& mode)
{
	resistor(get_port(mbed_pin), get_pin(mbed_pin), mode);
	return;
}

void pin_mode(const unsigned char& mbed_pin, const bool& mode)
{
	pin_mode(get_port(mbed_pin), get_pin(mbed_pin), mode);
	return;
}

void digital_write(const unsigned char& mbed_pin, const bool& mode)
{
	digital_write(get_port(mbed_pin), get_pin(mbed_pin), mode);
	return;
}

bool digital_read(const unsigned char& mbed_pin)
{
	return digital_read(get_port(mbed_pin), get_pin(mbed_pin));
}

void pwm(const unsigned char& mbed_pin)
{
	pwm (get_port(mbed_pin), get_pin(mbed_pin));
	return;
}

void pwm_write(const unsigned char& mbed_pin, const unsigned char& duty)
{
	switch (-mbed_pin + 27) {
	case 1:
		LPC_PWM1 -> MR0 = 100;
		LPC_PWM1 -> MCR |= 1 << 1;
		LPC_PWM1 -> MR1 = duty;
		LPC_PWM1 -> TCR |= (1 << 0) | (1 << 3);
		LPC_PWM1 -> PCR = 1 << 9;
	}
}