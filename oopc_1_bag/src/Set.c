#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"


struct Set
{
	unsigned int count; //集合中元素的个数
};

struct Object
{
	unsigned int count; //对象被加入集合的次数
	                                  //每调用一次drop()减1，
	                                  //当为0时，删除此对象。
	struct Set *in; //指向集合的指针
};

static const size_t _Set =sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void * Set = & _Set;
const void * Object = & _Object;

void * new (const void * type, ...)
{
	const size_t size = *(const size_t *) type;

	void *p = calloc(1, size);

	assert(p);
	return (p);
}

void delete (void * p)
{
	free(p);
}

void * add (void * _set, const void * _element)
{
	struct Set * set = _set;
	struct Object * element = (void *)_element;

	assert(set);
	assert(element);

	if (!element->in)
	{
		element->in = set;
	}
	else
	{
		assert(element->in == set);
	}

	set->count++;
	element->count++;

	return element;
}

void * find (const void * _set, const void * _element)
{
	struct Set * set = (void *)_set;
	struct Object * element = (void *)_element;

	assert(set);
	assert(element);

	return (element->in == set) ? (void *)element : 0;
}

int contains (const void * _set, const void * _element)
{
	return find(_set, _element) != 0;
}

void * drop (void * _set, const void * _element)
{
	struct Set * set = (void *)_set;
	struct Object * element = (void *)_element;

	if (element)
	{
		if (-- element->count  == 0)
		{
			element->in = 0;
		}
		-- set->count;
	}

	return element;
}

int differ (const void * a, const void * b)
{
	return a != b;
}

unsigned int count(const void * _set)
{
	const struct Set *set = _set;

	assert(set);

	return set->count;
}


