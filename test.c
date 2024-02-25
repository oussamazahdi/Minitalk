#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGUSR1
void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal\n");
}

// Signal handler for SIGUSR2
void sigusr2_handler(int signum) {
    printf("Received SIGUSR2 signal\n");
}

int main() {
    // Register signal handlers
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    // Print the process ID
    int pid = getpid();
    printf("My PID is: %d\n", pid);

    // Simulate a long-running process
    printf("Running...\n");
    if (kill(pid, SIGUSR1) == 0) {
        printf("SIGUSR1 signal sent successfully to PID %d\n", pid);
    } else {
        perror("Error sending SIGUSR1 signal");
        return 1;
    }
    // while(1) {
    //     kill (SIGUSR1, pid);
    //     sleep(1);
    // }

    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>

// // Signal handler function for SIGINT
// void sigint_handler(int signum) {
//     printf("Caught SIGINT signal (Ctrl+C)\n");
//     // Optionally, you can perform cleanup or other actions here
//     exit(signum); // Exit the program with the signal number
// }

// int main() {
//     // Define the new action for SIGINT
//     struct sigaction new_action;
//     new_action.sa_handler = sigint_handler;
//     sigemptyset(&new_action.sa_mask); // Clear the signal mask
//     new_action.sa_flags = 0; // No special flags

//     // Install the new action for SIGINT
//     if (sigaction(SIGINT, &new_action, NULL) == -1) {
//         perror("sigaction");
//         return 1;
//     }

//     // Loop indefinitely
//     printf("Press Ctrl+C to trigger SIGINT signal\n");
//     while (1) {}

//     return 0;
// }

