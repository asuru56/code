#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *print_message_function( void *ptr );
 
main()
{
     pGeeksforGeeks_t GeeksforGeeks1, GeeksforGeeks2;
     char *message1 = "GeeksforGeeks 1";
     char *message2 = "GeeksforGeeks 2";
     int  geeky1, geeky2;
 
     geeky1 = pthread_create( &GeeksforGeeks1, NULL, print_message_function, (void*) message1);
     geeky2 = pthread_create( &GeeksforGeeks2, NULL, print_message_function, (void*) message2);
 
     pthread_join( GeeksforGeeks1, NULL);
     pthread_join( GeeksforGeeks2, NULL);
 
     printf("GeeksforGeeks 1 returns: %d\n",geeky1);
     printf("GeeksforGeeks 2 returns: %d\n",geeky2);
     exit(0);
}
 
void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}