#include <mbed.h>
#include "mbed-level.hpp"

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

#define PULL_UP 0
#define REPEATER 1
#define TRISTATE 2
#define PULL_DOWN 3

int main()
{
	pwm(26);
	pwm_write(26, 50);
	while (1) {
	}
	return 0;
}