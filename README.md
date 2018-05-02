## Windows 10 SetCursorPos() Bug Demonstration 

## Purpose: 
Simple C/C++ Winapi Console application that demonstrates a cursor behavior anomaly present in Windows 10 build 16299 and later. 
The program reads the arrow keys to update a "cursor position" and then feeds this into SetCursorPos(). In short: The keyboard arrow keys can be used to move the cursor. This allows easy testing of interaction of UI elements beneath the cursor as SetCursorPos() moves it about. You will quickly find that some UI elements fail to "notice" when the cursor is overheard.
  
NOTE: Running the sample application with administrative rights makes no difference, so I do not believe this to be security or privileges related.

## Bug Summary: 
When the cursor is moved about programmatically using [SetCursorPos()](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648394%28v=vs.85%29.aspx) some applications are failing to react when the cursor is overhead. It seems like it could be a failure to send WM_MOUSEMOVE. 
  
The behaviour is recent and did **not** occur in Windows 10 build 15063 and prior.

## Video demonstration of the bug (~2 minutes):
https://youtu.be/zEXPD18zE1s  
Note: It may be necessary to set the video quality to 1080p to read the text properly. 

## Bug submitted to microsoft here:
https://developer.microsoft.com/en-us/microsoft-edge/platform/issues/17124228/

## Example applications where SetCursorPos() exhibits this behavior:
1. Simple cursor motion above start menu items: The tiles and icons fail to light up, or only do so with a long delay.
2. Click + Drag of a card in Spider Solitaire
3. Click + Drag to highlight text in the Edge Browser

## Tested Windows Versions: 
* Bug NOT present: Windows 10 build 15063
* Bug first present: Windows 10 build 16299
* Bug still present: Windows 10 build 17133
* Bug still present: Windows 10 build 17134 (May 2nd, 2018)
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

