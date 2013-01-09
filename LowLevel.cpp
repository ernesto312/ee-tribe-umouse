#include "LowLevel.hpp"

#include <mbed.h>

#define INPUT 0
#define OUTPUT 1

#define NULL 0

volatile uint32_t *get_pinsel(const unsigned char& port, const unsigned char& pin)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINSEL0);
		} else {
			address = &(LPC_PINCON -> PINSEL1);
		}
		break;
	case 1:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINSEL2);
		} else {
			address = &(LPC_PINCON -> PINSEL3);
		}
		break;
	case 2:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINSEL4);
		} else {
			address = &(LPC_PINCON -> PINSEL5);
		}
		break;
	case 3:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINSEL6);
		} else {
			address = &(LPC_PINCON -> PINSEL7);
		}
		break;
	case 4:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINSEL8);
		} else {
			address = &(LPC_PINCON -> PINSEL9);
		}
		break;
	}
	return address;
}

volatile uint32_t *get_pinmode(const unsigned char& port, const unsigned char& pin)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINMODE0);
		} else {
			address = &(LPC_PINCON -> PINMODE1);
		}
		break;
	case 1:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINMODE2);
		} else {
			address = &(LPC_PINCON -> PINMODE3);
		}
		break;
	case 2:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINMODE4);
		} else {
			address = &(LPC_PINCON -> PINMODE5);
		}
		break;
	case 3:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINMODE6);
		} else {
			address = &(LPC_PINCON -> PINMODE7);
		}
		break;
	case 4:
		if (pin <= 15) {
			address = &(LPC_PINCON -> PINMODE8);
		} else {
			address = &(LPC_PINCON -> PINMODE9);
		}
		break;
	}
	return address;
}

volatile uint32_t *get_fiodir(const unsigned char& port)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		address = &(LPC_GPIO0 -> FIODIR);
		break;
	case 1:
		address = &(LPC_GPIO1 -> FIODIR);
		break;
	case 2:
		address = &(LPC_GPIO2 -> FIODIR);
		break;
	case 3:
		address = &(LPC_GPIO3 -> FIODIR);
		break;
	case 4:
		address = &(LPC_GPIO4 -> FIODIR);
		break;
	}
	return address;
}

volatile uint32_t *get_fioset(const unsigned char& port)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		address = &(LPC_GPIO0 -> FIOSET);
		break;
	case 1:
		address = &(LPC_GPIO1 -> FIOSET);
		break;
	case 2:
		address = &(LPC_GPIO2 -> FIOSET);
		break;
	case 3:
		address = &(LPC_GPIO3 -> FIOSET);
		break;
	case 4:
		address = &(LPC_GPIO4 -> FIOSET);
		break;
	}
	return address;
}

volatile uint32_t *get_fioclr(const unsigned char& port)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		address = &(LPC_GPIO0 -> FIOCLR);
		break;
	case 1:
		address = &(LPC_GPIO1 -> FIOCLR);
		break;
	case 2:
		address = &(LPC_GPIO2 -> FIOCLR);
		break;
	case 3:
		address = &(LPC_GPIO3 -> FIOCLR);
		break;
	case 4:
		address = &(LPC_GPIO4 -> FIOCLR);
		break;
	}
	return address;
}

volatile uint32_t *get_fiopin(const unsigned char& port)
{
	volatile uint32_t *address = NULL;
	switch (port) {
	case 0:
		address = &(LPC_GPIO0 -> FIOPIN);
		break;
	case 1:
		address = &(LPC_GPIO1 -> FIOPIN);
		break;
	case 2:
		address = &(LPC_GPIO2 -> FIOPIN);
		break;
	case 3:
		address = &(LPC_GPIO3 -> FIOPIN);
		break;
	case 4:
		address = &(LPC_GPIO4 -> FIOPIN);
		break;
	}
	return address;
}

void gpio(const unsigned char& port, const unsigned char& pin)
{
	*get_pinsel(port, pin) &= ~((1 << ((pin * 2) + 1)) | (1 << (pin * 2)));
	return;
}

void io(const unsigned char& port, const unsigned char& pin, const bool & mode)
{
	switch (mode) {
	case INPUT:
		*get_fiodir(port) &= ~(1 << pin);
		break;
	case OUTPUT:
		*get_fiodir(port) |= (1 << pin);
		break;
	}
	return;
}