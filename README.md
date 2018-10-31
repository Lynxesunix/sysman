# SysMan
SysMan is a C++ simple tool that allow MacBook (designed for Early 2015 MacBook Pro, should work on other devices) owner have a bit more control on the device.

# Features
[0] Set min fan speed (set minimum fan speed, useful is Linux is by default turning on fan but your Mac is too hot anyway).
[1] Set screen brightness (if your Linux distro does not have a shortcut key to manage screen brightness, this will be useful).
[2] Set keyboard backlight brightness (again, if your Linux distro does not have a shortcut for that, working in a dark room won't be a problem anymore!).
[3] Turn on manual fan control and set speed (literally what it says, WARNING: setting a too slow RPM value when the CPU get hot will damage your device, use this options carefully)
[4] Turn off manual fan control (turn off manual fan control, Linux will control fan by itself after this option has been selected.)
Arguments are now supported.

# Notes
~~sysman is the compiled C++ program (Compiled on a MacBook Pro 13" early 2015).~~ (Now only available under "releases")
sysman.cpp is the source code, you can modify it to match your device (even devices different than Mac) or compile ti for you platform.

To make things easier I suggest to link or move the file to an easy access directory or in /bin, /sbin, /usr/bin and so on.

# Other Devices
sysman can work on other devices, however, because I don't own other systems at the moment, I can't test and find the directory to use in order to control fan (if available), screen brightness and keyboard backlight brightness (if available), or eventually other devices.
If you would like to help making sysman available for more systems and devices, feel free to edit the source code, and make a new version for that device.
