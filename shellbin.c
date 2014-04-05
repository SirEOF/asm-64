//executando bin/sh
// gcc -o shell shell.c 
int main() {
/*
*******************************
#include <stdlib.h>
int main() {
  execve("/bin/sh", NULL, NULL);
}
*******************************
*/
__asm__(
"xor    %rdx,%rdx\n\t"                // arg 3 = NULL
"mov    %rdx,%rsi\n\t"                // arg 2 = NULL
"mov    $0x1168732f6e69622f,%rdi\n\t"
"shl    $0x8,%rdi\n\t"                
"shr    $0x8,%rdi\n\t"                
"push   %rdi\n\t"                     // colocar /bin/sh na pilha
"mov    %rsp,%rdi\n\t"                
"mov    $0x111111111111113b,%rax\n\t" // syscall numero da = 59
"shl    $0x38,%rax\n\t"         
"shr    $0x38,%rax\n\t"               
"syscall\n\t"
);
}
