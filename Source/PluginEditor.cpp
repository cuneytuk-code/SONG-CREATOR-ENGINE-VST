#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p), webView(juce::WebBrowserComponent::Options{}.withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
        .withWinWebView2Options(juce::WebBrowserComponent::Options::WinWebView2{}.withUserDataFolder(juce::File::getSpecialLocation(juce::File::tempDirectory)))
        .withResourceProvider([](const juce::String& url) -> std::optional<juce::WebBrowserComponent::Resource> {
            if (url == "/" || url == "/index.html") {
                auto data = BinaryData::getNamedResource(BinaryData::namedResourceList[0], BinaryData::namedResourceListSize[0]);
                // Actually get index.html
                for (int i=0;i<BinaryData::namedResourceListSize;++i){
                    juce::String name(BinaryData::namedResourceList[i]);
                    if (name.contains("index")){
                        int size=0;
                        auto res = BinaryData::getNamedResource(BinaryData::namedResourceList[i], size);
                        juce::String html = juce::String::fromUTF8((const char*)res, size);
                        std::vector<std::byte> bytes;
                        bytes.reserve(html.getNumBytesAsUTF8());
                        for (auto c: html.toRawUTF8()) bytes.push_back((std::byte)c);
                        // Simpler: return string resource via lambda that loads file
                        // JUCE expects vector<byte> for content
                        std::vector<std::byte> content;
                        auto* src = res;
                        for(int j=0;j<size;++j) content.push_back((std::byte)src[j]);
                        return juce::WebBrowserComponent::Resource{ std::move(content), "text/html" };
                    }
                }
                return std::nullopt;
            }
            return std::nullopt;
        })
        .withNativeIntegrationEnabled())
{
    setSize(1400, 900);
    setResizable(true, true);
    addAndMakeVisible(webView);
    webView.goToURL(webView.getResourceProviderRoot());
}
MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
