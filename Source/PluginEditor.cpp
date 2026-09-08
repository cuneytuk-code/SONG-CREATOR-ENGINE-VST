#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    addAndMakeVisible(webView);
    auto html = juce::String::fromUTF8(BinaryData::index_html, BinaryData::index_htmlSize);
    auto url = juce::String("data:text/html,") + juce::URL::addEscapeChars(html, false);
    webView.goToURL(url);
}
MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
