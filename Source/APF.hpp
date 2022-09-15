
#ifndef APF_hpp
#define APF_hpp

#include "FractionalDelay.hpp"
using namespace std;

class APF {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    APF();

    APF(float delaySamples, float speed);

    // Destructor
    ~APF();

    //Methods
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDepth(float depth);

    void setFeedbackGain(float time);

    double PI = 3.14159265358979323846;;

    void setDelay(float Delay) {
        fractionalDelay.setDelaySamples(Delay);
    }

    void setSpeed(float speed) {
        fractionalDelay.setSpeed(speed);
    }

    
private:

    //Sample Rate
    
    float Fs = 48000.f;

    //Delay Instances (Delay in Samples, Mod Speed)

    FractionalDelay fractionalDelay {240.f, 0.7f};
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO

    float fbGain = 0.5f;

    //Defining feedback paths

    float fb1[2] = { 0.f };

};



#endif /* APF_hpp */
