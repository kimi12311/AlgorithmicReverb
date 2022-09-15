
#ifndef Shroeder_hpp
#define Shroeder_hpp

#include "FBCF.hpp"
#include "APF.hpp"

using namespace std;

class Shroeder {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    Shroeder();

    // Destructor
    ~Shroeder();

    //Methods
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDepth(float depth);

    void setFeedbackGain(float time);
    void setDiffusionGain(float diffusion);

    double PI = 3.14159265358979323846;;

    
private:

    //Sample Rate
    
    float Fs = 48000.f;

    //Instance of Components needed for model

    FBCF fbcf1{1426.f, 0.7203f, 163.f, 0.2459f};
    FBCF fbcf2{1781.f, 1.2094, 271.f, 0.7403};
    FBCF fbcf3{1973.f, 0.98747, 83.f, 0.53322f};
    FBCF fbcf4{2098.f, 1.18049, 307.f, 0.10354};

    APF apf1{ 240.f, 0.928f };
    APF apf2{ 82.f, 0.3802f };
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO

    float fbGain = 0.5f;
    float diffusion = 0.4f;
};



#endif /* Shroeder_hpp */
