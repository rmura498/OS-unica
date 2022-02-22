//
// Created by Raffaele Mura on 22/02/22.
//

#ifndef OS_UNICA_SERVER_H
#define OS_UNICA_SERVER_H

#define PIPE "/tmp/pipe_file_processing"

typedef struct {
    char filename[100];
    char private_pipe[100];

} message;



#endif //OS_UNICA_SERVER_H
