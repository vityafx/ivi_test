#ifndef TESTCAMERA_H
#define TESTCAMERA_H

#include "icamera.h"
#include "testled.h"
#include "icommandsender.h"
#include "pipeobserver.h"

class TestCamera : public ICamera, public PipeObserver
{
private:
    ICommandSender *_commandSender;

    void setCommands();
public:
    TestCamera();
    TestCamera(ICommandSender *);

    void setCommandSender(ICommandSender *);
    ICommandSender *commandSender() const;

    void onPipeDataReceived(std::string);
};

#endif // TESTCAMERA_H
