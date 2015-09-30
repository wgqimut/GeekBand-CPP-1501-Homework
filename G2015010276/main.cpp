#include <iostream>
#include "Rectange.h"

using namespace std;

int main()
{
	Rectangle newRec(2, 3, 4, 4);
	cout << newRec << endl;

	Rectangle newRec2(newRec);
    cout << newRec2 << endl;

    Rectangle newRec3(3, 4, 1, 1);
    cout << newRec3 << endl;
    newRec3 = newRec2;
    cout << newRec3 << endl;
	
	return 0;
}