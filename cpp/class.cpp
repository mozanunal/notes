

#include <iostream>

using namespace std;

class animal
{

    int val = 20;

private:
    int positions;
    string name;
    void step()
    {
        this->positions += 1;
        cout << this->name << " step.. pos: " << this->positions << endl;
    }

public:
    animal(string name)
    {
        this->name = name;
        this->positions = 0;
    }
    int pos()
    {
        return this->positions;
    }
    void set_pos(int pos)
    {
        if (pos < 7)
        {
            positions = pos;
        }
        else
        {
            cout << "pos can not be set, you are cheating" << endl;
        }
    }
    void walk(int step_count)
    {
        for (int i = 0; i < step_count; i++)
        {
            this->step();
        }
    }
};

int main()
{

    animal ayi = animal("ayi");
    animal kaplan = animal("kaplan");

    ayi.walk(1);
    kaplan.walk(3);
    ayi.walk(2);

    cout << "ayi pos: " << ayi.pos() << endl;
    ayi.set_pos(10);
    cout << "ayi pos: " << ayi.pos() << endl;
    ayi.set_pos(5);
    cout << "ayi pos: " << ayi.pos() << endl;
    cout << "done" << endl;

    return 0;
}
