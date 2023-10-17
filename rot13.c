#include "main.h"

void initLow(char lowRot[256]);
void initCaps(char rotMap[256]);
/**
 * rot13 - cyphers string with rot 13 cyphers
 * @str: string to be encrypted
 * @buf: buffer to save rot
 * Return: returs encrypted string
 */
char *rot13(char *buf, char *str)
{
	int i = 0;
	char rotMap[256] = {0};
	char lowRot[256] = {0};


	initCaps(rotMap);
	initLow(lowRot);

	while (str[i])
	{
		if (!(str[i] >= 65 && str[i] <= 90))
		{
			buf[_strlen(buf)] = str[i];
		}
		while (rotMap[(unsigned char)str[i]] || (lowRot[(unsigned char)str[i]]))
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				buf[_strlen(buf)] = rotMap[(unsigned char)str[i]];
				break;
			}
			buf[_strlen(buf)] = lowRot[(unsigned char)str[i]];
			break;
		}

		i++;
	}

	return (buf);

}
/**
 * initLow - initialize map for lowecase
 * @lowRot: array for lowercase
 */
void initLow(char lowRot[256])
{
	lowRot['a'] = 'n';
	lowRot['b'] = 'o';
	lowRot['c'] = 'p';
	lowRot['d'] = 'q';
	lowRot['e'] = 'r';
	lowRot['f'] = 's';
	lowRot['g'] = 't';
	lowRot['h'] = 'u';
	lowRot['i'] = 'v';
	lowRot['j'] = 'w';
	lowRot['k'] = 'x';
	lowRot['l'] = 'y';
	lowRot['m'] = 'z';
	lowRot['n'] = 'a';
	lowRot['o'] = 'b';
	lowRot['p'] = 'c';
	lowRot['q'] = 'd';
	lowRot['r'] = 'e';
	lowRot['s'] = 'f';
	lowRot['t'] = 'g';
	lowRot['u'] = 'h';
	lowRot['v'] = 'i';
	lowRot['w'] = 'j';
	lowRot['x'] = 'k';
	lowRot['y'] = 'l';
	lowRot['z'] = 'm';


}

/**
 * initCaps - initialise lowercse
 * @rotMap: initialize uppercae latters
 */
void initCaps(char rotMap[256])
{
	rotMap['A'] = 'N';
	rotMap['B'] = 'O';
	rotMap['C'] = 'P';
	rotMap['D'] = 'Q';
	rotMap['E'] = 'R';
	rotMap['F'] = 'S';
	rotMap['G'] = 'T';
	rotMap['H'] = 'U';
	rotMap['I'] = 'V';
	rotMap['J'] = 'W';
	rotMap['K'] = 'X';
	rotMap['L'] = 'Y';
	rotMap['M'] = 'Z';
	rotMap['N'] = 'Q';
	rotMap['O'] = 'B';
	rotMap['P'] = 'C';
	rotMap['Q'] = 'D';
	rotMap['R'] = 'E';
	rotMap['S'] = 'F';
	rotMap['T'] = 'G';
	rotMap['U'] = 'H';
	rotMap['V'] = 'I';
	rotMap['W'] = 'J';
	rotMap['X'] = 'K';
	rotMap['Y'] = 'L';
	rotMap['Z'] = 'M';

}
