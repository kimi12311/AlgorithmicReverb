
#ifndef FBCF_hpp
#define FBCF_hpp

#include "FractionalDelay.hpp"
#include "APF.hpp"
using namespace std;

class FBCF {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FBCF();

    FBCF(float delaySamples, float speed);

    FBCF(float delaySamples, float speed, float apfDelay, float apfSpeed);

    // Destructor
    ~FBCF();

    //Methods
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDepth(float depth);

    void setFeedbackGain(float time);

    double PI = 3.14159265358979323846;;

    
private:

    //Sample Rate
    
    float Fs = 48000.f;

    //Delay Instances (Delay in Samples, Mod Speed)

    FractionalDelay fractionalDelay {240.f, 0.7f};
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO

    float fbGain = 0.5f;

    //Defining feedback paths

    float fb1[2] = { 0.f };


    class simpleLPF 
    {

    public:

        float processSample(float x, int channel) 
        {
            float y = 0.5f * x + 0.5f * ff[channel];
            ff[channel] = x;
            return y;
        };

    private:

        float ff[2] = { 0.1f };

    };

    simpleLPF lpf;
    APF apf;
};





#endif /* FBCF_hpp */
