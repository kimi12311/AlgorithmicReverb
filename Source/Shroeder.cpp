
#define _USE_MATH_DEFINES 
#include "Shroeder.hpp"

Shroeder::Shroeder()
{

}

// Destructor
Shroeder::~Shroeder(){
}




float Shroeder::processSample(float x, int channel)
{
    
    float y;

    //Recombine feedback

    float outFBCF1 = fbcf1.processSample(x, channel);
    float outFBCF2 = fbcf2.processSample(x, channel);
    float outFBCF3 = fbcf3.processSample(x, channel);
    float outFBCF4 = fbcf4.processSample(x, channel);

    float inAPF1 = outFBCF1 + outFBCF2 + outFBCF3 + outFBCF4;

    //Process individual lines

    float outAPF1 = apf1.processSample(inAPF1, channel);

    //Output variable

    y = apf2.processSample(outAPF1, channel);

    //Feedback matrix

    return y;
}

void Shroeder::setFs(float Fs)
{
    this->Fs = Fs;
    fbcf1.setFs(Fs);
    fbcf2.setFs(Fs);
    fbcf3.setFs(Fs);
    fbcf4.setFs(Fs);
    apf1.setFs(Fs);
    apf2.setFs(Fs);
}


void Shroeder::setDepth(float depth)
{

    this->depth = depth;
    fbcf1.setDepth(depth);
    fbcf2.setDepth(depth);
    fbcf3.setDepth(depth);
    fbcf4.setDepth(depth);
    apf1.setDepth(depth);
    apf2.setDepth(depth);
}

void Shroeder::setFeedbackGain(float time)
{
    fbGain = time;
    fbcf1.setFeedbackGain(time);
    fbcf2.setFeedbackGain(time);
    fbcf3.setFeedbackGain(time);
    fbcf4.setFeedbackGain(time);
}

void Shroeder::setDiffusionGain(float _diffusion)
{
    diffusion = _diffusion;
    apf1.setFeedbackGain(_diffusion);
    apf2.setFeedbackGain(_diffusion);
}
