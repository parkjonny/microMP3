#include <avr/io.h> //
#include <util/delay.h> 
#include <stdio.h>
#include <avr/interrupt.h>
#include <math.h>
#include "lcd.h"

#define SEI() sei()
#define CLI() cli()

#define EX_SS_DATA			(*(volatile unsigned char *)0x8002)
#define EX_SS_SEL			(*(volatile unsigned char *)0x8003)
#define EX_DM_SEL			(*(volatile unsigned char *)0x8004)
#define EX_DM_DATA			(*(volatile unsigned char *)0x8006)
#define EX_LED				(*(volatile unsigned char *)0x8008)

#define ON 1
#define OFF 2

#define C1 523
#define C1_ 554
#define D1 587
#define D1_ 622
#define E1 659		//미
#define F1 699		//파
#define F1_ 740
#define G1 784		//솔
#define G1_ 831
#define A1 880		//라
#define A1_ 932
#define B1 988		//시

#define C2 C1 * 2
#define C2_ C1_ * 2
#define D2 D1 * 2
#define D2 D1_ * 2
#define E2 E1 * 2
#define F2 F1 * 2
#define F2_ F1_ * 2
#define G2 G1 * 2
#define G2_ G1_ * 2
#define A2 A1 * 2
#define A2_ A1_ * 2
#define B2 B2 * 2

#define DLY_1 DLY_4 * 4
#define DLY_2 DLY_4 * 2
#define DLY_4 400
#define DLY_8 DLY_4 / 2
#define DLY_16 DLY_8 / 2

volatile long T1HIGHCNT = 0xFD, T1LOWCNT = 0x86;
volatile int Soundonoff = ON;

unsigned int digit_num = 0;
unsigned int sec = 0;
unsigned char segment_data[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char display_num[4] = {0xfe, 0xfd, 0xfb, 0xf7};

int a = 0;
int b = 0;
int c = 0;
int d = 0;

int keydata;
int isPlay = 0;	//0 : pause , 1 : play
int beatType = 0; //0: nosound, 1: lowsound, 2: highsound
int dm_data1[10] = {0x000, 0x000, 0x000, 0x000, 0x030, 0x030, 0x000, 0x000, 0x000, 0x000};
int dm_data2[10] = {0x000, 0x000, 0x078, 0x084, 0x0B4, 0x0B4, 0x084, 0x078, 0x000, 0x000};
int dm_data3[10] = {0x0FC, 0x102, 0x279, 0x285, 0x2B5, 0x2B5, 0x285, 0x279, 0x102, 0x0FC};
int dmi = 0;

//곡 정보
int playTime = 0;
char songName[10];
char artistName[10];

void runDotMatrix(void)
{
		EX_DM_SEL = 0;
		if(beatType == 0)
			EX_DM_DATA = dm_data1[dmi];
		else if(beatType == 1)
			EX_DM_DATA = dm_data2[dmi];
		else
			EX_DM_DATA = dm_data3[dmi];
		EX_DM_SEL = 1<<dmi;
		dmi++;
		if(dmi>9) dmi = 0;
}

void port_init(void)
{ // void port_init() 포트 초기화
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
	
	TCCR0 = 0x04;    //프리스케일러(분주비)=64          16000000(16MHz)/64/1000(1ms) = 250(250 클럭마다 1ms)     
	TCNT0 = 0x06;    // 256 - 250 = 6

} 

void timer1_init(void)
{ // void time1_init()
	TCCR1B = 0x00;
	TCNT1H = 0xFD;			//TCNT1 초기화(큰 의미 없음)
	TCNT1L = 0x66;
	TCCR1A = 0x00;
	TCCR1B = 0x02; // start timer  //분주비 8
} 

ISR(TIMER0_OVF_vect)
{ // 
	TCNT0 = 0x06; //TCNT0 값을 6으로 초기화
	sec++;
	if(sec >= 100)  //1ms 오버플로우 1000번이면 1초
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
	TCNT1H = T1HIGHCNT;		//원하는 주파수로 셋팅
	TCNT1L = T1LOWCNT;

	if(Soundonoff == ON)
	{
		PORTG = PORTG ^ 0x10;		//포트G의 4번핀 XOR 연산으로 주파수 생성
	}

} // SIGNAL(SIG_OVERFLOW1)

void show_led(int a, int b, int c, int d)
{
	
	EX_SS_SEL = display_num[0];
	EX_SS_DATA = segment_data[a];
	_delay_ms(5);
	EX_SS_SEL = display_num[1];
	EX_SS_DATA = segment_data[b];
	_delay_ms(5);
	EX_SS_SEL = display_num[2];
	EX_SS_DATA = segment_data[c];
	_delay_ms(5);
	EX_SS_SEL = display_num[3];
	EX_SS_DATA = segment_data[d];
	_delay_ms(5);
}

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
	MCUCR = 0X80;
	TIMSK = 0X05;

	sei(); // enable interrupt
} // void init_devices()

void sound(int freq)
{
	Soundonoff = ON;
	
	T1HIGHCNT = (0xFFFF - floor(2000000/freq)) / 0x100;	
	T1LOWCNT = 0xFFFF - floor(2000000/freq) - 0xFF00;

	if(freq < 1000)
		beatType = 1;
	else
		beatType = 2;
}


void nosound(void)
{
	Soundonoff = OFF;
	beatType = 0;
}

void schoolsong(void)
{
	songName[10] = "School Bell Ring";
	artistName[10] = "Unknown";

	playTime = 9;
	if(isPlay == 1)
	switch(digit_num)
	{
		case 1:
			sound(G1);
			break;
		case 5:
			nosound();
			break;
		case 6:
			sound(G1);
			break;
		case 10:
			nosound();
			break;
		case 11:
			sound(A1);
			break;
		case 15:	
			nosound();
			break;
		case 16:
			sound(A1);
			break;
		case 20:
			nosound();
			break;
		case 21:	
			sound(G1);
			break;
		case 25:
			nosound();
			break;
		case 26:	
			sound(G1);
			break;
		case 30:
			nosound();
			break;
		case 31:
			sound(E1);
			break;
		case 35:
			nosound();
			break;
		case 36:
			sound(G1);
			break;
		case 40:
			nosound();
			break;
		case 41:
			sound(G1);
			break;
		case 45:
			nosound();
			break;
		case 46:
			sound(E1);
			break;
		case 50:
			nosound();
			break;
		case 51:
			sound(E1);
			break;
		case 55:
			nosound();
			break;
		case 56:
			sound(D1);
			break;
		case 60:
			nosound();
			break;
		case 61:
			sound(G1);
			break;
		case 65:
			nosound();
			break;
		case 66:
			sound(G1);
			break;
		case 70:
			nosound();
			break;
		case 71:
			sound(A1);
			break;
		case 75:
			nosound();
			break;
		case 76:
			sound(A1);
			break;
		case 80:
			nosound();
			break;
		case 81:
			sound(A1);
			break;
		case 85:
			nosound();
			break;
		case 86:
			sound(A1);
			break;
		case 90:
			nosound();
			break;
	}		
}

void pauseMusic()
{
	isPlay = 0;
}

void playMusic()
{
	isPlay = 1;
}

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

void adc_init( void)   // adc  초기화
{    
  ADCSRA = 0x00; //disable adc
  ADMUX = 0x00; //select adc input 
  ADCSRA = 0x87; //adc enable, 분주 128

  //adc를 위한 주파수 = 16mhz/128=125khz

}
 
void adc_startConversion( void)   // adc변환
{

  ADCSRA &= 0x07; //  128분주비 사용
  ADMUX = 0x00;  

  ADCSRA |= 0xC0;  // ADC ON
}

unsigned int  adc_readData( void)   // adc변환
{  
  volatile unsigned int adc_temp;

  while((ADCSRA & 0x10) == 0); //변환완료될때까지 기다림
  adc_temp=(int)ADCL+(int)ADCH*256;

  return adc_temp;
}

 
void main()
{	
	unsigned int adc_data;
	float voltage;

	init_devices();
	adc_init();
	lcdInit();
	lcdClear();
	nosound();


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

	//	lcd_gotoxy(1, 1);
		putString(songName[10]);
		//lcd_puts(2, artistName);
				
		lcd_gotoxy(10,2);
		lcd_putn3(voltage);

		for(int i = 0 ; i<1000;i++)
			runDotMatrix();
		
	}
}
