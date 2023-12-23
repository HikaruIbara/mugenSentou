#include "XorShift32.h"
#include <stdio.h>
#include <stdint.h>
#include "XorShift32.h"

using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;

uint32_t state = 4087532457;

bool init = false;

void initXshit()
{
	//Œ»İ‚ÌŠÔ‚ğæ“¾‚µ‚Ä—”‚Ìí‚ğ¶¬
	state = (uint32_t)duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
}

uint32_t xorshift32()
{
	uint32_t x = state;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	state = x;
	return x;
}
