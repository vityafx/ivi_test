#include "pipeprocessor.h"

PipeProcessor::PipeProcessor()
{
//    int status;

//    if ((status = mkfifo(FIFO_FILE, 0666)) < 0) {
//         printf("FIFO file was not created: %s\n", strerror(errno));
//    }

//    this->_fifo = open(FIFO_FILE, O_RDWR);
//    if (this->_fifo < 0) {
//        printf("Error - can't open fifo file: %s\n", strerror(errno));

//        exit(1);
//    }

//    this->setFifo(this->fifo());
    this->openPipe();
}

PipeProcessor* PipeProcessor::instance()
{
    static PipeProcessor *processor = new PipeProcessor();

    return processor;
}

void PipeProcessor::addObserver(PipeObserver *observer)
{
    this->_observers.push_back(observer);
}

void PipeProcessor::notifyObservers(std::string data) const
{
    for (unsigned short i = 0; i < this->_observers.size(); i++)
    {
        this->_observers[i]->onPipeDataReceived(data);
    }
}

void PipeProcessor::openPipe()
{
    //we don't really care about it so no any check of return code
    mkfifo(FIFO_FILE, 0666);

    this->_fifo = open(FIFO_FILE, O_RDWR);
    if (this->_fifo < 0) {
        printf("Error - can't open fifo file: %s\n", strerror(errno));

        exit(1);
    }

    this->setFifo(this->fifo());
}

void PipeProcessor::run()
{
    int num;
    char temp[1024];

    while (true) {
        if ((num = read(this->_fifo, temp, sizeof(temp))) < 0) {
             printf("Error occured during reading FIFO file: %s\n", strerror(errno));

             exit(2);
        } else {
            if (num < sizeof(temp)) {
                temp[num] = '\0';
            }

            this->notifyObservers(std::string(temp));

            // To let other readers of this file get information we have to close file

            close(this->fifo());
            this->openPipe();
        }
    }
}

int PipeProcessor::fifo() const
{
    return this->_fifo;
}
