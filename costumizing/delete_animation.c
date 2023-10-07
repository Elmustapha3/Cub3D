/*#include <stdio.h>
#include <unistd.h>

int	main(void) {
    printf("Deleting files: [");
    fflush(stdout);  // flush stdout to ensure prompt display

    // Simulate deleting animation
    int i;
    for (i = 0; i < 20; i++) {
        usleep(100000);  // sleep for 100ms
        printf("\033[1D");  // move cursor back one character
        printf("%c", i % 2 == 0 ? '|' : '\\');
        printf("%c", i % 2 == 0 ? '/' : '\\'); // alternate between '|' and '-'
        fflush(stdout);  // flush stdout to ensure prompt display
    }

    printf("]\n");  // print final message
    return (0);
}*/
