#include <stdio.h>
#include <string.h>

void counter( unsigned *hi, unsigned *lo )
{
asm("rdtsc; movl %%edx,%0; movl %%eax, %1"
        : "=r" (*hi), "=r" (*lo)
        :
        : "%edx", "%eax");
}

void main(){
    char buffer1[1024] = {0};
    char buffer2[1518] = {0};
    int i = 0;

    for(i = 0;i < 1000; ++i){
        buffer1[i] = i%256;
    }

    for(i = 0;i < 1500; ++i){
        buffer2[i] = i%256;
    }
    
    for(i = 0;i < 10000; ++i){
        memmove(buffer1+24,buffer1,1000);
        memmove(buffer2+18,buffer2,1500);
    }
}
