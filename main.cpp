#include <iostream>
#include "navigator/navigator_ui.h"
#include "compress/compress.h"
#include "extract/extract.h"

using namespace ui::navigator;

int main() {
    while (true) {
        std::cout << "fuckme" << std::endl;
        ui::navigator::clear();
        ui::navigator::welcome();
        ui::navigator::dispmenu();
        int choice;
        do {
            choice = getchar() - '0';
            if (choice < 0 || choice > 3) {
                break;
            }
        } while (true);
        switch (choice) {
            default:
                std::cerr << "unknown choice" << std::endl;
                exit(EXIT_FAILURE);
            case 3:
                exit(EXIT_SUCCESS);
            case 1:
                compress_mode();
                break;
            case 2:
                extract_mode();
                break;
        }
    }
}