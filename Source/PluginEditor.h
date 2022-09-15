/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener
{
public:
    AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor&);
    ~AlgoReverbAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AlgoReverbAudioProcessor& processor;

    Slider reverbTimeSlider;
    Label reverbTimeLabel;

    Slider modulationSlider;
    Label modulationLabel;

    Slider wetdrySlider;
    Label wetdryLabel;

    Slider predelaySlider;
    Label predelayLabel;

    Slider diffusionSlider;
    Label diffusionLabel;
    
    Slider lpfSlider;
    Label lpfLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessorEditor)
};
