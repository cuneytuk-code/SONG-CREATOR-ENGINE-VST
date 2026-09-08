#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    setResizable(true, true);
    addAndMakeVisible(webView);
    
    // Load the real HTML from BinaryData as data URL
    juce::String html = juce::String::fromUTF8(BinaryData::index_html, BinaryData::index_htmlSize);
    webView.goToURL("data:text/html;base64," + juce::Base64::toBase64(html.toRawUTF8(), html.getNumBytesAsUTF8()));
}

MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
