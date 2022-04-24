/*
	@Mohamed Adel
	Project: Cortex-M3 Led_Toggle
*/

.section .vectors 
.word 0x20001000 /*stack_top_add*/ 
/*0x00000000 == 0x80000000==sp*/
.word _reset /* jump on reset after sp*/
.word Vector_handler /* 2 NMI */
.word Vector_handler /* 3 Hardfault */
.word Vector_handler /* 4 MemManage */
.word Vector_handler /* 5 BusFault */
.word Vector_handler /* 6 UsageFault */
.word Vector_handler /* 7 Reserved */
.word Vector_handler /* 8 SVCall */
.word Vector_handler /* 9 Debug Monitor */
.word Vector_handler /* 10 Reserved */
.word Vector_handler /* 11 PendSV */
.word Vector_handler /* 12 SysTick */
.word Vector_handler /* 13 WWDG */
.word Vector_handler /* 14 PVD */
.word Vector_handler /* 15 TAMPER */
.word Vector_handler /* 16 RTC */
.word Vector_handler /* 17 FLASH */
.word Vector_handler /* 18 RCC */
.word Vector_handler /* 19 EX10 */
.word Vector_handler /* 20 EX11 */
.word Vector_handler /* 21 EX12 */


.section .text
_reset:
	bl main
	b . /*infinite loop*/

.thumb_func /*thumb instruction */
Vector_handler:
	b _reset


