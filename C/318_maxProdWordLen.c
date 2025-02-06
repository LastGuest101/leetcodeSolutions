#include <stdio.h>
#include <string.h>

int maxProduct();
int main (int argc, char** argv)
{
 char * words[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
 maxProduct(words, 6);

    return 0;
}

#include <stdio.h>
#include <string.h>

int map_letters(char* str)
{
    int map = 0;
	int i;

	for (i=0;i<strlen(str);i++)
	{
		map |= 1<<(str[i] - 'a'); 
	}

	return map;
}

int maxProduct(char** words, int wordsSize) 
{ 
    int i,j,product;
    int result = 0;

    int *maps = (int *) calloc(wordsSize,sizeof(int));

    for (i=0;i<wordsSize;i++)
    {
        maps[i] = map_letters(words[i]);
    }


     for (i=0;i<(wordsSize-1);i++)
    {
        for (j=i+1;j<wordsSize;j++)
        {

            if (!(maps[i] & maps[j]))
            {
                product = strlen(words[i]) * strlen(words[j]);

                if (product>result)  
                {
                    result = product;
                }
            }
        }
    }

    free((void *)maps);

    return result;
}