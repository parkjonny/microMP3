void adc_init( void)   // adc  �ʱ�ȭ
{    
  ADCSRA = 0x00; //disable adc
  ADMUX = 0x00; //select adc input 
  ADCSRA = 0x87; //adc enable, ���� 128

  //adc�� ���� ���ļ� = 16mhz/128=125khz

}

unsigned int  adc_readData( void)   // adc��ȯ
{  
  volatile unsigned int adc_temp;

  while((ADCSRA & 0x10) == 0); //��ȯ�Ϸ�ɶ����� ��ٸ�
  adc_temp=(int)ADCL+(int)ADCH*256;

  return adc_temp;
}

void adc_startConversion( void)   // adc��ȯ
{
  ADCSRA &= 0x07; //  128���ֺ� ���
  ADMUX = 0x00;  

  ADCSRA |= 0xC0;  // ADC ON
}
 
