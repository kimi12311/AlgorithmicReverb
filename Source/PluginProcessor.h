/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#include "FDN.hpp"
#include "APF.hpp"
#include "Shroeder.hpp"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AlgoReverbAudioProcessor();
    ~AlgoReverbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float preDelayMS = 0.0f;
    float currentSampleRate = 44100;
    float drywet = 0.5f;
    float verbTime = 0.5f;
    float depth = 0.5f;
    float diffusion = 0.2f;

private:

    FractionalDelay predelay;
    //FDN fdn;
    //APF apf1{240.f, 0.928f};
    //APF apf2{82.f, 0.3802f};
    Shroeder shroeder;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessor)
};
