# Music Studio VST3 - Auto Build

This repo auto-builds your VST3 for FL Studio, Reaper, Ableton Live, Bitwig, Maschine.

## How to get your VST3 without installing anything:

1. **Create GitHub repo**: Go to github.com/new → Create repo named `music-studio-vst`
2. **Upload this zip**: On repo page → Add file → Upload files → Drag all files from this zip
3. **Wait 5-10 min**: Go to Actions tab → Click latest run → Download artifact `Music-Studio-VST3-Windows`
4. **Install**: Unzip artifact → Copy `Music Studio.vst3` folder to `C:\Program Files\Common Files\VST3\`
5. **Rescan** in your DAW

No Visual Studio needed - GitHub builds it for you!

## Local build (optional)
```
cmake -B Build -DCMAKE_BUILD_TYPE=Release
cmake --build Build --config Release
```
