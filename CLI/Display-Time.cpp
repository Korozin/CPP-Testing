#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <thread>

using namespace std;

int main() {
    while(true) {
        // Get the current time
        time_t now = time(0);
        tm* ltm = localtime(&now);
        
        // Convert to 12-hour format with AM/PM
        int hour = ltm->tm_hour;
        string meridian = "AM";
        if(hour >= 12) {
            meridian = "PM";
            hour -= 12;
        }
        if(hour == 0) {
            hour = 12;
        }
        
        // Display the time with leading zeros
        cout << setfill('0') << setw(2) << hour << ":" 
             << setw(2) << ltm->tm_min << ":" 
             << setw(2) << ltm->tm_sec << " " << meridian << "\r";
        cout.flush();
        
        // Wait for one second
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
