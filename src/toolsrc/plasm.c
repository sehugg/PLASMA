#include <stdio.h>
#include "tokens.h"
#include "lex.h"
#include "codegen.h"
#include "parse.h"

int global_flags = 0;

int main(int argc, char **argv)
{
    int j, i, flags = 0;
    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        { 
            j = 1;
            while (argv[i][j])
            {
                switch(argv[i][j++])
                {
                    case 'A':
                        flags |= ACME;
                        break;
                    case 'M':
                        flags |= MODULE;
                        break;
                    case 'Z':
                        flags |= USE_ZONES;
                        break;
                }
            }
        }
    }
    global_flags = flags;
    emit_flags(flags);
    if (parse_module())
    {
        fprintf(stderr, "Compilation complete.\n");
    }
    return (0);
}
