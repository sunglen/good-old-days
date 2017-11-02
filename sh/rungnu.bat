@echo off
:: CAUTION: run this script (rungnu.bat) ONCE at a time!!
:: if you want to open another terminal, i.e. another RXVT session,
:: please open the new terminal through the current shell, other
:: than this script.

echo ---CAUTION:---
echo run this script (rungnu.bat) ONCE at a time!!
echo if you want to open another terminal, i.e. another RXVT session,
echo please open the new terminal through the current shell, other 
echo than this script.
echo --------------

:: set software version
set WINAVR_VER=20081205
set EMACS_VER=22.3

:: determine the current drive, and set parameter "WD" to it.
for /F %%A in ('cd') do set WD=%%A

:: record the existed Cygwin mount point.
rem cygwin\bin\mount -m | cygwin\bin\sed s/mount/"%WD%\/cygwin\\/bin\\/mount"/ > cygwin\tmp\mount.log

cygwin\bin\mount -m | cygwin\bin\sed s/mount/"%WD%/cygwin\/bin\/mount"/ > cygwin\tmp\mount.log

:: umount the existed Cygwin.
rem cygwin\bin\umount -c
cygwin\bin\umount -A

:: mount Cygwin which is on the current drive.
cygwin\bin\mount -bfu %WD%cygwin/ /
cygwin\bin\mount -bfu %WD%cygwin\bin /usr/bin
cygwin\bin\mount -bfu %WD%cygwin\lib /usr/lib

:: useless
rem set path=%path%;%WD%cygwin\bin;%WD%cygwin\usr\X11R6\bin

:: set environment variables for WinAVR toolset
set PORTABLEWINAVR=%WD%WinAVR-%WINAVR_VER%
set PATH=%PORTABLEWINAVR%\bin;%PORTABLEWINAVR%\utils\bin;%PATH%

:: set environment variables for Emacs
set PORTABLEEMACS=%WD%emacs-%EMACS_VER%-bin-i386\emacs-%EMACS_VER%
set PATH=%PORTABLEEMACS%\bin;%PATH%

:: set environment variables for OpenOCD
set PORTABLEOPENOCD=%WD%openocd-r717
set PATH=%PORTABLEOPENOCD%\bin;%PATH%

:: set environment variables for yet-another-gnu-arm-toolschain
set PORTABLEARM=%WD%yagarto
set PATH=%PORTABLEARM%\bin;%PATH%

rem start cygwin\bin\rxvt.exe -title "" -bg "#fafad2" -fg "#000040" -color10 green4 -color14 brown -fn "Lucida Console-14" -geometry 80x58+0+0 -sl 4000 -sr -tn rxvt -e /bin/bash --login -i

echo ---CAUTION:---
echo DO NOT CLOSE THIS DOS BOX UNTIL IT NORMALLY EXIT!!
echo --------------

:: if X11 exist, start X.
rem set DISPLAY=localhost:0.0
rem run cygwin\usr\X11R6\bin\XWin -multiwindow -emulate3buttons 200

:: run rxvt without closing the dos box.
cygwin\bin\rxvt.exe -title "" -bg "#fafad2" -fg "#000040" -color10 green4 -color14 brown -fn "Lucida Console-14" -geometry 80x50+0+0 -sl 4000 -sr -tn rxvt -e /bin/bash --login -i

:: the following commands ensure the safe and clean exit of the portable Cygwin.

:: umount current Cygwin
rem cygwin\bin\umount -c
cygwin\bin\umount -A

:: restore the old Cygwin mount points, if it have.
cygwin\bin\bash  cygwin\tmp\mount.log
cygwin\bin\rm    cygwin\tmp\mount.log
