#include <stdio.h>   // standard C input/output library
#include <signal.h>  // signal library
#include <unistd.h>  // Process Control
#include <stdlib.h>  // Process Control
#include <stdbool.h> // allows for bool variable to be used as defined

/* Author: Omar Mousa
 * Student ID #: 006181240
 * Subject : CMPE 142: Operating Systems
 * Assignment: Homework #4 create a program that runs an infinite loop that sleeps for 2 seconds
 *             send program a Signal of SIGINT to count each iteration through the loop
 *             sending a SIGUSR1 signal should terminate the program.
 * /

/* ||======================================================||
   ||                   Global Variable                    ||
   ||======================================================|| */
/* allows the toggle boolean variable to work as defined */
bool toggle = false;

/* ||======================================================||
   ||                 Signal Handler                       ||
   ||======================================================|| */

void handleMySignal(int _mySignal)
{
  /* signal SIGINT condition */
  if(_mySignal == SIGINT)
  {
    printf("\nSignal SIGINT received\n");
    toggle = !toggle;
  }
/* signal SIGUSR1 condition */
  if(_mySignal == SIGUSR1)
  {
    printf("\nSignal SIGUSR1 received\nProgram Terminated\n");
    exit(0);
  }

}

/* ||======================================================||
   ||                 Code Body Main Function              ||
   ||======================================================|| */

int main(int argv, char *argc[])
{
  int count = 0;

    /* SIGINT Error check */
     if(signal(SIGINT,handleMySignal) == SIG_ERR)
    {
      printf("\nSignal SIGINT was not caught\n");
    }

    /* SIGUSR1 Error Check */
    if(signal(SIGUSR1,handleMySignal) == SIG_ERR)
    {
      printf("\nSignal SIGUSR1 was not caught\n");
    }

/* infinite loop of iterations */
    do{
        count++;
        /* toggle flagged for signal SIGINT falls true */
        if(toggle == true)
        {
          /* prints out the number of iterations */
          printf("\n Iteration #: %i \n\n", count);
        }
        /* sleeps process for 2 seconds as asked per assignment */
        sleep(2);
        /* end of infinite do-while loop */
    }while(1);
return 0;
}

