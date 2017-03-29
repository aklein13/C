.intel_syntax noprefix
	.text
	.global main

main:
	finit
	fld1
	fst qword ptr a
	fst qword ptr n
	fstp qword ptr wynik


	# tu bedzie wyliczanie

mov ecx, 20

petla:
	fld qword ptr n
	fld qword ptr a
	fld qword ptr x
	fmulp
	fdivrp
	fst qword ptr a
	fld qword ptr wynik
	faddp
	fstp qword ptr wynik

	fld qword ptr n
	fld1
	faddp
	fstp qword ptr n
	
	
loop petla




	fld qword ptr wynik
	sub esp, 8
	fstp qword ptr [esp]
	mov eax, offset messg
	push eax
	call printf
	add esp, 12
	mov eax, 0
	ret

	.data
x:	.double 1.0
a:	.double 99.9
n:	.double 99.9
wynik:	.double 99.9
messg:	.asciz "wynik=%f\n"
