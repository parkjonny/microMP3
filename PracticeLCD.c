#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"

#define EX_LCD_DATA (*(volatile unsigned char*)0x8000)
#define EX_LCD_CONTROL (*(volatile unsigned char*)0x8001)

#define  SEI() sei()
#define CLI() cli()


void port_init(void)
{
	PORTA=0x00;
	DDRA=0xFF;
	PORTB=0x00;
	DDRB=0x00;
	PORTC=0x00;
	DDRC=0xFF;
	PORTD=0x00;
	DDRD=0xFF;
	PORTE=0x00;
	DDRE=0x00;
	PORTF=0x00;
	DDRF=0x00;
	PORTG=0x00;
	DDRG=0xFF;

}



void init_devices(void)
{ CLI();
port_init();
MCUCR=0x80;
SEI();
}

int main(void)
{
	int hour = 10;
	int minute = 0;
	int second = 0;
char i, count=0;
init_devices();
_delay_ms(1000);
lcdInit();
lcdClear();
lcd_puts(1,"baby shark");
while(1)
{
	count++;
	second = count;
	if(second == 59)
	{
		minute++;
		count = -1;
	}
	lcd_gotoxy(1,2);
	lcd_putn2(hour);
	lcd_gotoxy(3, 2);
	lcd_putss(":");
	lcd_gotoxy(4, 2);
	lcd_putn2(minute);
	lcd_gotoxy(6, 2);
	lcd_putss(":");
	lcd_gotoxy(7, 2);
	lcd_putn2(second);
	_delay_ms(100);
}
return 0;
}
