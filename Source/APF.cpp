
#define _USE_MATH_DEFINES 
#include "APF.hpp"

APF::APF()
{

}

APF::APF(float sampleDelay, float speed) 
{
    fractionalDelay.setDelaySamples(sampleDelay);
    fractionalDelay.setSpeed(speed);
}

// Destructor
APF::~APF(){
}




float APF::processSample(float x, int channel)
{
    
    float y;

    //Recombine feedback

    float inDL1 = x + (-fbGain) * fb1[channel];

    //Process individual lines

    float outDL1 = fractionalDelay.processSample(inDL1, channel);

    //Output variable

    y = outDL1 + fbGain * inDL1;

    //Feedback matrix

    fb1[channel] = outDL1;

    return y;
}

void APF::setFs(float Fs)
{
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
}


void APF::setDepth(float depth)
{

    this->depth = depth;
    fractionalDelay.setDepth(depth);
}

void APF::setFeedbackGain(float time)
{
    fbGain = time;
}
