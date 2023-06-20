#include "common.h"
std::vector<std::string> split(const std::string &s, char &&delim) {
    std::vector<std::string> ret;
    if (!s.empty())
        split_internal(s, delim, std::back_inserter(ret));
    return ret;
}