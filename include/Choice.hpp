#ifndef CHOICE_HPP
#define CHOICE_HPP

using namespace std;
#include <string>

class Choice {
    public:
        Choice(): text(""), resultScene("") {}
        Choice(string t, string s): text(t), resultScene(s) {}
        string text; 
        string resultScene;
};

#endif