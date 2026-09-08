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
    juce::WebBrowserComponent webView{juce::WebBrowserComponent::Options{}
        .withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
        .withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}
            .withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory))
        )
        .withResourceProvider([this](const juce::String& url) -> std::optional<juce::WebBrowserComponent::Resource>
        {
            if (url == "/" || url == "/index.html")
            {
                // Load embedded HTML from binary data
                extern const char* index_html;
                extern const int index_htmlSize;
                // Fallback: load from Resources folder during dev
                auto file = juce::File::getCurrentWorkingDirectory().getChildFile("Resources").getChildFile("index.html");
                if (!file.existsAsFile())
                    file = juce::File::getSpecialLocation(juce::File::currentApplicationFile)
                        .getParentDirectory().getChildFile("Resources").getChildFile("index.html");
                
                if (file.existsAsFile())
                {
                    return juce::WebBrowserComponent::Resource{ file.loadFileAsString().toRawUTF8(), "text/html" };
                }
                
                // Embedded fallback - will be replaced by binary data
                return std::nullopt;
            }
            return std::nullopt;
        })
        .withNativeIntegrationEnabled()
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicStudioAudioProcessorEditor)
};
