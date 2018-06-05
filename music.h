//곡 정보
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
#define D2_ D1_ * 2
#define E2 E1 * 2
#define F2 F1 * 2
#define F2_ F1_ * 2
#define G2 G1 * 2
#define G2_ G1_ * 2
#define A2 A1 * 2
#define A2_ A1_ * 2
#define B2 B2 * 2

#define ON 1
#define OFF 2

volatile long T1HIGHCNT = 0xFD, T1LOWCNT = 0x86;
volatile int Soundonoff = ON;

int playTime = 0;
int isPlay = 0;	//0 : pause , 1 : play
char songName[20];
char artistName[20];
unsigned int digit_num = 0;

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

void pauseMusic()
{
	isPlay = 0;
}

void playMusic()
{
	isPlay = 1;
}

void schoolsong(void)
{
	songName[20] = "School Bell Ring";
	artistName[20] = "Unknown";

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
