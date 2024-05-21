#include <iostream>
#include <windows.h>  // Include the Windows header for Sleep

int main() {
    std::cout << "Sleeping for 2 seconds..." << std::endl;
    Sleep(2000);  // Sleep for 2000 milliseconds (2 seconds)
    std::cout << "Awake now!" << std::endl;
    return 0;
}
