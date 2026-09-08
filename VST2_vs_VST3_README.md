# VST2 vs VST3 - The Real Story

## VST3 (RECOMMENDED - Works in ALL modern DAWs)
- FL Studio ✅ (20.8+)
- Reaper ✅
- Ableton Live ✅ (11+)
- Bitwig ✅
- Maschine ✅ (2.14+)
- Cubase ✅
- Studio One ✅

Steinberg provides VST3 SDK free. Build with JUCE 8 as above.

## VST2 (Legacy - Extra Headache)
Steinberg STOPPED issuing VST2 licenses in Oct 2018. Legally you cannot distribute VST2 unless you had license before 2018.

If you DO have old license:
1. Download VST2 SDK (vst2.x)
2. In CMakeLists.txt change:
   FORMATS VST3 VST2
   And add:
   juce_set_vst2_sdk_path(...)

If you DON'T have license:
Option A - Use VeSTige (open-source VST2 header) - legally grey, works in FL/Reaper
Option B - Just ship VST3 - all DAWs you listed support VST3 now, VST2 not needed
Option C - Use JUCE 6 (last version with VST2 support)

RECOMMENDATION: Ship ONLY VST3. You're covered for every DAW you listed. VST2 adds legal + build headaches for zero extra users in 2026.

If you MUST have VST2, use this fork:
https://github.com/juce-framework/JUCE/tree/juce6
and build with VST2 SDK path.
