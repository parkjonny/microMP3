void adc_init( void)   // adc  초기화
{    
  ADCSRA = 0x00; //disable adc
  ADMUX = 0x00; //select adc input 
  ADCSRA = 0x87; //adc enable, 분주 128

  //adc를 위한 주파수 = 16mhz/128=125khz

}

unsigned int  adc_readData( void)   // adc변환
{  
  volatile unsigned int adc_temp;

  while((ADCSRA & 0x10) == 0); //변환완료될때까지 기다림
  adc_temp=(int)ADCL+(int)ADCH*256;

  return adc_temp;
}

void adc_startConversion( void)   // adc변환
{
  ADCSRA &= 0x07; //  128분주비 사용
  ADMUX = 0x00;  

  ADCSRA |= 0xC0;  // ADC ON
}
 
