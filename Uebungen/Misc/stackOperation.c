.include "tn2313def.inc"
 
	;Set up AVR ATTiny2313 stack
	LDI	R16, RAMEND
	OUT	SPL, R16
 
	LDI	R16, 0x33
	LDI	R17, 0x25
	LDI	R18, 0x0A
 
	PUSH	R16
	PUSH	R17
	POP	R17
	PUSH	R18
 
 
end:	RJMP	end
