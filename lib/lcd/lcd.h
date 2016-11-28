/*
 * panel.h
 *
 *  Created on: Oct 28, 2016
 *      Author: inkys_000
 */
#include "API.h"
#include "lcdcore.h"

#ifndef SRC_LCD_LCD_H_
#define SRC_LCD_LCD_H_

#define NULL_PTR 0
namespace lcd {

struct InitialLcd;

extern void lcdControl(void* initalCallback);
extern InitialLcd* generateInitial(FILE * port, MenuPanel * root);
extern Callback* menu(MenuPanel * root);


struct InitialLcd {
	Callback * InitialCallback;
	FILE * LCD;
};

}
#endif /* SRC_LCD_LCD_H_ */
