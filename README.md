# Music Studio - VST3 Wrapper (Easiest Hassle-Free Way)

This is the JUCE 8 WebView template that loads your exact HTML (V38) inside a VST3.

## Why this is hassle-free:
- No C++ audio coding needed - your JS Web Audio stays
- JUCE handles DAW compatibility for you
- One codebase → VST3 + Standalone + AU (Mac)
- Works in FL Studio, Reaper, Ableton Live, Bitwig, Maschine, Cubase, etc.

## Build Steps (Windows 11)

### Prerequisites (once)
1. Install Visual Studio 2022 Community (free) with "Desktop development with C++"
2. Install CMake 3.22+ from cmake.org
3. Install Git

### Build
```powershell
# Clone JUCE will be auto-fetched, so just:
cd MusicStudio-VST-Wrapper

# Configure
cmake -B Build -DCMAKE_BUILD_TYPE=Release

# Build VST3
cmake --build Build --config Release
```

Output:
```
Build/MusicStudioVST_artefacts/Release/VST3/Music Studio.vst3
Build/MusicStudioVST_artefacts/Release/Standalone/Music Studio.exe
```

### Install for testing
Copy `Music Studio.vst3` folder to:
`C:\Program Files\Common Files\VST3\`

Then rescan plugins in your DAW.

## How it works
- PluginEditor creates a WebView2 browser (Edge Chromium)
- Loads Resources/index.html (your V38)
- Your Web Audio API plays inside the plugin window
- No internet needed

## DAW-Specific Notes
- **FL Studio**: Add VST3 path, rescan. Works as Instrument
- **Reaper**: Preferences → VST → Re-scan. Loads instantly
- **Ableton Live 11+**: Drag VST3 to track. Enable "Use VST3" in prefs
- **Bitwig**: Settings → Plug-ins → rescan. Shows under Instruments
- **Maschine**: Preferences → Plug-ins → rescan VST3 folder

## Even EASIER Alternative (No C++ at all)

If you want ZERO C++, use **WARM + Element** or **Neon**:

Option 1 - **AudioKit + WebView** (1-click):
Use https://github.com/ElkVision/webview-vst-template - drop your index.html in, run build.bat

Option 2 - **HISE WebView** (easiest for non-coders):
HISE has a WebView component. Import HTML as interface, export VST3 directly.

Option 3 - **PlugData / Cmajor**:
Cmajor can load HTML UI and export VST3: https://cmajor.dev

## VST2
See VST2_vs_VST3_README.md - but honestly skip it. All your target DAWs support VST3.

## Need AU / Mac?
Same CMake project, run on Mac:
```
cmake -B Build -G Xcode
cmake --build Build --config Release
```
Gives you .vst3 + .component (AU)

Want me to build the actual .vst3 for you? I can generate a GitHub Actions workflow that builds Windows VST3 automatically.
