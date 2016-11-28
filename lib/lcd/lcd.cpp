/*
 * lcd.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: inkys_000
 */
#include "lcd.h"

namespace lcd {

void lcdControl(void* initialCallback) {
	InitialLcd * i = (InitialLcd*) initialCallback;
	Callback * c = i->InitialCallback;
	c->Evaluate(0);
	printf("[DEBUG] Started the LCD Control\n");
	while (true) {
		delay(250);
		int button = lcdReadButtons(i->LCD);
		if (button == 0)
			continue;
		c->Evaluate(button);
		if (c->IsReleased())
			break;
	}
	printf("[DEBUG] Exiting LCD Control\n");
	lcdClear(i->LCD);
	lcdSetText(i->LCD, 1, "Finished printing");
}

InitialLcd* generateInitial(FILE * port, MenuPanel * root) {
	printf("Created initial\n");
	InitialLcd * initial = new InitialLcd();
	initial->LCD = port;
	initial->InitialCallback = menu(root);
	return initial;
}

Callback * menu(MenuPanel * panel) {
	return new NavigateCallback(panel);
}

}
