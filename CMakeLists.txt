cmake_minimum_required(VERSION 3.22)
project(MusicStudioVST VERSION 1.0.0)

# JUCE - will be fetched if not found
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.4
)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(MusicStudioVST
    COMPANY_NAME "Music Studio"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT TRUE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE MsSt
    PLUGIN_CODE MuSt
    FORMATS VST3 Standalone
    PRODUCT_NAME "Music Studio"
    VST3_CATEGORIES Instrument Synth
)

juce_generate_juce_header(MusicStudioVST)

target_sources(MusicStudioVST PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_definitions(MusicStudioVST PUBLIC
    JUCE_WEB_BROWSER=1
    JUCE_USE_WIN_WEBVIEW2_WITH_STATIC_LINKING=1
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(MusicStudioVST PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_browser
)

# Embed HTML as binary resource
juce_add_binary_data(PluginResources SOURCES Resources/index.html)

# For Windows, need WebView2 loader
if(WIN32)
    target_link_libraries(MusicStudioVST PRIVATE juce::juce_browser)
endif()
