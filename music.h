//?? ????
#define C1 523
#define C1_ 554
#define D1 587
#define D1_ 622
#define E1 659		//??
#define F1 699		//??
#define F1_ 740
#define G1 784		//??
#define G1_ 831
#define A1 880		//??
#define A1_ 932
#define B1 988		//??

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


void bearFamily(void)
{
	songName[10] = "Three Bear";
	artistName[10] = "Unknown";

	playTime = 20;
	if(isPlay == 1)
	switch(digit_num)
	{
		case 1:
			sound(C1);//°õ
			break;
		case 2:
			nosound();
			break;
		case 3:
			nosound();
			break;
		case 4:
			nosound();
			break;
		case 5:
			sound(C1);//¼¼
			break;
		case 6:
			nosound();
			break;
		case 7:
			sound(C1);//¸¶
			break;
		case 8:
			nosound();
			break;
		case 9:
			sound(C1);//¸®
			break;
		case 10:
			nosound();
			break;
		case 11:
			nosound();
			break;
		case 12:
			nosound();
			break;						
		case 13:
			sound(C1);//°¡
			break;	
	    case 14:
			nosound();
			break;
		case 15:
			nosound();
			break;
		case 16:
			nosound();
			break;	
		case 17:	
			sound(E1);//ÇÑ
			break;
		case 18:
			nosound();
			break;
		case 19:
			nosound();
			break;
		case 20:
			nosound();
			break;
		case 21:
			sound(G1);//Áý
			break;
		case 22:
			nosound();
			break;
		case 23:
			sound(G1);//¿¡
			break;
		case 24:
			nosound();
			break;
		case 25:	
			sound(E1);//ÀÖ
			break;
		case 26:
			nosound();
			break;
		case 27:
			nosound();
			break;
		case 28:
			nosound();
			break;
		case 29:
			sound(C1);//¾î
			break;
		case 30:
			nosound();
			break;
		case 31:
			nosound();
			break;
		case 32:
			nosound();
			break;
		case 33:	
			sound(G1);//¾Æ
			break;
		case 34:
			nosound();
			break;
		case 35:
			sound(G1);//ºü
			break;
		case 36:
			nosound();
			break;
		case 37:
			sound(E1);//°õ
			break;
		case 38:
			nosound();
			break;
		case 39:
			nosound();
			break;	
		case 40:
			nosound();
			break;
		case 41:
			sound(G1);//¾ö
			break;
		case 42:
			nosound();
			break;
		case 43:
			sound(G1);//¸¶
			break;
		case 44:
			nosound();
			break;
		case 45:
			sound(E1);//°õ
			break;
		case 46:
			nosound();
			break;
		case 47:
			nosound();
			break;
		case 48:
			nosound();
			break;	
		case 49:
			sound(C1);//¾Ö
			break;
		case 50:
			nosound();
			break;
		case 51:
			nosound();
			break;
		case 52:
			nosound();
			break;
		case 53:
			sound(C1);//±â
			break;
		case 54:
			nosound();
			break;
		case 55:
			nosound();
			break;
		case 56:
			nosound();
			break;
		case 57:
			sound(C1);//°õ
			break;
		case 58:
			nosound();
			break;
		case 59:
			nosound();
			break;
		case 60:
			nosound();
			break;
		case 61:
			nosound();
			break;
		case 62:
			nosound();
			break;
		case 63:
			nosound();
			break;
		case 64:
			nosound();
			break;
		case 65:
			sound(G1);//¾Æ
			break;
		case 66:
			nosound();
			break;
		case 67:
			nosound();
			break;
		case 68:
			nosound();
			break;
		case 69:
			sound(G1);//ºü
			break;
		case 70:
			nosound();
			break;
		case 71:
			nosound();
			break;
		case 72:
			nosound();
			break;
		case 73:
			sound(E1);//°õ
			break;
		case 74:
			nosound();
			break;
		case 75:
			nosound();
			break;
		case 76:
			nosound();
			break;
		case 77:
			sound(C1);//Àº
			break;
		case 78:
			nosound();
			break;
		case 79:
			nosound();
			break;
		case 80:
			nosound();
			break;
		case 81:
			sound(G1);//¶×
			break;
		case 82:
			nosound();
			break;
		case 83:
			nosound();
			break;
		case 84:
			nosound();
			break;
		case 85:
			sound(G1);//¶×
			break;
		case 86:
			nosound();
			break;
		case 87:
			nosound();
			break;
		case 88:
			nosound();
			break;
		case 89:
			sound(G1);//ÇØ
			break;
		case 90:
			nosound();
			break;
		case 91:
			nosound();
			break;
		case 92:
			nosound();
			break;	
		case 93:
			nosound();
			break;
		case 94:
			nosound();
			break;
		case 95:
			nosound();
			break;
		case 96:
			nosound();
			break;
		case 97:
			sound(G1);//¾ö
			break;
		case 98:
			nosound();
			break;
		case 99:
			nosound();
			break;
		case 100:
			nosound();
			break;
		case 101:
			sound(G1);//¸¶
			break;
		case 102:
			nosound();
			break;
		case 103:
			nosound();
			break;
		case 104:
			nosound();
			break;
		case 105:
			sound(E1);//°õ
			break;
		case 106:
			nosound();
			break;
		case 107:
			nosound();
			break;
		case 108:
			nosound();
			break;
		case 109:
			sound(C1);//Àº
			break;
		case 110:
			nosound();
			break;
		case 111:
			nosound();
			break;
		case 112:
			nosound();
			break;
		case 113:
			sound(G1);//³¯
			break;
		case 114:
			nosound();
			break;
		case 115:
			nosound();
			break;
		case 116:
			nosound();
			break;
		case 117:
			sound(G1);//¾À
			break;
		case 118:
			nosound();
			break;
		case 119:
			nosound();
			break;
		case 120:
			nosound();
			break;
		case 121:
			sound(G1);//ÇØ
			break;
		case 122:
			nosound();
			break;
		case 123:
			nosound();
			break;
		case 124:
			nosound();
			break;
		case 125:
			nosound();
			break;
		case 126:
			nosound();
			break;
		case 127:
			nosound();
			break;
		case 128:
			nosound();
			break;
		case 129:
			sound(G1);//¾Ö
			break;
		case 130:
			nosound();
			break;
		case 131:
			nosound();
			break;
		case 132:
			nosound();
			break;
		case 133:
			sound(G1);//±â
			break;
		case 134:
			nosound();
			break;
		case 135:
			nosound();
			break;
		case 136:
			nosound();
			break;
		case 137:
			sound(E1);//°õ
			break;
		case 138:
			nosound();
			break;
		case 139:
			nosound();
			break;
		case 140:
			nosound();
			break;
		case 141:
			sound(C1);//Àº
			break;
		case 142:
			nosound();
			break;
		case 143:
			nosound();
			break;
		case 144:
			nosound();
			break;
		case 145:
			sound(G1);//³Ê
			break;
		case 146:
			nosound();
			break;
		case 147:
			sound(G1);//¹«
			break;
		case 148:
			nosound();
			break;
		case 149:
			sound(G1);//±Í
			break;
		case 150:
			nosound();
			break;
		case 151:
			sound(A1);//¿©
			break;
		case 152:
			nosound();
			break;
		case 153:
			sound(G1);//¿ö
			break;
		case 154:
			nosound();
			break;
		case 155:
			nosound();
			break;
		case 156:
			nosound();
			break;
		case 157:
			nosound();
			break;
		case 158:
			nosound();
			break;
		case 159:
			nosound();
			break;
		case 160:
			nosound();
			break;
		case 161:
			sound(C2);//À¸
			break;
		case 162:
			nosound();
			break;
		case 163:
			nosound();
			break;
		case 164:
			nosound();
			break;
		case 165:
			sound(G1);//¾³
			break;
		case 166:
			nosound();
			break;
		case 167:
			nosound();
			break;
		case 168:
			nosound();
			break;
		case 169:
			sound(C2);//À¸
			break;
		case 170:
			nosound();
			break;
		case 171:
			nosound();
			break;
		case 172:
			nosound();
			break;
		case 173:
			sound(G1);//¾³
			break;
		case 174:
			nosound();
			break;
		case 175:
			nosound();
			break;
		case 176:
			nosound();
			break;
		case 177:
			sound(E1);//Àß
			break;
		case 178:
			nosound();
			break;
		case 179:
			nosound();
			break;
		case 180:
			nosound();
			break;				
		case 181:
			sound(D1);//ÇÑ
			break;	
		case 182:
			nosound();
			break;
		case 183:
			nosound();
			break;
		case 184:
			nosound();
			break;
		case 185:
			sound(C1);//´Ù
			break;
		case 186:
			nosound();
			break;
		case 187:
			nosound();
			break;
		case 188:
			nosound();
			break;
		case 189:
			nosound();
			break;
		case 190:
			nosound();
			break;
		case 191:
			nosound();
			break;
		case 192:
			nosound();
			break;
	}		
}

void birthdaySong(void)
{
	songName[10] = "Happy Birth Day";
	artistName[10] = "Unknown";

	playTime = 9;
	if(isPlay == 1)
	switch(digit_num)
	{
		case 1:
			sound(D1);
			break;
		case 2:
			nosound();
			break;
		case 3:
			sound(D1);
			break;
		case 4:
			nosound();
			break;
		case 5:
			sound(E1);
			break;
		case 6:
			nosound();
			break;
		case 7:
			nosound();
			break;
		case 8:
			nosound();
			break;
		case 9:
			sound(D1);
			break;
		case 10:
			nosound();
			break;
		case 11:
			nosound();
			break;
		case 12:
			nosound();
			break;
		case 13:
			sound(G1);
			break;
		case 14:
			nosound();
			break;
		case 15:	
			nosound();
			break;
		case 16:
			nosound();
			break;
		case 17:
			sound(F1_);
			break;
		case 18:
			nosound();
			break;
		case 19:
			nosound();
			break;
		case 20:
			nosound();
			break;
		case 21:
			nosound();
			break;
		case 22:
			nosound();
			break;
		case 23:
			nosound();
			break;
		case 24:
			nosound();
			break;
		case 25:
			sound(D1);
			break;
		case 26:
			nosound();
			break;
		case 27:	
			sound(D1);
			break;
		case 28:
			nosound();
			break;
		case 29:
			sound(E1);
			break;
		case 30:
			nosound();
			break;
		case 31:
			nosound();
			break;
		case 32:
			nosound();
			break;
		case 33:	
			sound(D1);
			break;
		case 34:
			nosound();
			break;
		case 35:
			nosound();
			break;
		case 36:
			nosound();
			break;
		case 37:
			sound(A1);
			break;
		case 38:
			nosound();
		case 39:
			sound(A1);
			break;
		case 40:
			nosound();
			break;
		case 41:
			sound(G1);
			break;
		case 42:
			nosound();
			break;
		case 43:
			nosound();
			break;
		case 44:
			nosound();
			break;
		case 45:
			nosound();
			break;
		case 46:
			nosound();
			break;
		case 47:
			nosound();
			break;
		case 48:
			nosound();
			break;
		case 49:
			sound(D1);
			break;
		case 50:
			nosound();
			break;
		case 51:
			sound(D1);
			break;
		case 52:
			nosound();
		case 53:
			sound(D2);
			break;
		case 54:
			nosound();
			break;
		case 55:
			nosound();
			break;
		case 56:
			nosound();
			break;
		case 57:
			sound(B1);
			break;
		case 58:
			nosound();
			break;
		case 59:
			nosound();
			break;
		case 60:
			nosound();
			break;
		case 61:
			sound(G1);
			break;
		case 62:
			nosound();
			break;
		case 63:
			nosound();
			break;
		case 64:
			nosound();
			break;
		case 65:
			sound(F1);
			break;
		case 66:
			nosound();
			break;
		case 67:
			nosound();
			break;
		case 68:
			nosound();
			break;
		case 69:
			sound(E1);
			break;
		case 70:
			nosound();
			break;
		case 71:
			nosound();
			break;
		case 72:
			nosound();
			break;
		case 73:
			sound(C2);
			break;
		case 74:
			nosound();
			break;
		case 75:
			sound(C2);
			break;
		case 76:
			nosound();
			break;
		case 77:
			sound(B1);
			break;
		case 78:
			nosound();
			break;
		case 79:
			nosound();
			break;
		case 80:
			nosound();
			break;
		case 81:
			sound(G1);
			break;
		case 82:
			nosound();
			break;
		case 83:
			nosound();
			break;
		case 84:
			nosound();
			break;
		case 85:
			sound(A1);
			break;
		case 86:
			nosound();
			break;
		case 87:
			sound(A1);
			break;
		case 88:
			nosound();
			break;
		case 89:
			sound(G1);
			break;
		case 90:
			nosound();
			break;
		case 91:
			nosound();
			break;
		case 92:
			nosound();
			break;
		case 93:
			nosound();
			break;
		case 94:
			nosound();
			break;
		case 95:
			nosound();
			break;
		case 96:
			nosound();
			break;
		case 97:
			nosound();
			break;


		
	}		
}

void thorn(void)
{
	songName[10] = "thorn";
	artistName[10] = "Buzz";

	playTime = 30;
	if(isPlay == 1)
	switch(digit_num)
	{
		case 1:
			sound(A1);
			break;
		case 2:
			nosound();
			break;
		case 3:
			sound(C2);
			break;
		case 4:
			nosound();
			break;
		case 5:
			sound(C2);
			break;
		case 6:
			nosound();
			break;
		case 7:
			sound(A1);
			break;
		case 8:
			sound(D2);
			break;
		case 9:	
			sound(D2);
			break;
		case 10:
			nosound();
			break;
		case 11:
			sound(C2);
			break;
		case 12:
			nosound();
			break;
		case 13:
			sound(C2);
			break;
		case 14:
			nosound();
			break;
		case 15:	
			nosound();
			break;
		case 16:
			sound(E2);
			break;
		case 17:	
			sound(F2);
			break;
		case 18:
			nosound();
			break;
		case 19:
			nosound();
			break;
		case 20:
			sound(E2);
			break;
		case 21:
			sound(D2);
			break;
		case 22:
			nosound();
			break;
		case 23:
			sound(A1);
			break;
		case 24:
			nosound();
			break;
		case 25:
			sound(D2);
			break;
		case 26:
			nosound();
			break;
		case 27:
			nosound();
			break;
		case 28:
			nosound();
			break;
		case 29:
			nosound();
			break;
		case 30:
			nosound();
			break;
		case 31:
			nosound();
			break;
		case 32:
		 	nosound();
			break;
		case 33:
			sound(A1);
			break;
		case 34:
			nosound();
			break;
		case 35:
			sound(C2);
			break;
		case 36:
			nosound();
			break;
		case 37:
			sound(C2);
			break;
		case 38:
			nosound();
			break;
		case 39:
			sound(C2);
			break;
		case 40:
			sound(C2);
			break;
		case 41:
			sound(D2);
			break;
		case 42:
			nosound();
			break;
		case 43:
			sound(D2);
			break;
		case 44:
			nosound();
			break;
		case 45:
			sound(C2);
			break;
		case 46:
			nosound();
			break;
		case 47:
			sound(A1);
			break;
		case 48:
			nosound();
			break;
		case 49:
			sound(G1);
			break;
		case 50:
			nosound();
			break;
		case 51:
			sound(A1);
			break;
		case 52:
			nosound();
			break;
		case 53:
			nosound();
			break;
		case 54:
			nosound();
			break;
		case 55:
			nosound();
			break;
		case 56:
			nosound();
			break;
		case 57:
			nosound();
			break;
		case 58:
			nosound();
			break;
		case 59:
			nosound();
			break;
		case 60:
			nosound();
			break;
		case 61:
			nosound();
			break;
		case 62:
			sound(A1);
			break;
		case 63:
			nosound();
			break;
		case 64:
			nosound();
			break;
		case 65:
			nosound();
			break;
		case 66:
			nosound();
			break;
		case 67:
			nosound();
			break;
		case 68:
			nosound();
			break;
		case 69:
			sound(C2);
			break;
		case 70:
			nosound();
			break;
		case 71:
			sound(C2);
			break;
		case 72:
			nosound();
			break;
		case 73:
			sound(A1);
			break;
		case 74:
			sound(D2);
			break;
		case 75:	
			sound(D2);
			break;
		case 76:
			nosound();
			break;
		case 77:
			sound(C2);
			break;
		case 78:
			nosound();
			break;
		case 79:
			sound(C2);
			break;
		case 80:
			nosound();
			break;
		case 81:	
			nosound();
			break;
		case 82:
			sound(E2);
			break;
		case 83:	
			sound(F2);
			break;
		case 84:
			nosound();
			break;
		case 85:
			nosound();
			break;
		case 86:
			sound(E2);
			break;
		case 87:
			sound(D2);
			break;
		case 88:
			nosound();
			break;
		case 89:
			sound(A1);
			break;
		case 90:
			nosound();
			break;
		case 91:
			sound(D2);
			break;
		case 92:
			nosound();
			break;
		case 93:
			nosound();
			break;
		case 94:
			nosound();
			break;
		case 95:
			nosound();
			break;
		case 96:
			nosound();
			break;
		case 97:
			nosound();
			break;
		case 98:
			nosound();
			break;
		case 99:
			sound(A1);
			break;
		case 100:
			nosound();
			break;
		case 101:
			sound(C2);
			break;
		case 102:
			sound(C2);
			break;
		case 103:
			sound(C2);
			break;
		case 104:
			nosound();
			break;
		case 105:
			sound(C2);
			break;
		case 106:
			nosound();
			break;
		case 107:
			sound(C2);
			break;
		case 108:
			sound(D2);
			break;
		case 109:
			sound(C2);
			break;
		case 110:
			nosound();
			break;
		case 111:
			sound(A1);
			break;
		case 112:
			nosound();
			break;
		case 113:
			sound(G1);
			break;
		case 114:
			nosound();
			break;
		case 115:
			sound(A1);
			break;
		case 116:
			nosound();
			break;
		case 117:
			nosound();
			break;
		case 118:
			nosound();
			break;
		case 119:
			nosound();
			break;
		case 120:
			nosound();
			break;
		case 121:
			nosound();
			break;
		case 122:
			nosound();
			break;
		case 123:
			nosound();
			break;
		case 124:
			nosound();
			break;
		case 125:
			nosound();
			break;
		case 126:
			nosound();
			break;
		case 127:
			nosound();
			break;
		case 128:
			nosound();
			break;
		case 129:
			nosound();
			break;
		case 130:
			nosound();
			break;
		case 131:
			nosound();
			break;
		case 132:
			nosound();
			break;
		case 133:
			nosound();
			break;
		case 134:
			nosound();
			break;
		case 135:
			sound(D2);
			break;
		case 136:
			nosound();
			break;
		case 137:
			sound(F2);
			break;
		case 138:
			nosound();
			break;
		case 139:
			sound(E2);
			break;
		case 140:
			sound(E2);
			break;
		case 141:
			sound(F2);
			break;
		case 142:
			sound(F2);
			break;
		case 143:
			nosound();
			break;
		case 144:
			sound(G2);
			break;
		case 145:
			nosound();
			break;
		case 146:
			sound(C2);
			break;
		case 147:
			nosound();
			break;
		case 148:
			sound(A1);
			break;
		case 149:
			nosound();
			break;
		case 150:
			sound(C2);
			break;
		case 151:
			sound(C2);
			break;
		case 152: 
			sound(D2);
			break;
		case 153:
			nosound();
			break;
		case 154:
			nosound();
			break;
		case 155:
			nosound();
			break;
		case 156:
			nosound();
			break;
		case 157:
			nosound();
			break;
		case 158:
			nosound();
			break;
		case 159:
			nosound();
			break;
		case 160:
			sound(D2);
			break;
		case 161:
			nosound();
			break;
		case 162:
			nosound();
			break;
		case 163:
			nosound();
			break;
		case 164:
			nosound();
			break;
		case 165:
			nosound();
			break;
		case 166:
			nosound();
			break;
		case 167:
			nosound();
			break;
		case 168:
			sound(B1);
			break;
		case 169:
			sound(B1);
			break;
		case 170:
			sound(B1);
			break;
		case 171:
			sound(D2);
			break;
		case 172:
			nosound();
			break;
		case 173:
			nosound();
			break;
		case 174:
			nosound();
			break;
		case 175:
			nosound();
			break;
		case 176:
			sound(C2);
			break;
		case 177:
			sound(C2);
			break;
		case 178:
			sound(C2);
			break;
		case 179:
			sound(C2);
			break;
		case 180:
			sound(A1);
			break;
		case 181:
			nosound();
			break;
		case 182:
			sound(C2);
			break;
		case 183:
			sound(D2);
			break;
		case 184:
			nosound();
			break;
		case 185:
			nosound();
			break;
		case 186:
			nosound();
			break;
		case 187:
			nosound();
			break;
		case 188:
			nosound();
			break;
		case 189:
			nosound();
			break;
		case 190:
			nosound();
			break;
		case 191:
			nosound();
			break;
		case 192:
			nosound();
			break;
		case 193:
			nosound();
			break;
		case 194:
			nosound();
			break;
		case 195:
			nosound();
			break;
		case 196:
			nosound();
			break;
		case 197:
			nosound();
			break;
		case 198:
			nosound();
			break;	
		case 199:
			sound(C2);
			break;
		case 200:
			nosound();
			break;
		case 201:
			nosound();
			break;
		case 202:
			sound(C2);
			break;
		case 203:
			sound(F2);
			break;
		case 204:
			sound(G2);
			break;
		case 205:
			sound(G2);
			break;
		case 206:
			nosound();
			break;
		case 207:
			sound(A2);
			break;
		case 208:
			nosound();
			break;
		case 209:
			nosound();
			break;
		case 210:
			nosound();
			break;
		case 211:
			nosound();
			break;
		case 212:
			nosound();
			break;
		case 213:
			nosound();
			break;
		case 214:
			nosound();
			break;
		case 215:
			sound(C2_);
			break;
		case 216:
			nosound();
			break;
		case 217:
			nosound();
			break;
		case 218:
			sound(C2);
			break;
		case 219:
			sound(F2);
			break;
		case 220:
			sound(G2);
			break;
		case 221:
			sound(G2);
			break;
		case 222:
			nosound();
			break;
		case 223:
			sound(A2);
			break;
		case 224:
			nosound();
			break;
		case 225:
			nosound();
			break;
		case 226:
			nosound();
			break;
		case 227:
			nosound();
			break;
		case 228:
			nosound();
			break;
		case 229:
			sound(G2);
			break;
		case 230:
			nosound();
			break;
		case 231:
			sound(G2);
			break;
		case 232:
			nosound();
			break;
		case 233:
			sound(F2);
			break;
		case 234:
			nosound();
			break;
		case 235:
			sound(F2);
			break;
		case 236:
			nosound();
			break;
		case 237:
			sound(E2);
			break;
		case 238:
			sound(F2);
			break;
	
		case 239:
			nosound();
			break;
		case 240:
			nosound();
			break;
		case 241:
			nosound();
			break;
		case 242:
			sound(G2);
			break;
		case 243:
			nosound();
			break;
		case 244:
			nosound();
			break;
		case 245:
			nosound();
			break;
		case 246:
			sound(G2);
			break;
		case 247:
			nosound();
			break;
		case 248:
			nosound();
			break;
		case 249:
			nosound();
			break;
		case 250:
			sound(C2);
			break;
		case 251:
			nosound();
			break;
		case 252:
			nosound();
			break;
		case 253:
			sound(C2);
			break;
		case 254:
			sound(F2);
			break;
		case 255:
			sound(G2);
			break;
		case 256:
			sound(G2);
			break;
		case 257:
			sound(A2);
			break;
		case 258:
			sound(A2);
			break;
		case 259:
			nosound();
			break;
		case 260:
			nosound();
			break;
		case 261:
			nosound();
			break;
		case 262:
			nosound();
			break;
		case 263:
			nosound();
			break;
		case 264:
			nosound();
			break;
		case 265:
			nosound();
			break;
		case 266:
			sound(C2);
			break;
		case 267:
			nosound();
			break;
		case 268:
			nosound();
			break;
		case 269:
			sound(C2);
			break;
		case 270:
			sound(F2);
			break;
		case 271:
			sound(G2);
			break;
		case 272:
			sound(G2);
			break;
		case 273:
			sound(A2);
			break;
		case 274:
			sound(A2);
			break;
		case 275:
			nosound();
			break;
		case 276:
			nosound();
			break;
		case 277:
			nosound();
			break;
		case 278:
			sound(G2);
			break;
		case 279:
			nosound();
			break;
		case 280:
			sound(G2);
			break;

		case 281:
			nosound();
			break;

		case 282:
			sound(G2);
			break;
		case 283:
			sound(F2);
			break;
		case 284:
			sound(F2);
			break;
		case 285:
			sound(F2);
			break;
		case 286:
			nosound();
			break;
		case 287:
			sound(E2);
			break;
		case 288:	
			sound(F2);
			break;
		case 289:
			sound(G2);
			break;
		case 290:
			nosound();
			break;
		case 291:
			sound(F2);
			break;
		case 292:
			nosound();
			break;
		case 293:	
			sound(E2);
			break;
		case 294:
			nosound();
			break;
		case 295:
			sound(F2);
			break;
		case 296:
			sound(F2);
			break;
		case 297:
			sound(F2);
			break;

		case 298:
			sound(F2);
			break;
	
	}		
}










