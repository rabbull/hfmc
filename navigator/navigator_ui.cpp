//
// Created by karl on 11/27/18.
//

#include <iostream>
#include "navigator_ui.h"

void ui::navigator::clear() {
//    system("reset");
}

void ui::navigator::welcome() {
    std::cout << "= = = huffman-tree = = =" << std::endl;
}

void ui::navigator::dispmenu() {
    std::cout << "1. compress file" << std::endl
              << "2. extract file" << std::endl
              << "3. exit" << std::endl;
    std::cout << "please select an option: ";
}
