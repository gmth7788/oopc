/*
 * 《Object-Oriented Programming With ANSI-C》
 *     Chapter 1
 *          1.7 An Implementation — Set
 *
 */


#include <stdio.h>
#include "new.h"
#include "Object.h"
#include "Set.h"

const void * Set;
const void * Object;

int main ()
{
	void * s = new(Set);
	void * a = add(s, new(Object));
	void * b = add(s, new(Object));
	void * c = new(Object);

	if (contains(s, a) && contains(s, b))
		puts("ok");

	if (contains(s, c))
		puts("contains?");

	if (differ(a, add(s, a)))
		puts("differ?");

	if (contains(s, drop(s, a)))
		puts("drop?");

	delete(drop(s, b));
	delete(drop(s, c));

	return 0;
}
