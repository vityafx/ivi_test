#ifndef PIPEOBSERVER_H
#define PIPEOBSERVER_H

class PipeObserver
{
public:
    virtual void onPipeDataReceived(std::string) = 0;
};

#endif // PIPEOBSERVER_H
