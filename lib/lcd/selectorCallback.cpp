/*
 * selectorCallback.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: inkys_000
 */
#include "lcd.h"

namespace lcd {
SelectorCallback::SelectorCallback(int * integer, FILE* output) : Integer(integer), Output(output) {

}

SelectorCallback::~SelectorCallback() {
	delete this;
}

void SelectorCallback::Evaluate(int selector) {
	printf("SELECTED %d\n", selector);
	lcdPrint(this->Output, 1, "Selected %d", selector);
	taskDelay(2000);
	*this->Integer = selector;
	this->Released = true;
}
}
