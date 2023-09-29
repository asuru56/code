#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main() {
    mqd_t mq;
    struct mq_attr attr;
    char buffer[1024];  // Buffer to hold the received message

    // Message queue attributes
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;  // Maximum number of messages in the queue
    attr.mq_msgsize = sizeof(buffer);  // Maximum message size

    // Create or open an existing message queue
    mq = mq_open("/my_message_queue", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    // Sending a message
    const char *message_to_send = "42";
    if (mq_send(mq, message_to_send, strlen(message_to_send) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    // Receiving a message
    ssize_t bytes_received = mq_receive(mq, buffer, sizeof(buffer), NULL);
    if (bytes_received == -1) {
        perror("mq_receive");
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Close and remove the message queue
    mq_close(mq);
    mq_unlink("/my_message_queue");

    return 0;
}
