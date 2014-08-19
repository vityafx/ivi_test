#ifndef PIPEPROCESSOR_H
#define PIPEPROCESSOR_H

#include <vector>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#include "pipeobserver.h"
#include "pipesender.h"

#define FIFO_FILE "/tmp/ivideon_pipe"

class PipeProcessor : public PipeSender
{
private:
    int _fifo;
    std::vector<PipeObserver*> _observers;

    PipeProcessor();

    void notifyObservers(std::string) const;
    void openPipe();
public:
    static PipeProcessor* instance();

    void addObserver(PipeObserver *);

    int fifo() const;

    void run();
};

#endif // PIPEPROCESSOR_H
