
#ifndef FDN_hpp
#define FDN_hpp

#include "FractionalDelay.hpp"
using namespace std;

class FDN {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FDN();

    // Destructor
    ~FDN();

    //Methods
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDepth(float depth);

    void setTime(float time);

    double PI = 3.14159265358979323846;;

    
private:

    //Sample Rate
    
    float Fs = 48000.f;

    //Delay Instances (Delay in Samples, Mod Speed)

    FractionalDelay fractionalDelay1 {2179.f, 0.7f};
    FractionalDelay fractionalDelay2 { 1583.f, 0.2f };
    FractionalDelay fractionalDelay3 {3517.f, 1.2f};
    FractionalDelay fractionalDelay4{ 5483.f, 0.4f };
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO

    float fbGain = 0.5f;

    //Defining feedback paths

    float fb1[2] = { 0.f };
    float fb2[2] = { 0.f };
    float fb3[2] = { 0.f };
    float fb4[2] = { 0.f };

};



#endif /* FDN_hpp */
