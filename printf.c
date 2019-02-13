
#include <stdio.h>
#include <stdarg.h>

int va_str_printer(int count, ...);


int va_str_printer(int count, ...)
{
	va_list ap;
	int i;

	va_start(ap, count);
	for(i = 0; i < count; i++)
	{
		char *str = va_arg(ap, char*);
		printf("%s\n", str);
	}
	va_end(ap);

	return count;
}

int main()
{
	va_str_printer(5,"string","printer","to","number of","strings");
	
	return 0;
}
