#include <mbed.h>

// Implement set_bit? With 2 bits?

volatile uint32_t *get_pinsel(const unsigned char&, const unsigned char&);

volatile uint32_t *get_pinmode(const unsigned char&, const unsigned char&);

volatile uint32_t *get_fiodir(const unsigned char&);

volatile uint32_t *get_fioset(const unsigned char&);

volatile uint32_t *get_fioclr(const unsigned char&);

volatile uint32_t *get_fiopin(const unsigned char&);

void gpio(const unsigned char&, const unsigned char&);

void io(const unsigned char&, const unsigned char&, const bool&);