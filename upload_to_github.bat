@echo off
echo === Music Studio VST - Auto Upload to GitHub ===
echo.
set /p USERNAME="Enter your GitHub username: "
set /p REPONAME="Enter repo name [music-studio-vst]: "
if "%REPONAME%"=="" set REPONAME=music-studio-vst

echo.
echo Initializing git...
git init
git add .
git branch -M main
echo.
echo Adding remote: https://github.com/%USERNAME%/%REPONAME%.git
git remote remove origin 2>nul
git remote add origin https://github.com/%USERNAME%/%REPONAME%.git

echo.
echo Committing...
git commit -m "initial VST3 wrapper with auto-build"

echo.
echo Pushing to GitHub...
git push -u origin main

echo.
echo === DONE! ===
echo Go to https://github.com/%USERNAME%/%REPONAME%/actions
echo Wait 8 min, then download your VST3 from Artifacts
pause
