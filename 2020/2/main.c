#include <stdio.h>

int main()
{
    int min, max, n, nvalids = 0, new_valids = 0;
    char must_incl, *p;
    char pass[50];

    while (scanf("%d-%d %c: %s", &min, &max, &must_incl, pass) != EOF) {
        p = pass;
        n = 0;

        while (*p)
            if (*p++ == must_incl)
                n++;
        if (n >= min && n <= max)
            nvalids++;

        if (pass[min - 1] == must_incl ^ pass[max - 1] == must_incl)
            new_valids++;
    }

    printf("number of valid passwords: %d\n", nvalids);
    printf("number of new valid passwords: %d\n", new_valids);
        
}
