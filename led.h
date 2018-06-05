#define EX_SS_DATA			(*(volatile unsigned char *)0x8002)
#define EX_SS_SEL			(*(volatile unsigned char *)0x8003)
#define EX_DM_SEL			(*(volatile unsigned char *)0x8004)
#define EX_DM_DATA			(*(volatile unsigned char *)0x8006)
#define EX_LED				(*(volatile unsigned char *)0x8008)

unsigned char display_num[4] = {0xfe, 0xfd, 0xfb, 0xf7};
unsigned char segment_data[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};

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
