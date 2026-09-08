#include "PluginEditor.h"
MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    setResizable(true, true);
    addAndMakeVisible(webView);
    webView.goToURL(webView.getResourceProviderRoot());
}
MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
