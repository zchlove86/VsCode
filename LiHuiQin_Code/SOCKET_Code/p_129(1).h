#ifndef P_129_H_
#define P_127_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>//notation
#define NAMESIZE 11
#define RCVPORT "1989"//when  and using atoi()
struct msg_st
{
    uint8_t name[NAMESIZE];
    uint32_t math;
    uint32_t chinese;
};//_attribute_((packed))

#endif