#include "PluginProcessor.h"
#include "PluginEditor.h"

MusicStudioAudioProcessor::MusicStudioAudioProcessor()
    : AudioProcessor(BusesProperties().withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

MusicStudioAudioProcessor::~MusicStudioAudioProcessor() {}

juce::AudioProcessorEditor* MusicStudioAudioProcessor::createEditor()
{
    return new MusicStudioAudioProcessorEditor(*this);
}

// THIS WAS MISSING - THIS FIXES LNK2019!
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MusicStudioAudioProcessor();
}
