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

//booking 1024 byte through unintialized array of 256 element
static unsigned long stack_top[256] ;

void (* const g_fun_vectors[])() __attribute__((section(".vectors"))) = 
{

	(void (*)()) ((unsigned long)stack_top+ sizeof(stack_top)),
	reset_handler ,
	&H_Fault_handler ,
	&MM_fault_handler ,
	&bus_fault_handler ,

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
