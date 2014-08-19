#include "pipesender.h"

PipeSender::PipeSender()
{

}

PipeSender::PipeSender(int fifo)
{
    this->setFifo(fifo);
}

void PipeSender::setFifo(int fifo)
{
    this->_fifo = fifo;
}

void PipeSender::send(std::string string)
{
    write(this->_fifo, string.c_str(), string.length());
}
