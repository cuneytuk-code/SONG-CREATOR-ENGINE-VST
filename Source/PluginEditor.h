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
    std::unique_ptr<juce::WebBrowserComponent> webView;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicStudioAudioProcessorEditor)
};
