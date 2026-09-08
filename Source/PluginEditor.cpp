#include "PluginEditor.h"
#include "BinaryData.h"

MusicStudioAudioProcessorEditor::MusicStudioAudioProcessorEditor(MusicStudioAudioProcessor& p)
    : AudioProcessorEditor(&p)
{
    setSize(1400, 900);
    setResizable(true, true);
    addAndMakeVisible(webView);

    juce::String htmlContent;
    int foundSize = 0;

    // Try to find index.html in BinaryData with any name
    for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
    {
        auto name = juce::String(BinaryData::namedResourceList[i]);
        auto original = juce::String(BinaryData::originalFileNames[i]);
        if (name.containsIgnoreCase("index") || original.containsIgnoreCase("index.html"))
        {
            int size = 0;
            const char* data = BinaryData::getNamedResource(BinaryData::namedResourceList[i], size);
            if (data != nullptr && size > 100)
            {
                htmlContent = juce::String(data, size);
                foundSize = size;
                break;
            }
        }
    }

    // Fallback: try direct symbols
    if (htmlContent.isEmpty() && BinaryData::namedResourceListSize > 0)
    {
        for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
        {
            int size = 0;
            const char* data = BinaryData::getNamedResource(BinaryData::namedResourceList[i], size);
            if (size > 50000) // index.html is ~161KB, so take biggest file
            {
                htmlContent = juce::String(data, size);
                foundSize = size;
                break;
            }
        }
    }

    if (htmlContent.isNotEmpty())
    {
        auto base64 = juce::Base64::toBase64(htmlContent.toRawUTF8(), (int)htmlContent.getNumBytesAsUTF8());
        webView.goToURL("data:text/html;base64," + base64);
    }
    else
    {
        // DEBUG: show what is actually in BinaryData
        juce::String debug = "<html><body style='background:#0d061f;color:white;font-family:monospace;padding:20px;'>";
        debug += "<h2>DEBUG: BinaryData not found - Listing resources:</h2>";
        debug += "<p>namedResourceListSize = " + juce::String(BinaryData::namedResourceListSize) + "</p><ul>";
        for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
        {
            int sz = 0;
            BinaryData::getNamedResource(BinaryData::namedResourceList[i], sz);
            debug += "<li>" + juce::String(BinaryData::namedResourceList[i]) + " (" + juce::String(BinaryData::originalFileNames[i]) + ") size=" + juce::String(sz) + "</li>";
        }
        debug += "</ul><p>Please screenshot this and send to developer!</p></body></html>";
        auto base64 = juce::Base64::toBase64(debug.toRawUTF8(), (int)debug.getNumBytesAsUTF8());
        webView.goToURL("data:text/html;base64," + base64);
    }
}

MusicStudioAudioProcessorEditor::~MusicStudioAudioProcessorEditor() {}
void MusicStudioAudioProcessorEditor::paint(juce::Graphics& g){ g.fillAll(juce::Colours::black); }
void MusicStudioAudioProcessorEditor::resized(){ webView.setBounds(getLocalBounds()); }
