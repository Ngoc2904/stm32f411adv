#include <stdint.h>
void ADC_init(){
	uint32_t *RCC_APB2ENR = (uint32_t *)0x40023844;
	*RCC_APB2ENR|=(1<<8);
	uint32_t *ADC_SMPR1 = (uint32_t *)0x4001200c;
	*ADC_SMPR1|=(0b111<<18);
	uint32_t *ADC_JSQR = (uint32_t *)0x40012038;
	*ADC_JSQR|=(16<<15);
	uint32_t *ADC_CR2 = (uint32_t *)0x40012008;
	*ADC_CR2|=(1<<0)|(0b01<<20);
	uint32_t *ADC_RCC = (uint32_t *)0x40012304;
	*ADC_RCC|=(1<<23);

}
int ADC_READ(){
	uint32_t *ADC_CR2 = (uint32_t *)0x40012008;
	*ADC_CR2|=(1<<22);
	uint32_t *ADC_SR = (uint32_t *)0x40012000;
	while(((*ADC_SR>>2)&1)==0);
	*ADC_CR2&=~(1<<22);
	uint32_t *ADC_JDR1 = (uint32_t *)0x4001203c;
	return *ADC_JDR1;
}
float tempearture(){
	int data=0;
	float Vin=0;
	float temp=0;
	data=ADC_READ();
    Vin=(float)(data*3)/4095.0;
    temp=((Vin-0.76)/0.0025)+25;
    return temp;
}


