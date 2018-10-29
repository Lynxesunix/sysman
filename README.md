# SysMan
SysMan is a C++ simple tool that allow MacBook (designed for Early 2015 MacBook Pro, should work on other devices) owner have a bit more control on the device.

# Features
[0] Set min fan speed (set minimum fan speed, useful is Linux is by default turning on fan but your Mac is too hot anyway).
[1] Set screen brightness (if your Linux distro does not have a shortcut key to manage screen brightness, this will be useful).
[2] Set keyboard backlight brightness (again, if your Linux distro does not have a shortcut for that, working in a dark room won't be a problem anymore!).
[3] Turn on manual fan control and set speed (literally what it says, WARNING: setting a too slow RPM value when the CPU get hot will damage your device, use this options carefully)
[4] Turn off manual fan control (turn off manual fan control, Linux will control fan by itself after this option has been selected.)

# Future Updates
SysMan will be able to take arguments in the future.

Just to let you know, this program does not use any other lib/dependency, however, because it is modifying /sys files, it have to be ran as root (using su, sudo won't work).
