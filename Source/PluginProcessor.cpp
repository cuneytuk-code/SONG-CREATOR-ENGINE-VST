#include "PluginProcessor.h"
#include "PluginEditor.h"

MusicStudioAudioProcessor::MusicStudioAudioProcessor()
    : AudioProcessor(BusesProperties().withOutput("Output", juce::AudioChannelSet::stereo(), true)) {}
MusicStudioAudioProcessor::~MusicStudioAudioProcessor() {}
const juce::String MusicStudioAudioProcessor::getName() const { return "Music Studio"; }
bool MusicStudioAudioProcessor::acceptsMidi() const { return true; }
bool MusicStudioAudioProcessor::producesMidi() const { return false; }
bool MusicStudioAudioProcessor::isMidiEffect() const { return false; }
double MusicStudioAudioProcessor::getTailLengthSeconds() const { return 0.0; }
int MusicStudioAudioProcessor::getNumPrograms() { return 1; }
int MusicStudioAudioProcessor::getCurrentProgram() { return 0; }
void MusicStudioAudioProcessor::setCurrentProgram(int) {}
const juce::String MusicStudioAudioProcessor::getProgramName(int) { return {}; }
void MusicStudioAudioProcessor::changeProgramName(int, const juce::String&) {}
void MusicStudioAudioProcessor::prepareToPlay(double, int) {}
void MusicStudioAudioProcessor::releaseResources() {}
bool MusicStudioAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
void MusicStudioAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) { buffer.clear(); }
juce::AudioProcessorEditor* MusicStudioAudioProcessor::createEditor() { return new MusicStudioAudioProcessorEditor(*this); }
bool MusicStudioAudioProcessor::hasEditor() const { return true; }
void MusicStudioAudioProcessor::getStateInformation(juce::MemoryBlock&) {}
void MusicStudioAudioProcessor::setStateInformation(const void*, int) {}
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new MusicStudioAudioProcessor(); }
