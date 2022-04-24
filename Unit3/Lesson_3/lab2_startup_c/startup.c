#include<stdint.h>
extern int main(void);

void reset_handler(void);
void Default_handler(){
	reset_handler();
}
void NMI_handler(void)__attribute__((weak, alias ("Default_handler")));;
void H_Fault_handler(void)__attribute__((weak, alias ("Default_handler")));;
void MM_fault_handler(void)__attribute__((weak, alias ("Default_handler")));;
void bus_fault_handler(void)__attribute__((weak, alias ("Default_handler")));;
extern unsigned int stack_top ;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &stack_top  , 
	(uint32_t) &reset_handler ,
	(uint32_t) &NMI_handler ,
	(uint32_t) &H_Fault_handler ,
	(uint32_t) &MM_fault_handler ,
	(uint32_t) &bus_fault_handler ,

};
extern unsigned int _E_text ;
extern unsigned int _s_data ;
extern unsigned int _E_data ;
extern unsigned int _s_bss ;
extern unsigned int _E_bss ;

void reset_handler(void){
	unsigned int data_size = (unsigned char *)&_E_data -(unsigned char *) &_s_data ;
	unsigned char*p_src = (unsigned char *) _E_text;
	unsigned char *p_dst = (unsigned char *) _s_data;

	for(int i=0 ; i<data_size;i++){
		*((unsigned char *)p_dst++)= *((unsigned char*)p_src++);
	}
	unsigned int bss_size = (unsigned char *)&_E_bss -(unsigned char *) &_s_bss ;
	for(int i=0 ; i<bss_size;i++){
		*((unsigned char *)p_dst++)= (unsigned char) 0;
	}
	main();
}
