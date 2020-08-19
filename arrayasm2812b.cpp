#include "arrayasm2812b.h"



nBlock_ArrayAsm2812B::nBlock_ArrayAsm2812B(PinName MOSI, uint32_t numberLEDs):
	_led_array(MOSI, numberLEDs) {
	
	// Number of LEDs to be used
	num_leds = numberLEDs;
	
	// Reset flag
	must_update = 0;	
	
}


void nBlock_ArrayAsm2812B::triggerInput(nBlocks_Message message){
	// input 0 receives an array of bytes
	if (message.inputNumber == 0) {
		// Copy values to internal array
		uint8_t * source_values;
		source_values = ((uint8_t *)message.pointerValue);
		// Temp variable to hold 0xRRGGBB value
		uint8_t r;
		uint8_t g;
		uint8_t b;
		for (uint32_t i = 0; i < num_leds; i++) {
			r = source_values[i*3];
			g = source_values[(i*3) + 1];
			b = source_values[(i*3) + 2];
			_led_array.setPixel(i, r, g, b);
		}
		// Set flag so we update the LEDs at the end of frame
		must_update =  1;
	}
}

void nBlock_ArrayAsm2812B::endFrame(void){

	if (must_update) {
		must_update = 0;
		_led_array.write();
	}
	
	
}


