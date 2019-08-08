	.text
	.intel_syntax noprefix
	.file	"TestAssembly.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# BB#0:
	push	rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp8:
	.cfi_def_cfa_register rbp
	sub	rsp, 112
	mov	dword ptr [rbp - 4], 0
	mov	dword ptr [rbp - 8], 0
	mov	eax, dword ptr [rip + .L_ZZ4mainE4help+16]
	mov	dword ptr [rbp - 16], eax
	movaps	xmm0, xmmword ptr [rip + .L_ZZ4mainE4help]
	movaps	xmmword ptr [rbp - 32], xmm0
	mov	qword ptr [rbp - 40], 0
	lea	rcx, [rbp - 80]
	mov	rdi, rcx
	mov	qword ptr [rbp - 112], rcx # 8-byte Spill
	call	_ZNSaIcEC1Ev
.Ltmp3:
	mov	eax, .L.str
	mov	esi, eax
	lea	rdi, [rbp - 72]
	mov	rdx, qword ptr [rbp - 112] # 8-byte Reload
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.Ltmp4:
	jmp	.LBB1_1
.LBB1_1:
	lea	rdi, [rbp - 80]
	call	_ZNSaIcED1Ev
	lea	rdi, [rbp - 72]
	mov	qword ptr [rbp - 104], rdi
	mov	dword ptr [rbp - 4], 0
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	mov	eax, dword ptr [rbp - 4]
	add	rsp, 112
	pop	rbp
	ret
.LBB1_2:
.Ltmp5:
	lea	rdi, [rbp - 80]
	mov	ecx, edx
	mov	qword ptr [rbp - 88], rax
	mov	dword ptr [rbp - 92], ecx
	call	_ZNSaIcED1Ev
# BB#3:
	mov	rdi, qword ptr [rbp - 88]
	call	_Unwind_Resume
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.align	4
GCC_except_table1:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\234"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	26                      # Call site table length
	.long	.Ltmp3-.Lfunc_begin0    # >> Call Site 1 <<
	.long	.Ltmp4-.Ltmp3           #   Call between .Ltmp3 and .Ltmp4
	.long	.Ltmp5-.Lfunc_begin0    #     jumps to .Ltmp5
	.byte	0                       #   On action: cleanup
	.long	.Ltmp4-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Lfunc_end1-.Ltmp4      #   Call between .Ltmp4 and .Lfunc_end1
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.align	4

	.text
	.globl	_Z8cmpMyObjPiRi
	.align	16, 0x90
	.type	_Z8cmpMyObjPiRi,@function
_Z8cmpMyObjPiRi:                        # @_Z8cmpMyObjPiRi
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp11:
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	rsi, qword ptr [rbp - 8]
	mov	eax, dword ptr [rsi]
	pop	rbp
	ret
.Lfunc_end2:
	.size	_Z8cmpMyObjPiRi, .Lfunc_end2-_Z8cmpMyObjPiRi
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_TestAssembly.cpp,@function
_GLOBAL__sub_I_TestAssembly.cpp:        # @_GLOBAL__sub_I_TestAssembly.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp12:
	.cfi_def_cfa_offset 16
.Ltmp13:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp14:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end3:
	.size	_GLOBAL__sub_I_TestAssembly.cpp, .Lfunc_end3-_GLOBAL__sub_I_TestAssembly.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L_ZZ4mainE4help,@object # @_ZZ4mainE4help
	.section	.rodata,"a",@progbits
	.align	16
.L_ZZ4mainE4help:
	.long	1                       # 0x1
	.long	2                       # 0x2
	.long	3                       # 0x3
	.long	4                       # 0x4
	.long	5                       # 0x5
	.size	.L_ZZ4mainE4help, 20

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"help"
	.size	.L.str, 5

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_TestAssembly.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
