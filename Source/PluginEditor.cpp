/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    //Reverb time slider
    reverbTimeSlider.addListener(this);
    reverbTimeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbTimeSlider.setBounds(50, 30, 100, 100);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    reverbTimeSlider.setRange(0.4f, 0.9f, 0.01f);
    reverbTimeSlider.setValue(0.5f);
    addAndMakeVisible(reverbTimeSlider);

    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);

    //Modulation slider
    modulationSlider.addListener(this);
    modulationSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    modulationSlider.setBounds(150, 30, 100, 100);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modulationSlider.setRange(1.0f, 30.0f, 0.01f);
    modulationSlider.setValue(1.f);
    addAndMakeVisible(modulationSlider);

    modulationLabel.setText("Modulation", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider, false);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);

    //DryWet slider
    wetdrySlider.addListener(this);
    wetdrySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    wetdrySlider.setBounds(250, 30, 100, 100);
    wetdrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    wetdrySlider.setRange(0.0f, 1.0f, 0.01f);
    wetdrySlider.setValue(0.5f);
    addAndMakeVisible(wetdrySlider);

    wetdryLabel.setText("Wet/Dry", dontSendNotification);
    wetdryLabel.attachToComponent(&wetdrySlider, false);
    wetdryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetdryLabel);

    //Predelay slider
    predelaySlider.addListener(this);
    predelaySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    predelaySlider.setBounds(50, 180, 100, 100);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    predelaySlider.setRange(0.0f, 200.0f, 0.1f);
    predelaySlider.setValue(0.0f);
    addAndMakeVisible(predelaySlider);

    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);

    //Diffusion slider
    diffusionSlider.addListener(this);
    diffusionSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    diffusionSlider.setBounds(150, 180, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.2f, 0.7f, 0.01f);
    diffusionSlider.setValue(0.5f);
    addAndMakeVisible(diffusionSlider);

    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);


    //LPF slider
    lpfSlider.addListener(this);
    lpfSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lpfSlider.setBounds(250, 180, 100, 100);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setRange(20, 20000, 1);
    lpfSlider.setValue(20000);
    addAndMakeVisible(lpfSlider);

    lpfLabel.setText("Low Pass", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);

    //LookAndFeel Overrides

    getLookAndFeel().setColour(Slider::thumbColourId, Colours::azure);
    getLookAndFeel().setColour(Slider::rotarySliderFillColourId, Colours::darkmagenta);
    getLookAndFeel().setColour(Slider::rotarySliderOutlineColourId, Colours::violet);
    getLookAndFeel().setColour(Slider::textBoxOutlineColourId, Colours::darkmagenta);
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::darkviolet);
}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider* slider) 
{
    if (slider == &predelaySlider) 
    {
        processor.preDelayMS = predelaySlider.getValue();
    }
    if (slider == &wetdrySlider) 
    {
        processor.drywet = wetdrySlider.getValue();
    }
    if (slider == &reverbTimeSlider) 
    {
        processor.verbTime = reverbTimeSlider.getValue();
    }
    if (slider == &modulationSlider) 
    {
        processor.depth = modulationSlider.getValue();
    }
    if (slider == &diffusionSlider) 
    {
        processor.diffusion = diffusionSlider.getValue();
    }
}