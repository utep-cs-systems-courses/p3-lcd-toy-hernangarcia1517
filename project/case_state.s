jt:
	.word case_1
	.word default
	
	.global check_switch4
check_switch4:
	MOV #1, R12
	CMP &switch4_state, R12
	jne default

	MOV &switch4_state, R12
	ADD R12, R12
	MOV jt(R12), pc
case_1:
	CALL #use_buzzer
	jmp end_case
default:
	jmp end_case
end_case:
	POP PC
