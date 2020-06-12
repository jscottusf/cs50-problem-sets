#include <cs50.h>
#include <stdio.h>

void mario(int height);

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    mario(n);

}

void mario(int height)
{
    int block = 1;
    string innerSpace = "  ";
    int outerSpace = height - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < outerSpace; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < block; k++)
        {
            printf("#");
        }
        printf("%s", innerSpace);
        for (int l = 0; l < block; l++)
        {
            printf("#");
        }
        block++;
        outerSpace--;
        printf("\n");
    }
}