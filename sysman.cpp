#include <iostream>
#include <string>
int main() {
std::cout << "Welcome to sysman." << std::endl;
std::cout << "  _| | |_/ __\\ \\ / / __|  \\/  | /_\\ | \\| |" << std::endl;
std::cout << " |_  .  _\\__ \\\\ V /\\__ \\ |\\/| |/ _ \\| .` |" << std::endl;
std::cout << " |_     _|___/ |_| |___/_|  |_/_/ \\_\\_|\\_|" << std::endl;
std::cout << "   |_|_|   ~~1.2 by Zero" << std::endl;
std::cout << "RUN THIS SOFTWARE AS ROOT (NOT SUDO BUT SU)" << std::endl;
std::cout << "" << std::endl;
std::cout << "" << std::endl;
std::cout << "   [0] Set min fan speed" << std::endl;
std::cout << "   [1] Set screen brightness" << std::endl;
std::cout << "   [2] Set keyboard backlight brightness" << std::endl;
std::cout << "   [3] Turn on manual fan control and set speed" << std::endl;
std::cout << "   [4] Turn off manual fan control" << std::endl;
std::cout << "" << std::endl;
std::cout << "" << std::endl;
std::string fsp("/sys/devices/platform/applesmc.768/fan1_min");
std::string sbb("/sys/class/backlight/intel_backlight/brightness");
std::string kbb("/sys/class/leds/smc\\:\\:kbd_backlight/brightness");
std::string fms("/sys/devices/platform/applesmc.768/fan1_output");
int uservalue;
int userdevicevalue;
std::string command;
std::cin >> uservalue;
if (uservalue == 0) {
    std::cout << "Insert a value between 1299 and 6199, higher value might damage your device." <<std::endl;
    std::cin >> userdevicevalue;
    command = "echo " + std::to_string(userdevicevalue) + " > " + fsp;
    system(command.c_str());
} else if (uservalue == 1) {
    std::cout << "Insert a value between 0 (off) and 1388 (max)." << std::endl;
    std::cin >> userdevicevalue;
    command = "echo " + std::to_string(userdevicevalue) + " > " + sbb;
    system(command.c_str());
} else if (uservalue == 2) {
    std::cout << "Inser a value between 0 (off) and 255 (max)." << std::endl;
    std::cin >> userdevicevalue;
    command = "echo " + std::to_string(userdevicevalue) + " > " + kbb;
    system(command.c_str());
} 
else if (uservalue == 3) {
    std::cout << "Insert a value (recomended are 1299~6199)" << std::endl;
    std::cin >> userdevicevalue;
    system("echo 1 > /sys/devices/platform/applesmc.768/fan1_manual");
    command = "echo " + std::to_string(userdevicevalue) + " > " + fms;
    system(command.c_str());
} else if (uservalue == 4) {
    std::cout << "Turning off manual fan control..." << std::endl;
    system("echo 0 > /sys/devices/platform/applesmc.768/fan1_manual");
} else {
    std::cout << "Please select a valid option." << std::endl;
}
return 0;
}
