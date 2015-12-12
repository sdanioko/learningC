#include <iostream>

// In C++ structs have a typedef defined automatically
struct VEC3 {
    long double x;
    long double y;
    long double z;
};

struct VEC2 {
    long double x;
    long double y;
};

// Function overloading allows the same name to be used for different types
void printVec(VEC3 v);
void printVec(VEC2 &wp);

VEC3 modifyVec3(VEC3 v, long double x, long double y, long double z);
void setVec(VEC2 &wp, long double x, long double y);

using namespace std;

int main(void)
{
    // The default constructor for a struct just zeroes the values
    VEC3 v = VEC3();
    VEC3 vprime = VEC3();
    VEC2 w = VEC2();
    
    cout << "-----Pass by value test-----" << endl;
    cout << "Original 3 vector:" << endl;
    printVec(v);
    vprime = modifyVec3(v, 1.0, 2.0, 3.0);
    cout << "Original 3 vector after modification:" << endl;
    printVec(v);
    cout << "New 3 vector after modification:" << endl;
    printVec(vprime);
    
    cout << "-----Pass by reference test-----" << endl;
    cout << "Original 2 vector:" << endl;
    printVec(w);
    setVec(w, 1.0, 2.0);
    cout << "Original 2 vector after modification:" << endl;
    printVec(w);

    return 0;
}

void printVec(VEC3 v)
{
    cout << "3Vector : [" << v.x << ", " << v.y << ", " << v.z << "]" << endl;
}

VEC3 modifyVec3(VEC3 v, long double x, long double y, long double z)
{
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void setVec(VEC2 &wr, long double x, long double y)
{
    // Local reference wr refers directly to original memory location
    wr.x = x;
    wr.y = y;
}

void printVec(VEC2 &wr)
{
    // Passing in a reference wr prevents unnecessary memory copying
    cout << "2Vector : [" << wr.x << ", " << wr.y << "]" << endl;
}
