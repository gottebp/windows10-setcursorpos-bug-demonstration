## Windows 10 SetCursorPos() Bug Demonstration 

## Purpose: 
Simple C/Winapi Console Application that demonstrates a cursor behavior anomaly present in Windows 10 build 16299 and later. In short, using SetCursorPos() seems to be failing to notify some underlying applications when the cursor is overhead.  

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
 
## Contact: 
Ben Gottemoller
bengottemoller [  AT  ] [g-m-a-i-l]

