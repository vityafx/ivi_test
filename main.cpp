//#include <stdio.h>
#include <iostream>

#include <unistd.h>

#include "testcamera.h"
#include "pipeprocessor.h"


int main()
{
    if (fork() == 0) {
        PipeProcessor *pipeProcessor = PipeProcessor::instance();
        TestCamera *camera = new TestCamera(pipeProcessor);
        pipeProcessor->addObserver(camera);
        pipeProcessor->run();

        delete camera;
    }

    return 0;
}
