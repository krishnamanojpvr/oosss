#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msgbuf
{
    long mtype;      // message type must be > 0
    char mtext[200]; // message data
};
int main()
{
    key_t key = 1234; // predefined key
    int msg_id;
    struct msgbuf msg;
    // Create a message queue
    msg_id = msgget(key, 0666 | IPC_CREAT);
    if (msg_id < 0)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    // Prepare a message to send
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, this message is from sender");
    // Send the message
    if (msgsnd(msg_id, &msg, strlen(msg.mtext), 0) < 0)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
    printf("Sent: %s\n", msg.mtext);
    
    return 0;
}