
#define _USE_MATH_DEFINES 
#include "FBCF.hpp"

FBCF::FBCF()
{

}

FBCF::FBCF(float sampleDelay, float speed)
{
    fractionalDelay.setDelaySamples(sampleDelay);
    fractionalDelay.setSpeed(speed);
}

FBCF::FBCF(float sampleDelay, float speed, float apfDelay, float apfSpeed)
{
    fractionalDelay.setDelaySamples(sampleDelay);
    fractionalDelay.setSpeed(speed);
    apf.setDelay(apfDelay);
    apf.setSpeed(apfSpeed);
    apf.setFeedbackGain(0.2f);
    apf.setDepth(3.1343f);
}

// Destructor
FBCF::~FBCF(){
}




float FBCF::processSample(float x, int channel)
{
    
    float y;

    //Recombine feedback

    float inDL1 = x + (-fbGain) * fb1[channel];

    //Process individual lines

    float outDL1 = fractionalDelay.processSample(inDL1, channel);

    //Output variable

    y = outDL1;

    //Feedback matrix

    fb1[channel] = apf.processSample(outDL1, channel);
    fb1[channel] = apf.processSample(outDL1, channel);
    fb1[channel] = lpf.processSample(outDL1, channel);

    return y;
}

void FBCF::setFs(float Fs)
{
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
    apf.setFs(Fs);
}


void FBCF::setDepth(float depth)
{

    this->depth = depth;
    fractionalDelay.setDepth(depth);
}

void FBCF::setFeedbackGain(float time)
{
    fbGain = time;
}
