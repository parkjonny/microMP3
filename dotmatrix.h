#define EX_SS_DATA			(*(volatile unsigned char *)0x8002)
#define EX_SS_SEL			(*(volatile unsigned char *)0x8003)
#define EX_DM_SEL			(*(volatile unsigned char *)0x8004)
#define EX_DM_DATA			(*(volatile unsigned char *)0x8006)
#define EX_LED				(*(volatile unsigned char *)0x8008)

int dm_data1[10] = {0x000, 0x000, 0x000, 0x000, 0x030, 0x030, 0x000, 0x000, 0x000, 0x000};
int dm_data2[10] = {0x000, 0x000, 0x078, 0x084, 0x0B4, 0x0B4, 0x084, 0x078, 0x000, 0x000};
int dm_data3[10] = {0x0FC, 0x102, 0x279, 0x285, 0x2B5, 0x2B5, 0x285, 0x279, 0x102, 0x0FC};
int beatType = 0; //0: nosound, 1: lowsound, 2: highsound
int dmi = 0;

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
