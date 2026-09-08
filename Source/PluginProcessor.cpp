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
