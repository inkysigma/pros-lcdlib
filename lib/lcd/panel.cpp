/*
 * panel.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: inkys_000
 */

#include "lcd.h"

namespace lcd {

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		FILE* uart) {
	this->FirstLine = firstLine;
	this->SecondLine = secondLine;
	this->FirstCallback = NULL_PTR;
	this->SecondCallback = NULL_PTR;
	this->ThirdCallback = NULL_PTR;
	this->FourthCallback = NULL_PTR;
	this->FifthCallback = NULL_PTR;
	this->SixthCallback = NULL_PTR;
	this->Passdown = 0;
	this->Uart = uart;
}

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback, FILE* uart) {
	this->FirstLine = firstLine;
	this->SecondLine = secondLine;
	this->FirstCallback = firstCallback;
	this->SecondCallback = NULL_PTR;
	this->ThirdCallback = NULL_PTR;
	this->FourthCallback = NULL_PTR;
	this->FifthCallback = NULL_PTR;
	this->SixthCallback = NULL_PTR;
	this->Passdown = 0;
	this->Uart = uart;
}

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback,
		Callback * secondCallback,
		FILE* uart) {
	// TODO Auto-generated constructor stub
	this->FirstLine = firstLine;
	this->SecondLine = secondLine;
	this->FirstCallback = firstCallback;
	this->SecondCallback = secondCallback;
	this->ThirdCallback = NULL_PTR;
	this->FourthCallback = NULL_PTR;
	this->FifthCallback = NULL_PTR;
	this->SixthCallback = NULL_PTR;
	this->Passdown = 0;
	this->Uart = uart;
}

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback,
		Callback * secondCallback,
		Callback * thirdCallback,
		FILE* uart) {
	this->FirstLine = firstLine;
	this->SecondLine = secondLine;
	this->FirstCallback = firstCallback;
	this->SecondCallback = secondCallback;
	this->ThirdCallback = thirdCallback;
	this->FourthCallback = NULL_PTR;
	this->FifthCallback = NULL_PTR;
	this->SixthCallback = NULL_PTR;
	this->Passdown = 0;
	this->Uart = uart;
}

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback,
		Callback * secondCallback,
		Callback * thirdCallback,
		Callback * fourthCallback,
		FILE * uart) : FirstLine(firstLine), SecondLine(secondLine),
		FirstCallback(firstCallback), SecondCallback(secondCallback),
		ThirdCallback(thirdCallback), FourthCallback(fourthCallback),
		FifthCallback(NULL_PTR), SixthCallback(NULL_PTR), Uart(uart) { }
		
MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback,
		Callback * secondCallback,
		Callback * thirdCallback,
		Callback * fourthCallback,
		Callback * fifthCallback,
		FILE * uart) : FirstLine(firstLine), SecondLine(secondLine),
		FirstCallback(firstCallback), SecondCallback(secondCallback),
		ThirdCallback(thirdCallback), FourthCallback(fourthCallback),
		FifthCallback(fifthCallback), SixthCallback(NULL_PTR), Uart(uart) { }

MenuPanel::MenuPanel(const char * firstLine, const char * secondLine,
		Callback * firstCallback,
		Callback * secondCallback,
		Callback * thirdCallback,
		Callback * fourthCallback,
		Callback * fifthCallback,
		Callback * sixthCallback,
		FILE * uart) : FirstLine(firstLine), SecondLine(secondLine),
		FirstCallback(firstCallback), SecondCallback(secondCallback),
		ThirdCallback(thirdCallback), FourthCallback(fourthCallback),
		FifthCallback(fifthCallback), SixthCallback(sixthCallback), Uart(uart) { }

MenuPanel::~MenuPanel() {
	delete this->FirstLine;
	delete this->SecondLine;
	delete this->FirstCallback;
	delete this->SecondCallback;
	delete this->ThirdCallback;
	delete this;
}

bool MenuPanel::IsPassingDown() {
	return this->Passdown != 0;
}

void MenuPanel::Render() {
	lcdSetText(this->Uart, 1, this->FirstLine);
	lcdSetText(this->Uart, 2, this->SecondLine);
}

void MenuPanel::Evaluate(int selector) {
	printf("%s : %s is %d\n", this->FirstLine, this->SecondLine, selector);
	if (this->Passdown == 0) {
		Render();
	}
	if ((this->Passdown == 1 || selector == LCD_BTN_LEFT) && FirstCallback != NULL_PTR) {
		Passdown = 1;
		this->FirstCallback->Evaluate(selector);
		if (this->FirstCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
	else if ((this->Passdown == 2 || selector == LCD_BTN_CENTER) && SecondCallback != NULL_PTR)
	{
		Passdown = 2;
		this->SecondCallback->Evaluate(selector);
		if (this->SecondCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
	else if ((this->Passdown == 3 || selector == LCD_BTN_RIGHT) && ThirdCallback != NULL_PTR) {
		Passdown = 3;
		this->ThirdCallback->Evaluate(selector);
		if (this->ThirdCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
	else if ((this->Passdown == 4 || selector == LCD_BTN_LEFT | LCD_BTN_CENTER) && FourthCallback != NULL_PTR) {
		Passdown = 4;
		this->FourthCallback->Evaluate(selector);
		if (this->FourthCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
	else if ((this->Passdown == 5 || selector == LCD_BTN_CENTER | LCD_BTN_RIGHT) && FifthCallback != NULL_PTR) {
		Passdown = 5;
		this->FifthCallback->Evaluate(selector);
		if (this->FifthCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
	else if ((this->Passdown == 6 || selector == LCD_BTN_LEFT | LCD_BTN_CENTER | LCD_BTN_RIGHT) && SixthCallback != NULL_PTR) {
		Passdown = 6;
		this->SixthCallback->Evaluate(selector);
		if (this->SixthCallback->IsReleased()) {
			Passdown = 0;
			Render();
		}
	}
}

}
