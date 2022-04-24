/* 
	linker_script for cortexM3
	@Mohamed Adel
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000 , LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*) /*anything.vector*/
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_E_text = . ;
	}> flash

	.data : {
		_s_data = .;
		*(.data)
		_E_data = .;
	}> sram AT> flash

	.bss : {
		_s_bss = . ;
		*(.bss*)
		_E_bss = .;
		. = ALIGN(4);
		. = . + 0x1000 ;
	}> sram
}