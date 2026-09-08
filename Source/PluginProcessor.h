#pragma once
#include "PluginProcessor.h"
#include <juce_gui_extra/juce_gui_extra.h>

class MusicStudioAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor&);
    ~MusicStudioAudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    juce::WebBrowserComponent webView { juce::WebBrowserComponent::Options{}.withBackend(juce::WebBrowserComponent::Options::Backend::webview2).withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}.withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory))) };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicStudioAudioProcessorEditor)
};
