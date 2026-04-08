void _start()
{
    const char msg[] = "hello_world\n";
    long n = (long)(sizeof(msg)-1);
    
    asm volatile (
        "mov $1, %%rax\n\t"    // syscall write
        "mov $1, %%rdi\n\t"    // stdout = 1
        "mov %0, %%rsi\n\t"    // string addr
        "mov %1, %%rdx\n\t"
        "syscall\n\t"
        
        "mov $60, %%rax\n\t"   //exit
        "mov $1, %%rdi\n\t"
        "syscall\n\t"
        :
        : "r"(msg), "r"(n)
        : "rax", "rdi", "rsi", "rdx"
    );   
}