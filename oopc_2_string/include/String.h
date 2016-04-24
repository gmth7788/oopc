#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

extern const void *String;

struct String{
	const void *class; //每个对象都起始于指向类型描述符的指针
	char *text;
};




#endif /*STRING_H*/


