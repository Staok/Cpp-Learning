#include"Alloctor.h"
#include<stdlib.h>

void* operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void* p)
{
	free(p);
}

void* operator new[](size_t size)
{
	return malloc(size);
}

void operator delete[](void* p)
{
	free(p);
}

void* mem_alloc(size_t size)
{
	return malloc(size);
}

void mem_free(void* p)
{
	free(p);
}