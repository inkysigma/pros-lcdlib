/*
 * voidCallback.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: inkys_000
 */
#include "lcd.h"

namespace lcd {
VoidCallback::VoidCallback(void (*func)(int)) : Function(func) { }

VoidCallback::~VoidCallback() {
	delete this;
}

void VoidCallback::Evaluate(int selection) {
	Function(selection);
}
}



