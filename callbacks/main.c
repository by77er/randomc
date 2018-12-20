#include <stdio.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}
int mod(int a, int b) {
    return a % b;
}

int main(void) {
    typedef struct _ins {
        unsigned char code;
        unsigned char arga;
        unsigned char argb;
        unsigned char argc;
    } instruction;
    typedef int (*f)();                          // declare typdef


    instruction assembly[5];
    memset(assembly, 0, sizeof(assembly));

    assembly[0].code = 0x00; // add
    assembly[0].arga = 5;
    assembly[0].argb = 5;
    assembly[1].code = 0x01; // sub
    assembly[1].arga = 4;
    assembly[1].argb = 3;
    assembly[2].code = 0x02; // mul
    assembly[2].arga = 10;
    assembly[2].argb = 10;
    assembly[3].code = 0x03; // div
    assembly[3].arga = 6;
    assembly[3].argb = 2;
    assembly[4].code = 0x04; // mod
    assembly[4].arga = 5;
    assembly[4].argb = 2;

    f funcs[5] = {&add, &sub, &mul, &div, &mod}; // cover function

    for (int i = 0; i < sizeof(assembly)/sizeof(instruction); i++) { // executes all instructions
        printf("Instruction 0x%02x: %d\n", assembly[i].code, funcs[assembly[i].code](assembly[i].arga, assembly[i].argb, assembly[i].argc));
    }
    printf("\nInstructions:\n");
    for (int i = 0; i < sizeof(assembly)/sizeof(instruction); i++) {
        printf("%02x%02x%02x%02x\n", assembly[i].code, assembly[i].arga, assembly[i].argb, assembly[i].argc);
    }
    printf("\n");
}