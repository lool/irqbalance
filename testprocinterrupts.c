#include <stdio.h>
#include <stdlib.h>

#include "irqbalance.h"

int test_parse_proc_interrupts(const char *data_path)
{
        proc_interrupts_path = data_path;
        fprintf(stderr, "Testing parse_proc_interrupts with %s...\n", data_path);
        /* no failure detection right now – might also crash or go into an
         * infinite loop */
        parse_proc_interrupts();
        return 0;
}

int main(void)
{
        int err = 0;

        if (test_parse_proc_interrupts("tests/interrupts-data-tegra") != 0) {
            err = 1;
        }
        if (test_parse_proc_interrupts("tests/interrupts-data-vm") != 0) {
            err = 1;
        }

        return (err == 0) ? 0 : -1;
}
