/*
Union
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;


// A union is a special type of object declaration.
// Unions allow us to treat data as different names or types.

// There are a couple of ways to use unions:
union XandY // This declares a union type XandY
{
    int x;  // this object type is both x and y.
    char y;  // x and y are both the same data, but don't need to be the same type!
};


int main() 
{
    {
        // Test union declared as a type.
        cout << "test union: " << endl;

        XandY thing;    // This kind of union is used similarly to a struct, but where each variable occupies the same data.
        thing.x = 75;    // Changing x, also changes y.

        cout << "thing.x = 75;" << endl;
        cout << "thing.y: " << thing.y << endl;

        // Unions are the same size as the largest object.
        cout << "sizeof(XandY): " << sizeof(XandY) << endl;
        cout << "sizeof(int): " << sizeof(int) << endl;
    }
    cin.get();


    {
        // Unions can also be declared as members without a type declaration:
        union
        {
            int x;
            int y;
        };

        x = 99; // In this situation, we don't create an object of the type, because there is no type.
                // It's just part of the scope it's defined in. (Can also be part of an object in this way).

        cout << "x = 99;" << endl;
        cout << "y: " << y << endl;
    }
    cin.get();


    {
        // A much more useful way to use unions, we can declare structs within unions:
        union
        {
            struct {
                float x;    // x, y, and z, can now be accessed as r, g, and b
                float y;
                float z;
            };
            struct {
                float r;
                float g;
                float b;
            };
        };

        // Let's test it out!
        r = g = b = 100;

        cout << "r = g = b = 100;" << endl;

        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
    }
    cin.get();




    return 0;   // End Program.
}