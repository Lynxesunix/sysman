#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]) {
string fsp("/sys/devices/platform/applesmc.768/fan1_min");
string sbb("/sys/class/backlight/intel_backlight/brightness");
string kbb("/sys/class/leds/smc\\:\\:kbd_backlight/brightness");
string fms("/sys/devices/platform/applesmc.768/fan1_output");
string command;
string option;
if (argc > 1) {
    option = argv[1];
} else {option == "empty";}
if (argc == 1) {
    bool live = true;
    while (live == true){
    cout << "Welcome to sysman." << endl;
    cout << "    _ _   _____   ________  __   _   _  _" << endl;
    cout << "  _| | |_/ __\\ \\ / / __|  \\/  | /_\\ | \\| |" << endl;
    cout << " |_  .  _\\__ \\\\ V /\\__ \\ |\\/| |/ _ \\| .` |" << endl;
    cout << " |_     _|___/ |_| |___/_|  |_/_/ \\_\\_|\\_|" << endl;
    cout << "   |_|_|   ~~1.3 by Zero" << endl;
    cout << "RUN THIS SOFTWARE AS ROOT (NOT SUDO BUT SU)" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "   [0] Set min fan speed" << endl;
    cout << "   [1] Set screen brightness" << endl;
    cout << "   [2] Set keyboard backlight brightness" << endl;
    cout << "   [3] Turn on manual fan control and set speed" << endl;
    cout << "   [4] Turn off manual fan control" << endl;
    cout << endl << endl;
    int uservalue;
    int userdevicevalue;
    cin >> uservalue;
    if (uservalue == 0) {
        cout << "Insert a value between 1299 and 6199, higher value might damage your device." << endl;
        cin >> userdevicevalue;
        command = "echo " + to_string(userdevicevalue) + " > " + fsp;
        system(command.c_str());
        live = false;
    } else if (uservalue == 1) {
        cout << "Insert a value between 0 (off) and 1388 (max)." << endl;
        cin >> userdevicevalue;
        command = "echo " + to_string(userdevicevalue) + " > " + sbb;
        system(command.c_str());
        live = false;
    } else if (uservalue == 2) {
        cout << "Inser a value between 0 (off) and 255 (max)." << endl;
        cin >> userdevicevalue;
        command = "echo " + to_string(userdevicevalue) + " > " + kbb;
        system(command.c_str());
        live = false;
    } 
    else if (uservalue == 3) {
        cout << "Insert a value (recomended are 1299~6199)" << endl;
        cin >> userdevicevalue;
        system("echo 1 > /sys/devices/platform/applesmc.768/fan1_manual");
        command = "echo " + to_string(userdevicevalue) + " > " + fms;
        system(command.c_str());
        live = false;
    } else if (uservalue == 4) {
        cout << "Turning off manual fan control..." << endl;
        system("echo 0 > /sys/devices/platform/applesmc.768/fan1_manual");
        live = false;
    } else {
        system("clear");
        cout << "Please select a valid option." << endl;
    }
    }
} else if (option == "4" || option == "-kmf" || option == "--stop-manual-fan" || option == "--kill-manual-fan") {
    cout << "Stopping manual fan control..." << endl;
    system("echo 0 > /sys/devices/platform/applesmc.768/fan1_manual");
    system(command.c_str());
} else if (argc == 3) {
    string optionvalue(argv[2]);
    if (option == "0" || option == "-mfs" || option == "--minimum-fan-speed"){
        cout << "Setting minimum fan speed at: " << optionvalue << " RPM" << endl;
        command = "echo " + optionvalue + " > " + fsp;
        system(command.c_str());
    } else if (option == "1" || option == "-ssb" || option == "--set-screen-brightness") {
        cout << "Setting screen brightness at: " << optionvalue << endl;
        command = "echo " + optionvalue + " > " + sbb;
        system(command.c_str());
    } else if (option == "2" || option == "-skb" || option == "--set-keyboard-backlight") {
        cout << "Setting keyboard backlight brightness at: " << optionvalue << endl;
        command = "echo " + optionvalue + " > " + kbb;
        system(command.c_str());
    } else if (option == "3" || "-smf" || "--set-manual-fan-speed") {
        cout << "Starting fan/s at: " << optionvalue << "RPM" << endl;
        system("echo 1 > /sys/devices/platform/applesmc.768/fan1_manual");
        command = "echo " + optionvalue + " > " + fms;
        system(command.c_str());
    } else {
        cout << "Syntax error, use -h or --help for help." << endl;
    }
} else if (option == "-h" || option == "--help") {
        cout << "Syntax error, displaying help." << endl;
        cout << "    _ _   _____   ________  __   _   _  _" << endl;
        cout << "  _| | |_/ __\\ \\ / / __|  \\/  | /_\\ | \\| |" << endl;
        cout << " |_  .  _\\__ \\\\ V /\\__ \\ |\\/| |/ _ \\| .` |" << endl;
        cout << " |_     _|___/ |_| |___/_|  |_/_/ \\_\\_|\\_|" << endl;
        cout << "   |_|_|   ~~1.3 by Zero" << endl;
        cout << "RUN THIS SOFTWARE AS ROOT (NOT SUDO BUT SU)" << endl;
        cout << endl << endl;
        cout << "Running sysman without argument will take you to the menu." << endl;
        cout << "To set minimum fan/s speed (Linux Auto Fan Mode) use: 0 or -mfs or --minimum-fan-speed" << endl;
        cout << "To set the screen brightness use: 1 or -ssb or --set-screen-brightness" << endl;
        cout << "To set the keyboard backlight brightness use: 2 or -skb or --set-keyboard-backlight" << endl;
        cout << "To start fan/s at a custom speed (Disabling Linux Auto Fan Mode and switching to Manual Mode) use: 3 or -smf or --set-manual-fan-speed" << endl;
        cout << "To stop the fan/s manual mode (And switch to Linux Auto Fan Mode) use: 4 or -kmf or --stop-manual-fan or --kill-manual-fan" << endl;
}else {
    cout << "Syntax error. Use -h or --help to show help." << endl;
}
return 0;
}
