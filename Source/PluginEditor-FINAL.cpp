#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p),
      webView(juce::WebBrowserComponent::Options{}
        .withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
        .withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}
            .withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory)))
        .withResourceProvider([](const juce::String& url) -> std::optional<juce::WebBrowserComponent::Resource>
        {
            if (url == "/" || url == "/index.html" || url.contains("index.html") || url == "https://juce.backend/")
            {
                auto* data = BinaryData::index_html;
                auto size = BinaryData::index_htmlSize;
                std::vector<std::byte> bytes;
                bytes.reserve(size);
                for (size_t i = 0; i < size; ++i) bytes.push_back(static_cast<std::byte>(data[i]));
                return juce::WebBrowserComponent::Resource{ std::move(bytes), juce::String("text/html") };
            }
            return std::nullopt;
        })
      )
{
    setSize(1400, 900);
    setResizable(true, true);
    addAndMakeVisible(webView);
    webView.goToURL(webView.getResourceProviderRoot());
}

MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
