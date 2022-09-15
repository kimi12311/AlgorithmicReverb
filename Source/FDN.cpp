
#define _USE_MATH_DEFINES 
#include "FDN.hpp"

FDN::FDN()
{
    fractionalDelay1.setDelaySamples(1789.0f);
    fractionalDelay2.setDelaySamples(2749.0f);
}

// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel)
{
    
    float y;

    //Recombine feedback

    float inDL1 = x + fb1[channel];
    float inDL2 = x + fb2[channel];
    float inDL3 = x + fb3[channel];
    float inDL4 = x + fb4[channel];

    //Process individual lines

    float outDL1 = fractionalDelay1.processSample(inDL1, channel);
    float outDL2 = fractionalDelay2.processSample(inDL2, channel);
    float outDL3 = fractionalDelay3.processSample(inDL3, channel);
    float outDL4 = fractionalDelay3.processSample(inDL4, channel);

    //Output variable

    y = 0.25f * (outDL1 + outDL2 + outDL3 + outDL4);

    //Feedback matrix

    fb1[channel] = (-outDL2 + outDL3) * fbGain;
    fb2[channel] = (outDL1 + outDL4) * fbGain;
    fb3[channel] = (outDL1 + -outDL4) * fbGain;
    fb4[channel] = (-outDL2 + -outDL3) * fbGain;

    return y;
}

void FDN::setFs(float Fs)
{
    this->Fs = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
}


void FDN::setDepth(float depth)
{

    this->depth = depth;
    fractionalDelay1.setDepth(depth);
    fractionalDelay2.setDepth(depth);
    fractionalDelay3.setDepth(depth);
    fractionalDelay4.setDepth(depth);
}

void FDN::setTime(float time) 
{
    fbGain = time;
}
