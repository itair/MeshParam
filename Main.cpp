/*-----------------------------------------
//   Param Test 
//   by itAir
//   Try to build a framework  
//                 2014.1
----------------------------------------- */ 
#include "Main.h"
#include "Mesh.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>


//bool IsFileName(std::string str);

void main(void)
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    
    cout << "|_______________________________________\n"
         << "|   Param Test \n" 
         << "|   by itAir   \n"
         << "|   Try to build a framework \n"  
         << "|________________________________________\n ";
    cout << endl << endl;

    // use on
    clock_t tbegin = clock();
    Mesh ma;
    ma.ReadData();

    
    




    clock_t tend = clock();
    longline("End");
    cout << "Ran for " << tend - tbegin << " ms.\n" << endl;
    system("pause");
    return ;
}
// 
// bool IsFileName(std::string str) {
//     int len = str.length();
//     std::string name, ext;
//     int pointpos = str.find('.');
//     name.copy(str.begin(), str.at(pointpos));
//     ext.copy(str.at(pointpos), str.end());
// 
//     if (ext.find('.') ) return false;
// 
//     for (char ch : ext) {
//         if (!isalnum(ch)) {
//             break;
//             return false;
//         }
//     }
// 
//     for (char ch : name) {
//         if (!isalnum(ch) && ch != '_' && ch != '(' && ch != ')' ) {
//             break;              
//             return false;
//         }
//     }
//     return true;
// }