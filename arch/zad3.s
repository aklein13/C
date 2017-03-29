// rekurencja funkcja(n-1)+2*funkcja(n-2)-funkcja(n-3)	f(0,1)=1 f(2)=0
// dziala tylko dla x = (0,6) xD
	.intel_syntax noprefix
	.globl main
	.text

main:
	mov eax, 6
	cmp eax, 2
	je dwa
	cmp eax,1
	je jeden
	cmp eax,0
	je jeden
	xor ebx,ebx
	push eax
	call ff
	//mov eax,ebx
	add esp, 4
	done:
	push eax
	push offset msg
	call printf
	add esp, 8
	mov eax, 0
	ret

dwa:
	xor eax,eax
	jmp done
	
jeden:
	mov eax,1
	jmp done
	
dwaa:
	xor eax,eax
	jmp donne
	
jedenn:
	mov eax,1
	jmp donne

ff:
	push ebp
	mov ebp, esp
	push ecx
	push edx	
	mov eax, [ebp+8]
	cmp eax,2
	ja dalej
	
	cmp eax,2
	je dwaa
	
	cmp eax,1
	je jedenn
	
	cmp eax,0
	je jedenn
	jmp dalej
	donne:
	pop edx
	pop ecx
	pop ebp
	ret
	
dalej:
	mov edx,eax
	mov edi,ebx
	dec eax
	mov ecx,eax
	
	push eax
	call ff
	mov ebx,eax
	xor eax,eax
	add esp, 4
	dec ecx
	push ecx
	call ff
	shl eax
	add ebx,eax
	xor eax,eax
	add esp, 4
	dec ecx
	push ecx
	call ff
	sub ebx,eax
	add esp, 4
	mov eax,ebx
	mov ecx,edx
	mov ebx,edi
	pop edx
	pop ecx
	pop ebp
	ret

	
	
	.data
msg:	.asciz "wynik = %d\n"
