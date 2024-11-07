#ifndef CHOICE_HPP
#define CHOICE_HPP

using namespace std;
#include <string>

class Choice {
    public:
        Choice(): text(""), resultScene(-1){}
        Choice(string t, int i): text(t), resultScene(i) {}
        string text; 
        int resultScene;
};

#endif