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
    juce::WebBrowserComponent webView { juce::WebBrowserComponent::Options{}
       .withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
       .withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}.withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory)))
       .withResourceProvider([](const juce::String& url) -> std::optional<juce::WebBrowserComponent::Resource> {
            if (url == "/" || url.contains("index.html")) {
                auto* data = BinaryData::index_html;
                int size = BinaryData::index_htmlSize;
                std::vector<std::byte> bytes;
                bytes.reserve(size);
                for (int i = 0; i < size; ++i) bytes.push_back(static_cast<std::byte>(data[i]));
                return juce::WebBrowserComponent::Resource{ std::move(bytes), "text/html" };
            }
            return std::nullopt;
        })
       .withNativeIntegrationEnabled()
    };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicStudioAudioProcessorEditor)
};
