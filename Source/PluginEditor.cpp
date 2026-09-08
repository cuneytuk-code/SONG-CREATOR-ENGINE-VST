#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    setResizable(true, true);
    
    juce::WebBrowserComponent::Options options;
    options.withBackend(juce::WebBrowserComponent::Options::Backend::webview2);
    options.withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}.withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory)));
    
    options.withResourceProvider([](const juce::String& url) -> std::optional<juce::WebBrowserComponent::Resource> {
        if (url == "/" || url.contains("index.html")) {
            auto* data = BinaryData::index_html;
            int dataSize = BinaryData::index_htmlSize;
            std::vector<std::byte> content;
            content.reserve(dataSize);
            for (int i = 0; i < dataSize; ++i) content.push_back(static_cast<std::byte>(data[i]));
            return juce::WebBrowserComponent::Resource{ std::move(content), "text/html" };
        }
        return std::nullopt;
    });
    
    options.withNativeIntegrationEnabled();
    
    webView = std::make_unique<juce::WebBrowserComponent>(options);
    addAndMakeVisible(*webView);
    webView->goToURL(webView->getResourceProviderRoot());
}

MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}

void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void MusicStudioAudioProcessorEditor::resized()
{
    if (webView) webView->setBounds(getLocalBounds());
}
