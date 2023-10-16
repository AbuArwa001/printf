#include "main.h"
char *str_buff(char *buf, int no, int len)
{
	int i = 0, ble = _strlen(buf), count = 0;
	count = (ble + len - 1);

	if (sizeof(no) != 4)
	{
		printf("FAILED IN STR_BUFF NOT NO.\n");
		exit(2);
	}

	for (i = ble; i <= count ; i++)
	{
		if (no < 10)
		{
			buf[i] = (no + '0');
		}
		else
		{
			buf[i] = (no / 10) + '0';
			no %= 10;
		}
	}

	buf[len + ble] = '\0';
	return (buf);

}
int int_len(int n)
{
	int i = 0;

	for (i = 0; n != 0; i++)
	{
		n /= 10;
	}

	return (i);

}