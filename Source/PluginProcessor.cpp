/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessor::AlgoReverbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AlgoReverbAudioProcessor::~AlgoReverbAudioProcessor()
{
}

//==============================================================================
const String AlgoReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AlgoReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AlgoReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AlgoReverbAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AlgoReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AlgoReverbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AlgoReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AlgoReverbAudioProcessor::setCurrentProgram (int index)
{
}

const String AlgoReverbAudioProcessor::getProgramName (int index)
{
    return {};
}

void AlgoReverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AlgoReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    predelay.setFs(sampleRate);
    predelay.setDelaySamples(0.0f);
    currentSampleRate = sampleRate;
    //fdn.setFs(sampleRate);
    //fdn.setTime(verbTime);
    //apf1.setFs(sampleRate);
    //apf2.setFs(sampleRate);
    shroeder.setFs(sampleRate);
}

void AlgoReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AlgoReverbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AlgoReverbAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{

    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    predelay.setSpeed(0);
    predelay.setDepth(0);

   // fdn.setTime(verbTime);

    float predelaySec = preDelayMS * 0.001;
    float predelaySamples = predelaySec * currentSampleRate;

    predelay.setDelaySamples(predelaySamples);

    //fdn.setDepth(depth);
    //apf1.setDepth(depth);
    //apf2.setDepth(depth);
    //apf1.setFeedbackGain(diffusion);
    //apf2.setFeedbackGain(diffusion);

    shroeder.setFeedbackGain(verbTime);
    shroeder.setDiffusionGain(diffusion);
    shroeder.setDepth(depth);

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            float x = buffer.getWritePointer(channel)[i];

            float reverb = predelay.processSample(x, channel);

            //reverb = fdn.processSample(reverb, channel);
            //reverb = apf1.processSample(reverb, channel);
            //reverb = apf2.processSample(reverb, channel);

            reverb = shroeder.processSample(reverb, channel);

            float output = (1.f - drywet) * x + drywet * reverb;

            buffer.getWritePointer(channel)[i] = output;
        }
    }
}

//==============================================================================
bool AlgoReverbAudioProcessor::hasEditor() const
{
    return true; 
}

AudioProcessorEditor* AlgoReverbAudioProcessor::createEditor()
{
    return new AlgoReverbAudioProcessorEditor (*this);
}

//==============================================================================
void AlgoReverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{

}

void AlgoReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{

}


AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AlgoReverbAudioProcessor();
}
