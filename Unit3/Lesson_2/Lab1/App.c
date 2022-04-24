#include "uart.h"
const int x;
unsigned char string_buffer[100]="Mohamed Adel";
unsigned char const moh[100]="create_row_data_section";
void main(){

	uart_send_string(string_buffer);
}