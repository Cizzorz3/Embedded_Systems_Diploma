
App.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <uart_send_string>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	61686f4d 	cmnvs	r8, sp, asr #30
   4:	2064656d 	rsbcs	r6, r4, sp, ror #10
   8:	6c656441 	cfstrdvs	mvd6, [r5], #-260	; 0xfffffefc
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	0000007d 	andeq	r0, r0, sp, ror r0
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000014 	andeq	r0, r0, r4, lsl r0
  10:	00000e0c 	andeq	r0, r0, ip, lsl #28
  14:	00007100 	andeq	r7, r0, r0, lsl #2
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001c00 	andeq	r1, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	00780200 	rsbseq	r0, r8, r0, lsl #4
  28:	003b0201 	eorseq	r0, fp, r1, lsl #4
  2c:	03050000 	movweq	r0, #20480	; 0x5000
  30:	00000000 	andeq	r0, r0, r0
  34:	69050403 	stmdbvs	r5, {r0, r1, sl}
  38:	0400746e 	streq	r7, [r0], #-1134	; 0xfffffb92
  3c:	00000034 	andeq	r0, r0, r4, lsr r0
  40:	00005705 	andeq	r5, r0, r5, lsl #14
  44:	00005000 	andeq	r5, r0, r0
  48:	00500600 	subseq	r0, r0, r0, lsl #12
  4c:	00630000 	rsbeq	r0, r3, r0
  50:	a8070407 	stmdage	r7, {r0, r1, r2, sl}
  54:	07000000 	streq	r0, [r0, -r0]
  58:	00000801 	andeq	r0, r0, r1, lsl #16
  5c:	b5080000 	strlt	r0, [r8, #-0]
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	00004003 	andeq	r4, r0, r3
  68:	00030500 	andeq	r0, r3, r0, lsl #10
  6c:	09000000 	stmdbeq	r0, {}	; <UNPREDICTABLE>
  70:	000000c3 	andeq	r0, r0, r3, asr #1
  74:	00000501 	andeq	r0, r0, r1, lsl #10
  78:	001c0000 	andseq	r0, ip, r0
  7c:	9c010000 	stcls	0, cr0, [r1], {-0}
	...

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	08030034 	stmdaeq	r3, {r2, r4, r5}
  18:	0b3b0b3a 	bleq	ec2d08 <main+0xec2d08>
  1c:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	; <UNPREDICTABLE>
  20:	00001802 	andeq	r1, r0, r2, lsl #16
  24:	0b002403 	bleq	9038 <main+0x9038>
  28:	030b3e0b 	movweq	r3, #48651	; 0xbe0b
  2c:	04000008 	streq	r0, [r0], #-8
  30:	13490026 	movtne	r0, #36902	; 0x9026
  34:	01050000 	mrseq	r0, (UNDEF: 5)
  38:	01134901 	tsteq	r3, r1, lsl #18
  3c:	06000013 			; <UNDEFINED> instruction: 0x06000013
  40:	13490021 	movtne	r0, #36897	; 0x9021
  44:	00000b2f 	andeq	r0, r0, pc, lsr #22
  48:	0b002407 	bleq	906c <main+0x906c>
  4c:	030b3e0b 	movweq	r3, #48651	; 0xbe0b
  50:	0800000e 	stmdaeq	r0, {r1, r2, r3}
  54:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  58:	0b3b0b3a 	bleq	ec2d48 <main+0xec2d48>
  5c:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	; <UNPREDICTABLE>
  60:	00001802 	andeq	r1, r0, r2, lsl #16
  64:	3f002e09 	svccc	0x00002e09
  68:	3a0e0319 	bcc	380cd4 <main+0x380cd4>
  6c:	110b3b0b 	tstne	fp, fp, lsl #22
  70:	40061201 	andmi	r1, r6, r1, lsl #4
  74:	19429618 	stmdbne	r2, {r3, r4, r9, sl, ip, pc}^
  78:	Address 0x00000078 is out of bounds.


Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000001c 	andeq	r0, r0, ip, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707041 	cdpcs	0, 7, cr7, cr0, cr1, {2}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4c1600 	blmi	1305834 <main+0x1305834>
  30:	01000602 	tsteq	r0, r2, lsl #12
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	70410072 	subvc	r0, r1, r2, ror r0
  10:	00632e70 	rsbeq	r2, r3, r0, ror lr
  14:	20554e47 	subscs	r4, r5, r7, asr #28
  18:	20313143 	eorscs	r3, r1, r3, asr #2
  1c:	2e322e37 	mrccs	14, 1, r2, cr2, cr7, {1}
  20:	30322031 	eorscc	r2, r2, r1, lsr r0
  24:	39303731 	ldmdbcc	r0!, {r0, r4, r5, r8, r9, sl, ip, sp}
  28:	28203430 	stmdacs	r0!, {r4, r5, sl, ip, sp}
  2c:	656c6572 	strbvs	r6, [ip, #-1394]!	; 0xfffffa8e
  30:	29657361 	stmdbcs	r5!, {r0, r5, r6, r8, r9, ip, sp, lr}^
  34:	52415b20 	subpl	r5, r1, #32, 22	; 0x8000
  38:	6d652f4d 	stclvs	15, cr2, [r5, #-308]!	; 0xfffffecc
  3c:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  40:	372d6465 	strcc	r6, [sp, -r5, ror #8]!
  44:	6172622d 	cmnvs	r2, sp, lsr #4
  48:	2068636e 	rsbcs	r6, r8, lr, ror #6
  4c:	69766572 	ldmdbvs	r6!, {r1, r4, r5, r6, r8, sl, sp, lr}^
  50:	6e6f6973 			; <UNDEFINED> instruction: 0x6e6f6973
  54:	35353220 	ldrcc	r3, [r5, #-544]!	; 0xfffffde0
  58:	5d343032 	ldcpl	0, cr3, [r4, #-200]!	; 0xffffff38
  5c:	636d2d20 	cmnvs	sp, #32, 26	; 0x800
  60:	613d7570 	teqvs	sp, r0, ror r5
  64:	32396d72 	eorscc	r6, r9, #7296	; 0x1c80
  68:	2d6a6536 	cfstr64cs	mvdx6, [sl, #-216]!	; 0xffffff28
  6c:	672d2073 			; <UNDEFINED> instruction: 0x672d2073
  70:	5c3a4500 	cfldr32pl	mvfx4, [sl], #-0
  74:	72756f43 	rsbsvc	r6, r5, #268	; 0x10c
  78:	5c736573 	cfldr64pl	mvdx6, [r3], #-460	; 0xfffffe34
  7c:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xfffff2bb
  80:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  84:	7379535f 	cmnvc	r9, #2080374785	; 0x7c000001
  88:	736d6574 	cmnvc	sp, #116, 10	; 0x1d000000
  8c:	756f435f 	strbvc	r4, [pc, #-863]!	; fffffd35 <main+0xfffffd35>
  90:	5c657372 	stclpl	3, cr7, [r5], #-456	; 0xfffffe38
  94:	74696e55 	strbtvc	r6, [r9], #-3669	; 0xfffff1ab
  98:	654c5c33 	strbvs	r5, [ip, #-3123]	; 0xfffff3cd
  9c:	6e6f7373 	mcrvs	3, 3, r7, cr15, cr3, {3}
  a0:	4c5c325f 	lfmmi	f3, 2, [ip], {95}	; 0x5f
  a4:	00316261 	eorseq	r6, r1, r1, ror #4
  a8:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  ac:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  b0:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  b4:	72747300 	rsbsvc	r7, r4, #0, 6
  b8:	5f676e69 	svcpl	0x00676e69
  bc:	66667562 	strbtvs	r7, [r6], -r2, ror #10
  c0:	6d007265 	sfmvs	f7, 4, [r0, #-404]	; 0xfffffe6c
  c4:	006e6961 	rsbeq	r6, lr, r1, ror #18

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	5420554e 	strtpl	r5, [r0], #-1358	; 0xfffffab2
   c:	736c6f6f 	cmnvc	ip, #444	; 0x1bc
  10:	726f6620 	rsbvc	r6, pc, #32, 12	; 0x2000000
  14:	6d724120 	ldfvse	f4, [r2, #-128]!	; 0xffffff80
  18:	626d4520 	rsbvs	r4, sp, #32, 10	; 0x8000000
  1c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  20:	72502064 	subsvc	r2, r0, #100	; 0x64
  24:	7365636f 	cmnvc	r5, #-1140850687	; 0xbc000001
  28:	73726f73 	cmnvc	r2, #460	; 0x1cc
  2c:	322d3720 	eorcc	r3, sp, #32, 14	; 0x800000
  30:	2d373130 	ldfcss	f3, [r7, #-192]!	; 0xffffff40
  34:	6d2d3471 	cfstrsvs	mvf3, [sp, #-452]!	; 0xfffffe3c
  38:	726f6a61 	rsbvc	r6, pc, #397312	; 0x61000
  3c:	2e372029 	cdpcs	0, 3, cr2, cr7, cr9, {1}
  40:	20312e32 	eorscs	r2, r1, r2, lsr lr
  44:	37313032 			; <UNDEFINED> instruction: 0x37313032
  48:	34303930 	ldrtcc	r3, [r0], #-2352	; 0xfffff6d0
  4c:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  50:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  54:	5b202965 	blpl	80a5f0 <main+0x80a5f0>
  58:	2f4d5241 	svccs	0x004d5241
  5c:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  60:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  64:	622d372d 	eorvs	r3, sp, #11796480	; 0xb40000
  68:	636e6172 	cmnvs	lr, #-2147483620	; 0x8000001c
  6c:	65722068 	ldrbvs	r2, [r2, #-104]!	; 0xffffff98
  70:	69736976 	ldmdbvs	r3!, {r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  74:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  78:	30323535 	eorscc	r3, r2, r5, lsr r5
  7c:	Address 0x0000007c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000001c 	andeq	r0, r0, ip, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0xfffffdc7
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0xfffffef7
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.

