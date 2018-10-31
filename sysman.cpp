#include <iostream>
#include <string>
using namespace std;
int main() {
cout << "Welcome to sysman." << endl;
cout << "    _ _   _____   ________  __   _   _  _" << endl;
cout << "  _| | |_/ __\\ \\ / / __|  \\/  | /_\\ | \\| |" << endl;
cout << " |_  .  _\\__ \\\\ V /\\__ \\ |\\/| |/ _ \\| .` |" << endl;
cout << " |_     _|___/ |_| |___/_|  |_/_/ \\_\\_|\\_|" << endl;
cout << "   |_|_|   ~~1.2 by Zero" << endl;
cout << "RUN THIS SOFTWARE AS ROOT (NOT SUDO BUT SU)" << endl;
cout << "" << endl;
cout << "" << endl;
cout << "   [0] Set min fan speed" << endl;
cout << "   [1] Set screen brightness" << endl;
cout << "   [2] Set keyboard backlight brightness" << endl;
cout << "   [3] Turn on manual fan control and set speed" << endl;
cout << "   [4] Turn off manual fan control" << endl;
cout << "" << endl;
cout << "" << endl;
string fsp("/sys/devices/platform/applesmc.768/fan1_min");
string sbb("/sys/class/backlight/intel_backlight/brightness");
string kbb("/sys/class/leds/smc\\:\\:kbd_backlight/brightness");
string fms("/sys/devices/platform/applesmc.768/fan1_output");
int uservalue;
int userdevicevalue;
string command;
cin >> uservalue;
if (uservalue == 0) {
    cout << "Insert a value between 1299 and 6199, higher value might damage your device." << endl;
    cin >> userdevicevalue;
    command = "echo " + to_string(userdevicevalue) + " > " + fsp;
    system(command.c_str());
} else if (uservalue == 1) {
    cout << "Insert a value between 0 (off) and 1388 (max)." << endl;
    cin >> userdevicevalue;
    command = "echo " + to_string(userdevicevalue) + " > " + sbb;
    system(command.c_str());
} else if (uservalue == 2) {
    cout << "Inser a value between 0 (off) and 255 (max)." << endl;
    cin >> userdevicevalue;
    command = "echo " + to_string(userdevicevalue) + " > " + kbb;
    system(command.c_str());
} 
else if (uservalue == 3) {
    cout << "Insert a value (recomended are 1299~6199)" << endl;
    cin >> userdevicevalue;
    system("echo 1 > /sys/devices/platform/applesmc.768/fan1_manual");
    command = "echo " + to_string(userdevicevalue) + " > " + fms;
    system(command.c_str());
} else if (uservalue == 4) {
    cout << "Turning off manual fan control..." << endl;
    system("echo 0 > /sys/devices/platform/applesmc.768/fan1_manual");
} else {
    cout << "Please select a valid option." << endl;
}
return 0;
}
