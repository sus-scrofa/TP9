#pragma once

#define PORT_P0 0
#define PORT_P1 1

#define LCD_E (1 << PORT_P0)
#define LCD_E_ON LCD_E
#define LCD_E_OFF (LCD_E ^ LCD_E)

#define LCD_RS (1 << PORT_P1)
#define LCD_RS_DR LCD_RS
#define LCD_RS_IR (LCD_RS ^ LCD_RS)

#define LCD_CLEAR	       0b1	//clear display
#define LCD_RETURN	      0b10	//return home
#define LCD_ENTSET	     0b100	//Entry mode set
#define LCD_CONTROL	    0b1000	//Display on/off control
#define LCD_SHIFT	   0b10000	//Cursor or display shift
#define LCD_FUNCSET	  0b100000	//Funtion set
#define LCD_SETCGR	 0b1000000	//Set CGRAM address
#define LCD_SETDDR	0b10000000	//Set DDRAM address

