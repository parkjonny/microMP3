#include <avr/io.h> //
#include <util/delay.h> 
#include <stdio.h>
#include <avr/interrupt.h>
#include <math.h>
#include "adc.h"
#include "dotMatrix.h"
#include "lcd.h"
#include "led.h"
#include "music.h"
#define SEI() sei()
#define CLI() cli()

unsigned int sec = 0;

int a = 0;
int b = 0;
int c = 0;
int d = 0;

int keydata;
void port_init(void)
{ // void port_init() ??? ????
	PORTA = 0X00;
	DDRA = 0XFF;
	PORTB = 0x00;
	DDRB = 0X00;
	PORTC = 0X00;
	DDRC = 0X03;
	PORTD = 0X00;
	DDRD = 0X00;
	PORTE = 0X00;
	DDRE = 0X00;
	PORTF = 0X00;
	DDRF = 0X00;
	PORTG = 0X00;
	DDRG = 0X00;
	EX_SS_SEL = 0x0f;
} // void port_init()

void timer0_init(void)
{ // void time1_init()
	
	TCCR0 = 0x04;    //???????????(?????)=64          16000000(16MHz)/64/1000(1ms) = 250(250 ??????? 1ms)     
	TCNT0 = 0x06;    // 256 - 250 = 6

} 

void timer1_init(void)
{ // void time1_init()
	TCCR1B = 0x00;
	TCNT1H = 0xFD;			//TCNT1 ????(? ??? ????)
	TCNT1L = 0x66;
	TCCR1A = 0x00;
	TCCR1B = 0x02; // start timer  //????? 8
} 

ISR(TIMER0_OVF_vect)
{ // 
	TCNT0 = 0x06; //TCNT0 ???? 6???? ????
	sec++;
	if(sec >= 100)  //1ms ?????б└ея? 1000????? 1??
	{	
		if(isPlay == 1)
		{
			digit_num++;
			time_pass();
		}
		else
		{	nosound();
		}
		sec = 0;
	}
} //

SIGNAL(TIMER1_OVF_vect)
{ // SIGNAL(SIG_OVERFLOW1)
	TCNT1H = T1HIGHCNT;		//????? ??????? ????
	TCNT1L = T1LOWCNT;

	if(Soundonoff == ON)
	{
		PORTG = PORTG ^ 0x10;		//???G?? 4???? XOR ???????? ????? ????
	}

} // SIGNAL(SIG_OVERFLOW1)

void time_pass()
{
	if(digit_num % 10 == 0)
		d++;
	if(d==10)
	{
		c++;
		d = 0;
	}
	if(c==6)
	{
		b++;
		c = 0;
	}
	if(b==10)
	{
		a++;
		b = 0;
	}
}

void init_devices()
{ // void init_devices()
	cli(); // disable interrupt
	port_init();
	timer0_init();
	timer1_init();
	adc_init();
	lcdInit();
	lcdClear();
	nosound();

	MCUCR = 0X80;
	TIMSK = 0X05;

	sei(); // enable interrupt
} // void init_devices()

void checkButton()
{
	switch(keydata)
	{
	case 0x01:
		playMusic();
		break;

	case 0x02:
		pauseMusic();
		break;
	}
}
 
int main()
{	
	unsigned int adc_data;
	float voltage;

	init_devices();

	while(1)
	{
		keydata = (PINB & 0xff);
		checkButton();
		schoolsong();
		show_led(a, b, c, d);

		adc_startConversion();

		adc_data = adc_readData();

		voltage=(float)(5.*adc_data)/1024;
		voltage = ((voltage * playTime) / 4995) * 1000;
	
		lcd_gotoxy(10,2);
		lcd_putn3(voltage);

		for(int i = 0 ; i<1000;i++)
			runDotMatrix();
		
	}
}

