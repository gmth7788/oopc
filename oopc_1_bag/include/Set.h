#ifndef SET_H
#define SET_H

extern const void * Set;
extern const void * Object;

void * add (void * set, const void * element);
void * find (const void * set, const void * element);
void * drop (void * set, const void * element);
int contains (const void * set, const void * element);
unsigned int count(const void * _set);

#endif

