#ifndef __NB_ARRAYASM2812B
#define __NB_ARRAYASM2812B

#include "nworkbench.h"
#include "NeoStrip/NeoStrip.h"

class nBlock_ArrayAsm2812B: public nBlockSimpleNode<1> {
public:

    nBlock_ArrayAsm2812B(PinName MOSI, uint32_t numberLEDs);
    void triggerInput(nBlocks_Message message);
	void endFrame();
	
   
private:
	
    // The pixel array control class.
    NeoStrip _led_array;

	uint32_t num_leds;
	uint32_t must_update = 0;
};

#endif