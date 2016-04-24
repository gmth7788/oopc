#include "String.h"
#include "new.h"

int main ()
{
	printf("%ld\n", sizeof(struct Class));
	void * a = new(String, "a11111"), * aa = clone(a);

	void * b = new(String, "b22222");
	printf("sizeOf(a) == %lu\n", sizeOf(a));
	printf("sizeOf(b) == %lu\n", sizeOf(b));
	printf("sizeOf(aa) == %lu\n", sizeOf(aa));
	if (differ(a, b))
		puts("ok");
	if (differ(a, aa))
		puts("differ?");
	if (a == aa)
		puts("clone?");
	delete(a), delete(aa), delete(b);


	return 0;
}
