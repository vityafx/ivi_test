#include "testcamera.h"
#include "setrefreshratecommand.h"
#include "setcolorcommand.h"
#include "setstatecommand.h"
#include "getrefreshratecommand.h"
#include "getcolorcommand.h"
#include "getstatecommand.h"

TestCamera::TestCamera()
{
    this->setLedController(new TestLed());

    this->setCommands();
}

TestCamera::TestCamera(ICommandSender *sender)
{
    this->setCommandSender(sender);

    this->setLedController(new TestLed());

    this->setCommands();
}

void TestCamera::setCommands()
{
    this->addCommand(new SetRefreshRateCommand(this, this->commandSender()));
    this->addCommand(new SetColorCommand(this, this->commandSender()));
    this->addCommand(new SetStateCommand(this, this->commandSender()));

    this->addCommand(new GetRefreshRateCommand(this, this->commandSender()));
    this->addCommand(new GetColorCommand(this, this->commandSender()));
    this->addCommand(new GetStateCommand(this, this->commandSender()));
}

void TestCamera::onPipeDataReceived(std::string newData)
{
    this->processCommand(newData);
}

void TestCamera::setCommandSender(ICommandSender *sender)
{
    this->_commandSender = sender;
}

ICommandSender* TestCamera::commandSender() const
{
    return this->_commandSender;
}
