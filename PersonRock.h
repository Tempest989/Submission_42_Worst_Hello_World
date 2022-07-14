#ifndef PERSONROCK
#define PERSONROCK

#include <string>
using namespace std;

class PersonRock
{
    public:
    PersonRock();
    virtual void set_choice();
    string get_choice();
    string get_name();
    virtual void set_name(string);
    string get_type();

    protected:
    string choice;
    string name;
};
#endif
