#ifndef MASHPARAM_MAIN_H
#define  MASHPARAM_MAIN_H

#include <iostream>

inline void longline(void) { 
    std::cout<< "_________________________\n\n";
}

inline void longline(const int i) { 
    std::cout<< "\n " << i << ". __________________\n\n"; 
}

inline void longline(const char ch[]) { 
    std::cout<< "\n<" << ch << ">__________________\n\n"; 
}


#endif  // MASHPARAM_MAIN_H