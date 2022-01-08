#ifndef CONTROLV3_MYREALIZATION_H
#define CONTROLV3_MYREALIZATION_H

#include <string>

namespace MyFun {
    class MyRealization {
    public:
        static void trim(std::string &src) {
            src.erase(std::find_if_not(src.rbegin(), src.rend(), ::isspace).base(), src.end());
            src.erase(src.begin(), std::find_if_not(src.begin(), src.end(), ::isspace));
        }

    };
}

#endif //CONTROLV3_MYREALIZATION_H
