## Windows 10 SetCursorPos() Bug Demonstration 

## Purpose: 
Simple C/C++ Winapi Console application that demonstrates a cursor behavior anomaly present in Windows 10 build 16299 and later. 

## Bug Summary: 
When the cursor is moved about programmatically using [SetCursorPos()](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648394%28v=vs.85%29.aspx) some applications are failing to react when the cursor is overhead. It seems like it could be a failure to send WM_MOUSEMOVE. 
  
The behaviour is recent and did not occur prior to Windows 10 build 15063

## Video demonstration of the bug:
https://youtu.be/zEXPD18zE1s  

## Example applications where SetCursorPos() exhibits this behavior:
1. Simple cursor motion above start menu items: The tiles and icons fail to light up, or only do so with a long delay.
2. Click + Drag of a card in Spider Solitaire
3. Click + Drag to highlight text in the Edge Browser

## Tested Windows Versions: 
* Bug NOT present: Windows 10 build 15063
* Bug first present: Windows 10 build 16299
* Bug still present: Windows 10 build 17133
* Bug still present: Windows 10 build 17134
* Bug NOT present: Windows 7 
* Bug NOT present: Windows 8.1 
 
## Steps to replicate:
* Download this repo
* Compile with Visual Studio 2017 (Target: Release - x86)
* Run the executable and press enter to begin
* Move the cursor using your arrow keys (You can still click with the regular mouse when needed).
* Open the start menu and proceed to move the cursor via the arrows and note the lack of reaction from underlying items.
 
## Contact:  
Ben Gottemoller  
ben DOT gottemoller [  AT  ] [g-m-a-i-l]  

