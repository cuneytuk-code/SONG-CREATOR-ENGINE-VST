#include "PluginProcessor.h"
#include "PluginEditor.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    setResizable(true, true);
    setResizeLimits(1200, 700, 3000, 2000);

    addAndMakeVisible(webView);

    // Load HTML - during development load from Resources folder
    auto htmlFile = juce::File::getCurrentWorkingDirectory().getChildFile("Resources").getChildFile("index.html");
    if (!htmlFile.existsAsFile())
    {
        // Try relative to binary
        htmlFile = juce::File::getSpecialLocation(juce::File::currentApplicationFile)
            .getParentDirectory().getChildFile("..").getChildFile("..").getChildFile("Resources").getChildFile("index.html");
    }
    
    if (htmlFile.existsAsFile())
    {
        webView.goToURL(juce::WebBrowserComponent::getResourceProviderRoot() + "index.html");
        // Alternative: webView.goToURL(htmlFile.getFullPathName());
    }
    else
    {
        // Fallback: load from embedded string - replace with your HTML
        webView.goToURL(juce::WebBrowserComponent::getResourceProviderRoot());
    }
}

MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}

void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MusicStudioAudioProcessorEditor::resized()
{
    webView.setBounds(getLocalBounds());
}
