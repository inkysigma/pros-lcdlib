/*
 * callback.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: inkys_000
 */
#include "lcd.h"
namespace lcd {

NavigateCallback::NavigateCallback(MenuPanel * panel){
	this->NavigatePanel = panel;
	this->Released = true;
	this->Initial = true;
}

NavigateCallback::~NavigateCallback() {
	delete this->NavigatePanel;
	delete this;
}

void NavigateCallback::Evaluate(int selection) {
	if (this->Initial) {
		this->Released = false;
		this->Initial = false;
		this->NavigatePanel->Evaluate(0);
		return;
	}
	if (selection == LCD_BTN_RIGHT && !NavigatePanel->IsPassingDown()) {
		printf("Released\n");
		this->Released = true;
		this->Initial = true;
		return;
	}
	this->NavigatePanel->Evaluate(selection);
}
}
